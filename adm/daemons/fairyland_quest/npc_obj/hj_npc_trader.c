//                标准描述长度示例                                   |
// 幻境新添 NPC，支持玩家之间进行交易的指令
// by naihe  2003-11-04  于茂名
// naihe 05-9-1 16:04 debug, 购买时居然不给钱给委托者，烦躁

#include <ansi.h>
#include <errs_func.h>
// 里面有个 errs() 代替 notify_fail() ，即 write(msg), return 1;

inherit NPC;

#include "hj_settings/room_amount_hj.h"
#define     MY_ROOM_MARK        HJ_ROOM_AMOUNT
// 此NPC仅出现在 HJ 密林东南方角落处才有效
#include "zj_lm_tarder_prefunc.h"



#define        MAX_DS_AMOUNT        50
        // 最大同时 代售 数量
#define        MAX_DS_AMOUNT_ME     10
        // 最大个人同时代售数量
#define        SXF                  1
        // 手续费喽

object *get_goods_list( object who );
void new_goods_in( string id );


void create()
{
    set_name( "代售商", ({ "daishou shang", "shang" }) );
    set("nickname", HIY"童叟皆欺 绝不公平"NOR );

    set("long", "这是一个专做代售生意的商人，幻境里勇士们之间的交易都是到这里来进行的。

代售货品：    "HIY"(daishou 货品ID #价格)"NOR"
取回货品：    "HIY"(quhui ID)"NOR"
查看货品列表："HIY"(list)"NOR"
查看求购信息："HIY"(list qg)"NOR"
发布求购信息："HIY"(qiugou ID)"NOR"
购买货品：    "HIY"(goumai ID)"NOR"

代售货品、发布求购信息都需要"HIR"手续费 "+SXF+" 点"NOR"（以你的幻境得分兑现）。
代售货品时，如果原物主已离开幻境或已死亡，将会取消代售，货品将扔在本地。
发布求购信息后，将于半小时后清除；或在此期间若有该ID的新货到来，将在通知后清除。\n\n");

    set("gender","男性");
    set("age",45);
    set("per",16);
    set("attitude","friendly");
    set("no_refresh",1);
    set("hj_game/npc","trader");

    setup();

    remove_call_out("checking");
    call_out("checking", 1);  // 检查货品有效性

    remove_call_out("me_do_ads");
    call_out("me_do_ads", 1 ); // 发布广告什么的
}

void init()
{
    add_action("do_daishou", "daishou");
    add_action("do_goumai", "goumai");
    add_action("do_quhui", "quhui");
    add_action("do_list", "list");
    add_action("do_qiugou", "qiugou");
}

// 这个文件里许多描述都不用  message() ，是不想对其他人造成太多的骚扰



// 获得有效的货品列表
// 无效的，当即处理
object *get_goods_list( object who )
{
    object *temp, *ok_goods, *bad_goods, t, me, env;
    int i;

    temp = all_inventory(this_object());
    if( !temp || sizeof( temp ) < 1 )
        return 0;

    if( !who ) who = this_object();

    ok_goods = ({ });
    bad_goods = ({ });

    for( i=0;i<sizeof(temp);i++)
    {
        t = temp[i];
        // 非hj内物件，立刻删除
        if( !t ->query("hj_game/obj") )
        {
            destruct( t );
            continue;
        }

        // 发生意外的 hj 内物件，准备丢下
        if( !t->query("sell_value") || !t->query("seller_mark") || !t->query("sell_id"))
        {
            bad_goods += ({ t });
            continue;
        }

        // 售卖者已离开 hj (退出、死亡)，准备丢下
        // 这是为了避免有人拣了别人的宝物，又故意放到这里卖高价
        // 这时候，被拣了宝物的人可以选择PK该人，即可得回宝物！哈哈哈
        me = t->query("seller");
        if( !me || !me_ok( me )
          || !environment(me) || !environment(me)->query("room_mark")
          || me->query_temp("this_time_mark") != t->query("seller_mark") )
        {
            bad_goods += ({ t });
            continue;
        }

        // 好的，此物件OK
        if( who == this_object() || me == who )
            ok_goods += ({ t });
    }

    // 如果有要丢下的东西
    if( bad_goods && sizeof(bad_goods) )
    {
        env = environment(this_object());
        for(i=0;i<sizeof( bad_goods);i++)
        {
            message_vision( sprintf("$N扔下一%s%s，口里嘀咕了一句什么。\n",
                bad_goods[i]->query("unit"), bad_goods[i]->query("name") ),
                    this_object() );
            bad_goods[i]->move( env );
        }
    }

    if( !ok_goods || sizeof( ok_goods ) < 1 )
        return 0;
    return ok_goods;
}

int do_daishou( string arg )
{
    object me = this_player(), ob = this_object(), g, *temp;
    int value;
    string g_id, *no_sell_list;

    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    // 先判断够不够钱给手续费，不够则免了一系列判断。
    // 虽然这个位置不该判断手续费在先
    if( me->query_temp("hj_score") < SXF+1 ) // 这个 +1 可别改了
        return errs("你这个穷光蛋，手续费都给不起，难道还想要我帮你白做事？！\n");

    if( !arg || sscanf( arg, "%s #%d", g_id, value ) != 2 )
        return errs("你要代售什么货品(daishou 货品ID #价格)？例如： daishou xy jian #10\n");

    if( value<10 ) return errs("这东西卖那么便宜，还不够赚回手续费，还是省省吧。\n");
    if( value > 1000 ) return errs("你这价钱太吓人了，我这可不敢代着卖，免得没人要，放着又占地方。\n");

    g = present( g_id, me);
    if( !g ) return errs("你身上没有这东西。\n");
    if( !g->query("hj_game/obj") )
        return errs( g->query("name")+"是什么东西？我怎么不认识？……\n");

    // 禁止售卖id列表
    no_sell_list = ({ "qixing deng", "shenren ling", "youling ling",  });

    if( member_array( g->query("id"), no_sell_list ) != -1 )
        return errs("这"+g->query("name")+"啊，不能卖。\n");

    if( g->query("hj_game/obj") == "other" && g->query("id") != "sl guo" )
        return errs( g->query("name")+"？！这个东西可不好卖……\n");

    // 看看是否货满
    temp = get_goods_list( me );
    if( temp && sizeof( temp ) >= MAX_DS_AMOUNT_ME )
        return errs("你还有很多货在我这里呢，还是等卖掉一些了再说吧。\n");
    temp = get_goods_list( ob );
    if( temp && sizeof( temp ) >= MAX_DS_AMOUNT )
        return errs("我这里的货都快多得放不下了，还是等卖掉一些了再说吧。\n");


    // ok, 可为代售。
    me->add_temp("hj_score", -SXF );
    g->move( ob );
    g->set( "seller", me );
    g->set( "sell_id", me->query("id") );
    g->set( "sell_value", value );
    g->set( "seller_mark", me->query_temp("this_time_mark") );
    set( "new_goods_msg", ({ me->query("name"), g->short(), sprintf("%d",value) }) );
    set( "new_goods", g );

    message_vision( CYN"$N"NOR+CYN"拿出一"+g->query("unit")+g->query("name")+NOR+CYN"递给了$n"NOR+CYN"，说道：“请帮忙卖掉这个，要卖 \""+value+"\" 这个价钱啊！”\n"NOR,me,ob);
    message_vision( CYN"$N"NOR+CYN"又拿出一点什么塞给了$n"NOR+CYN"，说道：“这里是小小意思，麻烦你了！”\n"NOR,me,ob);
    command( "ok "+me->query("id") );

    // 新货品进仓，查找是否有求购该品的玩家，有就通知
    // 放到另一个函数里弄它。
    call_out( "new_goods_in", 3, g->query("id") );

    me->start_busy(1);

    return 1;
}


// 取回代售货品
int do_quhui( string arg )
{
    object g, me = this_player();

    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    if( !arg ) return errs("你要取回什么东西？\n");

    // 清一遍先
    get_goods_list( this_object() );

    g = present( arg, this_object() );
    if( !g ) return errs("我这没有这样东西。\n");
    if( g->query("seller") != me ) return errs("这"+g->query("name")+"不是你拿来代售的，想抢劫啊？\n");


    // ok.

    g->move(me);
    message_vision( sprintf( CYN"$N"NOR+CYN"对着$n"NOR+CYN"说道：“我想取回我的%s"NOR+CYN"。”\n$n"NOR+CYN"点了点头，拿出一%s%s"NOR+CYN"递给了$N"NOR+CYN"。\n"NOR, 
        g->query("name"), g->query("unit"), g->query("name") ), me, this_object() );

    me->start_busy(1);
    return 1;
}


// 购买货品
// 判断流程和 do_quhui 基本一样。
int do_goumai( string arg )
{
    object g, me = this_player(), seller;
    int value;

    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    if( !arg ) return errs("你要购买什么东西？\n");

    // 看够不够基本的钱先，免得又拉一次 all_inv
    if( me->query_temp("hj_score") < 10 )
        return errs("穷鬼，攒点钱再来吧。\n");

    // 清一遍先。此时将把不合条件的都清掉
    get_goods_list( this_object() );

    g = present( arg, this_object() );
    if( !g ) return errs("我这没有这样东西。\n");
    if( g->query("seller") == me ) return errs("这"+g->query("name")+"是你拿来代售的，你是要取回吗？(quhui)\n");

    value = g->query("sell_value");
    if( value < 10 )
        value = 10;
    if( me->query_temp("hj_score") < value )
        return errs("这个啊……你好象买不起。\n");

    // ok.
    me->add_temp("hj_score", -value );
    g->move(me);
    message_vision( sprintf( CYN"$N"NOR+CYN"对着$n"NOR+CYN"说道：“我想买个%s"NOR+CYN"。”\n$n"NOR+CYN"点了点头，拿出一%s%s"NOR+CYN"递给了$N"NOR+CYN"。\n"NOR, 
        g->query("name"), g->query("unit"), g->query("name") ), me, this_object() );
    me->start_busy(1);
    if( !(seller=g->query("seller"))
      || !me_ok(seller)
      || seller->query_temp( "this_time_mark" ) != g->query("seller_mark")
    )
        return 1;
    if( environment(seller) == environment(this_object() ) )
        message_vision( CYN +query("name")+NOR+CYN"对着$N"NOR+CYN"说道："
            "“嘿，你上次寄售的"+g->query("name")+NOR+CYN"卖出去了，这里是得到的收入。”\n"NOR, seller );
    else
        message_vision( CYN"只见一个"+query("name")+NOR+CYN"匆匆走了过来，对着$N"
            NOR+CYN"说道：“你上次寄售的"+g->query("name")+NOR+CYN"卖出去了，这里是得到的收入。”\n"
            +query("name")+NOR+CYN"说完，又匆匆地离开了。\n"NOR,  seller);
    tell_object( seller, "你得到了 "+value+" 点积分。\n");
    seller->add_temp( "hj_score", value );
    return 1;
}

int do_list( string arg )
{
    object me = this_player(), ob = this_object(), *list, who;
    int i, j;
    string msg, *key, *kkk;
    mapping qg_list;


    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    if( !arg ) who = ob;
    else
    {
        if( arg != "qg" )
        {
            if( arg == "me" ) arg = me->query("id");
            who = find_player( arg );
        }
    }

/* 求购信息设置格式
    set("qg_list", ([
        "tmxk yyf" : ({ "naihe", "zhu", "haha", "money" }),
        "dh jian" : ({ "yes" }),
        "test" : 0,
    ]) );
*/

    if( !who )
    {
        if( arg!= "qg" ) return errs( arg+" 没有任何货品在我这里代售。\n");

        qg_list = query("qg_list");
        if( !qg_list || sizeof(qg_list) < 1 )
            return errs("现在没有任何求购货品的信息。\n");

        msg = "现在有如下求购信息：\n";
        key = keys(qg_list);
        for(i=0;i<sizeof(key);i++)
        {
            kkk = qg_list[key[i]];
            if( kkk && sizeof(kkk) )
            {
                msg += sprintf( "\n(%s) 有求购者如下：", key[i] );
                for(j=0;j<sizeof(kkk);j++)
                    msg += sprintf( "    %s", kkk[j] );
            }
        }
        msg += "\n";
        me->start_busy(1);
        me->start_more("", msg,0 );
        return 1;
    }

    list = get_goods_list( who );
    if( !list || sizeof(list) < 1 )
    {
        if( who == ob )
            return errs("现在没有任何货品代售。\n");
        else return errs( arg+" 没有任何货品在我这里代售。\n");
    }

    if( who == ob )
        msg = "我这里现有这些货品代售：\n\n";
    else msg = "我这里现有这些货品是 "+arg+" 委托代售的：\n\n";

    for(i=0;i<sizeof(list);i++)
    {
        msg += sprintf( "%-40s  售价：%4d    %-20s  出售者：%s\n",
            list[i]->query("name")+"("+list[i]->query("id")+")",
            list[i]->query("sell_value"),
            list[i]->query("use_times")
                ? "剩余使用次数 "+list[i]->query("use_times")+ " "
                : "特别物品",
            list[i]->query("sell_id"));
    }
    me->start_busy( 1 );
    me->start_more("", msg,0 );
    return 1;
}


// 发布求购信息
int do_qiugou( string arg )
{
    object me = this_player(), *goods_list;
    string id = me->query("id"), *temp;
    int i;

    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    if( !arg ) return errs("你要求购什么物品？(qiugou 物品ID)\n");

    if( me->query_temp("hj_score") < SXF+1 )
        return errs("你这个穷光蛋，手续费都给不起，难道还想要我帮你白做事？！\n");

    temp = query( "qg_list/" + arg );
    if( temp && sizeof(temp) )
    {
        if( member_array( id, temp ) != -1 )
            return errs("你的事我会留心的了，一有消息我立刻通知你！\n");
        temp += ({ id });
        set( "qg_list/"+arg, temp );
    }
    else set( "qg_list/" + arg, ({ id }) );

    me->add_temp("hj_score", -SXF );

    message_vision( CYN"$N"NOR+CYN"拿出一点什么塞给了$n"NOR+CYN"，说道：“我急需 \""+arg+"\" 这个货，如果有消息请尽快通知我！”\n"NOR, me, this_object() );
    command( "nod2 "+id );
    command( "say “当然当然，请放心，一有货到，立刻通知！”");

    call_out("delete_msg", 1800, arg, id); // 半小时后删除此求购信息
    me->start_busy(1);


    // 收了钱再查是不是有现货
    goods_list = get_goods_list( this_object() );
    if( goods_list && sizeof( goods_list ) )
    {
        for( i=0;i<sizeof( goods_list );i++ )
        {
            if( goods_list[i]->query("id") == arg )
            {
                command("say “哟……这个我这里好象有现货，你要不要看看？(list)”");
                break;
            }
        }
    }
    return 1;
}


// 半小时内自动清除求购信息
void delete_msg( string qg_id, string who_id )
{
    string *list;
    if( !qg_id || !who_id ) return;
    list = query("qg_list/"+qg_id );
    if( !list || sizeof(list) < 1 || member_array( who_id, list) == -1 ) return;
    list -= ({ who_id });
    if( !list || !sizeof(list) )
    {
        delete( "qg_list/"+qg_id );
        return;
    }
    set("qg_list/"+qg_id, list );
}


// 新货进仓，通知曾求购的玩家
void new_goods_in( string id )
{
    int i;
    string *ids;
    object who;

    ids = query("qg_list/"+id);
    if( !ids || sizeof(ids) < 1 ) return;
    // 没有此物品的求购信息

    for(i=0;i<sizeof(ids);i++)
    {
        who = find_player( ids[i] );
        if( !who || !me_ok(who) ) continue;
        // 这里有个漏洞，玩家在上一轮游戏发布的求购信息，也会通知
        // 不过也无所谓~ 给了钱的，这点好处也是应该滴~

        if( environment(who) == environment(this_object() ) )
            message_vision( CYN"$n"NOR+CYN"对着$N"NOR+CYN"说道：“嘿，你不是说要买"
                +id+"吗，现在有货了。”\n"NOR,who, this_object() );
        else
            message_vision( CYN"只见一个"+query("name")+NOR+CYN"匆匆走了过来，对着$N"
                NOR+CYN"说道：“你早些时候想买的"+id+"，现在有货了！”\n"
                +query("name")+NOR+CYN"说完，又匆匆地离开了。\n"NOR, who);
    }

    delete( "qg_list/"+id );
}



// 广告内容：新货入仓，闲话
void me_do_ads()
{
    string *msg, temp;
    int i;

    if( !environment( this_object() ) ) return;

    msg = ({
"这里代售各类货品，手续从简，收费低廉哪！(daishou)",
"你急需求购什么东西吗？来我这发个消息，一有货到，立刻通知！(qiugou)",
"如果你有什么代售的东西又不想卖了，来我这取回就是，分文不取！(quhui)",
"来来来，走过路过不要错过，这里有好东西卖哪，快来看看吧！(list)",
"你有什么东西不需要的，来看看别人是不是正在求购它，也好卖掉啊！(list qg)",
    });


    // 新货信息
    if( query("new_goods") && environment( query("new_goods") ) == this_object() )
    {
        temp = query("new_goods_msg");
        if( temp && sizeof(temp) == 3 )
        {
            i=3;  // 让新货消息发布的频率高些
            while(i--) 
            msg += ({ sprintf( "现在有%s委托的最新货品%s"NOR+CYN"，仅售 %s 点，快来看看啦！",
                temp[0], temp[1], temp[2] ) });
        }
    }

    message_vision(CYN"$N"NOR+CYN"说道：“"+msg[random(sizeof(msg))]+"”\n"NOR,this_object());

    remove_call_out("me_do_ads");
    call_out("me_do_ads", 30 );
}


// 每3钟例行检查一次物品有效性
void checking()
{
    get_goods_list( this_object() );
    remove_call_out("checking");
    call_out("checking", 180);
}
