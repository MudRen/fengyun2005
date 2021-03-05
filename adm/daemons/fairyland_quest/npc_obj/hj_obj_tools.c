//                标准描述长度示例                                   |
// 幻境内物品  游戏工具类型
// by naihe  2002-10-24 ~ 25  于茂名
// 改善一下 fx, dx, xr 的效力 05-8-31 10:16

#include <ansi.h>

inherit ITEM;

#include "hj_settings/obj_list.h"          // 具体定义的变量请参看该文件
#include "hj_settings/room_amount_hj.h"

string *names=({
    HIG"定向水晶"NOR,
    HIC"飞翔之石"NOR,
    YEL"脱离水晶"NOR,
    HIW"回归之镜"NOR,
    HIY"祈祷之石"NOR,
    HIM"召唤之盒"NOR,
    HIM"发呆之旗"NOR,
    HIM"驱逐之旗"NOR,
    HIG"寻人水晶"NOR,
    HIB"窥探水晶"NOR,
    HIW"定位之仪"NOR,
});

/************************************
 本来还有诸多的想法，但：
1、道具太多，玩家将无所适从
2、每次想到新的都要添加，何时才是个头？
3、一些特强力的道具，可留待 幻境系列 第2集 里写！

by the way, 第2集的情节已想好几个国度的构思了！
玩家将能够进一步深入游戏中去，继续延续第1集里
的故事！！！

并且，第2集里将是以情节为主的内容！大家
拭目以待一个迷一般、史诗一般的情节吧！

YEAH~~   all by naihe 2002-10 ~ 11

终于未写，唉。 naihe 14:04 03-10-15
**************************************/



string *ids=({
    "dx shuijing",
    "fx zhishi",
    "tl shuijing",
    "hg zhijing",
    "qd zhishi",
    "zh zhihe",
    "fd zhiqi",
    "qz zhiqi",
    "xr shuijing",
    "kt shuijing",
    "dw zhiyi",
});

string *ids2=({
    "shj",
    "shi",
    "shj",
    "jing",
    "shi",
    "he",
    "qi",
    "qi",
    "shj",
    "shj",
    "yi",
});

string *longs=({
    "这是一个定向水晶，用它你可以(dingxiang / dx)查得自己身在何处。\n",
    "这是一颗飞翔之石，用它你可以(feixiang / fx)瞬间飞翔到幻境里的任何地方。\n",
    "这是一个脱离水晶，用它你可以(tuoli / tl)逃开怪物，随机脱离去到别的地方。\n",
    "这是一面回归之镜，用它你可以(huigui / hg)立刻离开幻境，回到现实里来（游戏得分将保持）。\n",
    "这是一颗祈祷之石，用它你可以(qidao / qd)祈祷随机宝物出现于自己所处之地。\n",
    "这是一个召唤之盒，用它你可以(zhaohuan / zh)召唤随机精灵出现于自己所处之地。\n",
    "这是一面发呆之旗，用它你可以(fadai / fd)让同一个地方的人发呆一会儿。\n",
    "这是一面驱逐之旗，用它你可以(quzhu / qz)让某地不许除了你之外的有着幻境气息的人停留。\n",
    "这是一颗寻人水晶，用它你可以(xunren / xr)寻找如你一样的勇士们所处何方。\n",
    "这是一颗窥探水晶，用它你可以(kuitan / kt)窥探如你一样的勇士们身上所带何物。\n",
    "这是一个定位之仪，用它你可以(dingwei here / dw here)先定位，再快速返回该地点(dw back)。\n",
});

string *units=({
    "个",
    "颗",
    "个",
    "面",
    "颗",
    "个",
    "面",
    "面",
    "颗",
    "颗",
    "个",
});

int *times=({
    10+random(6),
    3+random(3),
    3,
    1,
    2+random(2),
    3+random(3),
    2+random(2),
    1,
    9,
    9,
    3,
});


// 程序优化，所有能否使用道具的判断在此进行。
int can_use( string id, object me )
{
    if( !me || !id || query("id") != id ||
        !me->query_temp("huanjing") || me->query_temp("huanjing") != "start" ||
        !me->query_temp("hj_hp") || me->query_temp("hj_hp") < 1 ||
        query("use_times") <= 0 || !environment(me) ||
        !environment(me)->query("room_mark") )

        return 0;

    return 1;
}

// 程序优化，这里判断 busy .
int hj_busy_now( object me )
{
    if( !me || me->is_busy() || me->query_temp("hj_need_waiting") ) return 1;
    return 0;
}

void setme( int iii )
{
    if( iii == 99 ) iii = random( sizeof(names) );
    set( "iii" , iii );

    set_name(names[ iii ],({ ids[ iii ] , ids2[ iii ] }));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);

    set("long", longs[ iii ]);
    set("unit", units[ iii ]);
    set("value", 1);  // 该物件扔下后不会消失。

    set("use_times",times[ iii ] );
    set("hj_game/obj","tools");
    set("msg","你似乎忽地眼睛一花，地上不知怎么的就多了一件物事。\n");
}


void create()
{
    setme( 99 );
 //   setup();
}

void init()
{
    switch( query("iii") )
    {
        case 0: add_action("do_dingxiang", ({ "dingxiang", "dx" }) ); break;
        case 1: add_action("do_feixiang", ({ "feixiang", "fx" }) ); break;
        case 2: add_action("do_tuoli", ({ "tuoli", "tl" }) ); break;
        case 3: add_action("do_huigui", ({ "huigui", "hg" }) ); break;
        case 4: add_action("do_qidao", ({ "qidao", "qd" }) ); break;
        case 5: add_action("do_zhaohuan", ({ "zhaohuan", "zh" }) ); break;
        case 6: add_action("do_fadai", ({ "fadai", "fd" }) ); break;
        case 7: add_action("do_quzhu", ({ "quzhu", "qz" }) ); break;
        case 8: add_action("do_xunren", ({ "xunren", "xr" }) ); break;
        case 9: add_action("do_kuitan", ({ "kuitan", "kt" }) ); break;
        case 10: add_action("do_dingwei", ({ "dingwei", "dw" }) ); break;
    }

    if(query("qzzq_host_is"))
    {
        remove_call_out("get_out_here");
        call_out("get_out_here",1);
    }
}

void delete_me()
{
    if( query("real_name") )
    {
        message_vision(this_object()->query("real_name")+"灵气已尽，「嘭」地一声消失不见了。\n",this_object());
        environment()->delete("qzzq_now");
    }
    else
        message_vision(this_object()->query("name")+"灵气已尽，「嘭」地一声消失不见了。\n",this_object());
    destruct(this_object());
}

int do_dingxiang()
{
    object me = this_player(), ob = this_object(), rooms;
    int temp_mark;

    // 已优化的判断句
    if( !can_use( "dx shuijing" , me ) )
        return 0;
    // 本道具不受 busy 限制。
    //if( hj_busy_now( me ) ) return notify_fail("你还有别的事情忙着呢！\n");
    rooms = (environment(me));
    if(rooms && temp_mark = rooms->query("room_mark"))
    {
        message_vision(CYN"$N"NOR+CYN"拿起"NOR"$n"NOR+CYN"凝神注视着。\n"NOR, me, ob );
        add("use_times",-1);
        // 报假的几率降低了。
        if( !random(5) )
        {
            temp_mark+= random(2) - random(2);
            if( temp_mark < 1 || temp_mark > HJ_ROOM_AMOUNT )
                temp_mark = 1+random( HJ_ROOM_AMOUNT );
        }
        write(query("name")+"里隐约显现着一个标记，似乎是 " + chinese_number(temp_mark) + " 。 \n");
    }
    else
        return notify_fail("此地并非幻境密林内。\n");
    if( query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_feixiang(string arg)
{
    object me = this_player(), ob = this_object(), rooms;
    int temp_mark;
    string goto_rooms;

    // 已优化的判断句
    if( !can_use( "fx zhishi" , me ) )
        return 0;
    if ( !arg || !sscanf(arg, "%d",temp_mark) ) 
        return notify_fail("这里的区域标记为 1 - "+HJ_ROOM_AMOUNT+" 。输入你想要去的地方的标记吧……\n");
    if( temp_mark < 1 || temp_mark > HJ_ROOM_AMOUNT)
        return notify_fail("这里的区域标记为 1 - "+HJ_ROOM_AMOUNT+" 。输入你想要去的地方的标记吧……\n");
    if( hj_busy_now( me ) )
        return notify_fail("你还有别的事情忙着呢！\n");
    message_vision(CYN"$N"NOR+CYN"左手把$n"NOR+CYN"握在手心，右手伸出，指了一个方向。\n"NOR,me, ob);
    add("use_times",-1);
    // 飞错的几率降低了。
    if( !random(5) )
    {
        temp_mark+= random(2) - random(2);
        if( temp_mark < 1 || temp_mark > HJ_ROOM_AMOUNT)
            temp_mark = 1+random(HJ_ROOM_AMOUNT);
    }
    goto_rooms = HJ_DIR +"hj_room"+ temp_mark;
    rooms = find_object(goto_rooms);
    if(!rooms)
        rooms = load_object(goto_rooms);
    message_vision(HIC"$N"HIC"腾空而起，往远处飞去了。\n"NOR,me);
    me->move(rooms);
    message_vision(HIC"只见$N"HIC"从空中飘然而下，稳稳地落在地上。\n"NOR,me);
    if( query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_tuoli()
{
    object me = this_player(), ob = this_object(), rooms;
    string random_rooms;

    // 已优化的判断句
    if( !can_use( "tl shuijing" , me ) )
        return 0;
    message_vision(CYN"$N"NOR+CYN"把$n"NOR+CYN"紧紧抓在手心里高举过头，大声叫道：“脱离此地！”\n"NOR,me, ob);
    add("use_times",-1);
    random_rooms = HJ_DIR +"hj_room"+ (1+random(HJ_ROOM_AMOUNT));
    rooms = find_object(random_rooms);
    if(!rooms)
        rooms = load_object(random_rooms);
    message_vision(HIR"$N"HIR"身形一晃，随即消失不见了。\n"NOR,me);
    me->move(rooms);
    message_vision(HIR"$N"HIR"突然出现在这里，一副惊魂未定的样子。\n"NOR,me);
    if(query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_huigui()
{
    object me = this_player(), ob = this_object(), rooms,qxd;

    // 已优化的判断句
    if( !can_use( "hg zhijing" , me ) )
        return 0;
    if( hj_busy_now( me ) )
        return notify_fail("你还有别的事情忙着呢！\n");
    qxd = present( "qixing deng",me);
    if(!qxd || qxd->query("my_master") != me )
        return notify_fail("你身上没有七星灯？……或者你不是它的主人？……\n请使用 quit 指令强行退出游戏！\n");
    if( !qxd ->query("can_quit_hj") )
        return notify_fail("你才刚进来游戏没多久，就要离开？\n");
    if( qxd ->query("wait_over") == "yes" )
        return notify_fail("你的游戏时间即将结束，不必使用"+query("name")+"了吧。\n");
    message_vision(CYN"$N"NOR+CYN"拿起"NOR"$n"NOR+CYN"高举过顶，口里叫道：“现实映现！”\n"NOR,me, ob);
    set("use_times",0);
    qxd->set("use_huigui","yes");
    message_vision(WHT"只见一阵白雾不知从何处飘来，愈来愈浓……\n"NOR,me);
    remove_call_out("delete_me");
    call_out("delete_me",1);
    return 1;
}

int do_qidao()
{
    object ob = this_object(),me = this_player(),obj;
    string msg,*temp_list;

    if( !can_use( "qd zhishi", me ) )
        return 0;
    if( hj_busy_now( me ) )
        return notify_fail("你还有别的事情忙着呢！\n");
    message_vision(CYN"$N"NOR+CYN"双手握起"NOR"$n"NOR+CYN"捧在心口，闭目喃喃说着什么。\n"NOR,me, ob);
    add("use_times",-1);
    if( !random(30) )  // 玩家将有更多的机会得到属于自己的宝物组成部分
    {
        if( !me->query_temp("hj_game_find") ) return 1;
        temp_list=({"wait","wait"});
        switch( me->query_temp("hj_game_find") )
        {
            case "feng":
                temp_list=obj_list_feng; break;
            case "yu":
                temp_list=obj_list_yu; break;
            case "lei":
                temp_list=obj_list_lei; break;
            case "dian":
                temp_list=obj_list_dian; break;
        }
        if( temp_list[0] == "wait")
            return 1;
        obj=new( temp_list[0] );
        obj->set("host_id",me->query("id"));
        obj->setme( 1+random(2) );
        obj->move(environment(me));
        if(obj->query("msg")) msg=obj->query("msg");
        else msg="忽然一小阵轻烟掠过……这里似乎多了一些什么。\n";
        tell_room(environment(me),msg);
    }
    else
    {
        obj=new( obj_list_obj[random(sizeof(obj_list_obj))] );
        obj->move(environment(me));
        if(obj->query("msg")) msg=obj->query("msg");
        else msg="忽然一小阵轻烟掠过……这里似乎多了一些什么。\n";
        tell_room(environment(me),msg);
    }
    // busy 由 3秒降为 1秒。
    me->start_busy(1);
    if( query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_zhaohuan()
{
    object ob = this_object(),me = this_player(),obj;
    string msg,*temp_list;

    if( !can_use( "zh zhihe", me ) )
        return 0;
    if( hj_busy_now( me ) )
        return notify_fail("你还有别的事情忙着呢！\n");
    message_vision(CYN"$N"NOR+CYN"右手捧起"NOR"$n"NOR+CYN"放在身前，猛地喝了一声：“精灵显现！”\n"NOR,me, ob);
    add("use_times", -1);
    //ob->set("use_times",0);  // 这里不知为何有BUG，为了解决，附加这一句。
    // 已无BUG
    if( !random(30) )  // 玩家将有更多的机会得到属于自己的宝物组成部分。这里是NPC携带宝物。
    {
        if( !me->query_temp("hj_game_find") ) return 1;
        temp_list=({"wait","wait"});
        switch( me->query_temp("hj_game_find") )
        {
            case "feng":
                temp_list=obj_list_feng; break;
            case "yu":
                temp_list=obj_list_yu;break;
            case "lei":
                temp_list=obj_list_lei;    break;
            case "dian":
                temp_list=obj_list_dian;break;
        }
        if( temp_list[0] == "wait")
            return 1;
        obj=new( temp_list[1] );
        obj->set("host_id",me->query("id"));
        obj->move(environment(me));
        if(obj->query("msg"))
            msg=obj->query("msg");
        else
            msg="忽然一小阵轻烟掠过……这里似乎多了一些什么。\n";
        tell_room(environment(me),msg);
    }
    else
    {
        obj=new( obj_list_npc[random(sizeof(obj_list_npc))] );
        obj->move(environment(me));
        if(obj->query("msg"))
            msg=obj->query("msg");
        else
            msg="忽然一小阵轻烟掠过……这里似乎多了一些什么。\n";
        tell_room(environment(me),msg);
    }
    if( query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

void fadai( object target, int time )
{
    object srl;
    // 夺魂之技特殊技能体现之三(1)，有效抵抗发呆之旗
    if( target->query_temp("hj_special/sh") )
    {
        message_vision( HIB"只听得$N"HIB"四周忽地响起一阵凄厉之声，似是把$N"HIB"保护起来了一般。\n"
            "$N"HIB"哈哈一笑，精神奕奕，竟是对发呆之旗毫无所惧。\n"NOR, target);
    }
    else if( (srl=present( "shenren ling", target )) )
    {
        message_vision( CYN"$N"NOR+CYN"身上的"+srl->query("name")+NOR+CYN"突然发出一阵光芒，"
            +"似是把$N"NOR+CYN"保护起来了一般。\n"NOR, target );
    }
    // 临时离开游戏，保证其安全
    else if( present( "hj temp leave obj", target ) )
    {
        message_vision( CYN"$N"NOR+CYN"身形忽隐忽现，竟似并无实体一般，发呆之旗却是毫无用处。\n"NOR, target );
    }
    else
    {
        message_vision(HIY"只见$N"HIY"忽地双目发直，果然就是个呆子般模样。\n"NOR,target);
        target->start_busy( target->query_busy() + time );
    }
}
int do_fadai(string arg)
{
    object *inv_here,target,me=this_player(),ob=this_object(), srl;
    int time,human_amount,i;

    if( !can_use( "fd zhiqi", me ) )
        return 0;
    // 不限制忙时
    //if( hj_busy_now( me ) )
        //return notify_fail("你还有别的事情忙着呢！\n");
    if(!arg)
        return notify_fail("你要让谁发呆？格式：\n"
            "让某人发呆 <fadai "+me->query("id")+"> \n"
            "让这个地方的所有有气息的人发呆 <fadai all> (需要消耗自身的气息)\n");
    if(!me->query_temp("hj_game_mepower"))
        time=3;
    else
        time= 5 + random(me->query_temp("hj_game_mepower"));
    if(time > 60)
        time = 60;
    if(time < 10)
        time = 10;
    if(arg != "all")
    {
        target = present(arg , environment( me ) );
        if(!target)
            return notify_fail("这里没有这个人。\n");
        if(!target->is_character())
            return notify_fail("这不是活物！\n");
        if(!target->query_temp("hj_hp") || target->query_temp("hj_hp") <1 )
            return notify_fail(target->query("name")+"没有幻境里的气息，无法对其进行攻击。\n");
        if(!living(target))
            return notify_fail("这个游戏里必须是清醒的对手才能攻击。\n");
        if( target == me )
            return notify_fail("让自己发呆？没必要吧……\n");
        message_vision(HIY"$N"HIY"举起"NOR"$n"HIY"大声叫道：“呆子出现！”\n"NOR,me, ob);
        fadai( target, time );
    }
    else
    {
        if(me->query_temp("hj_hp") < 60 )
            return notify_fail("你的气息不够，使唤不了这个东西。\n");
        inv_here = all_inventory(environment(me));
        if(!inv_here || sizeof(inv_here) < 2)
            return notify_fail("这儿没别的人，这可是个宝贝，还是省着点用吧。\n");
        for(i=0;i<sizeof(inv_here);i++)
        {
            if( inv_here[i] ->query_temp("hj_hp") &&
                inv_here[i]->query_temp("hj_hp") > 0 &&
                inv_here[i] != me )
            human_amount++;
        }
        if( human_amount < 1 )
            return notify_fail("这儿没别的人，这可是个宝贝，还是省着点用吧。\n");
        message_vision(HIY"$N"HIY"举起"NOR"$n"HIY"声嘶力竭般大声叫喊道：“一堆呆子，快快出现！”\n"NOR,me, ob);
        for(i=0;i<sizeof(inv_here);i++)
        {
            if( inv_here[i] ->query_temp("hj_hp") &&
                inv_here[i]->query_temp("hj_hp") > 0 &&
                inv_here[i] != me
            )
                fadai( inv_here[i], time );
        }
        me->add_temp("hj_hp",- (25 + random(26) ) );
        tell_object(me,"你大叫之后，觉得气喘吁吁的。\n");
    }
    add("use_times",-1);
    if( query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_quzhu()
{
    object env, me=this_player(), ob=this_object();
    if( !can_use( "qz zhiqi", me ) )
    {
        write("什么？\n");
        return 1;
    }
    // 不受忙时限制。
    //if( hj_busy_now( me ) ) return notify_fail("你还有别的事情忙着呢！\n");
    env = environment(me);
    if(env->query("room_mark") == 1)
        return notify_fail("你不能在这个地方插下驱逐之旗。\n");
    if( env->query("qzzq_now") )
    {
        write("这里已经有人插下驱逐之旗了。\n");
        return 1;
    }
    set("qzzq_host_is",me->query("id") );
    add("use_times",-1);
    set("use_times",0); // 有bug噢，不加这句不行，怪事.
    set("real_name","插在地上的驱逐之旗");
    set("no_refresh", 1 );
    if( environment(this_object()) != me )
        message_vision(CYN"$N"NOR+CYN"把"NOR"$n"NOR+CYN"拣了起来，使劲地插到了地上！\n"NOR,me, ob);
    else
        message_vision(CYN"$N"NOR+CYN"从身上取出"NOR"$n"NOR+CYN"，使劲地插到了地上！\n"NOR,me, ob);
    message_vision(HIB"霎时间狂风大作，就连天空也暗了下来！\n"NOR,me);
    move( env );
    set_weight(6300000);
    env->set("qzzq_now", 1);
    ob->get_out_here();
    ob->set_name(HIM"　　　　　　　一面 驱逐之旗 插在地上　　　　　　　"NOR,({"　"}));
    remove_call_out("delete_me");
    call_out("delete_me",180+random(300));
    // 时间延长，由原来的 2-3 分钟延长到 3-5 分钟。
    return 1;
}

void get_out_here()
{
    object *inv_here,srl,random_rooms;
    string temp;
    int i;
    inv_here = all_inventory(environment(this_object()));
    for(i=0;i<sizeof(inv_here);i++)
    {
        if( inv_here[i]->query("id") == query("qzzq_host_is") )
            continue;
        if( !inv_here[i]->query_temp("hj_hp") )
            continue;
        srl = present("shenren ling" , inv_here[i] );
        if(srl)
        {
            message_vision( HIC+query("real_name")+""HIC"发出一阵耀眼光芒！……\n"
                +"却见$N"HIC"身上的"+srl->query("name")+HIC
                +"也散出一阵光芒，似是保护圈般把$N"HIC"围了起来！\n"NOR,
                inv_here[i] );
            continue;
        }
        // 玩家暂时离开，保护其角色的安全。
        if( present( "hj temp leave obj", inv_here[i] ) )
        {
            continue;
        }
        message_vision(HIC+query("real_name")+""HIC"发出一阵耀眼光芒！……只见$N"
            +HIC"身不由己地往外飞了出去！\n"NOR,inv_here[i]);
        if(inv_here[i]->query_temp("hj_flying") )
        {
            inv_here[i]->delete_temp("hj_flying");
            temp = HJ_DIR  +"hj_room"+ 1;
        }
        else
        {
            inv_here[i]->set_temp( "hj_flying", 1 );
            temp= HJ_DIR  + "hj_room" + ( 1+random(HJ_ROOM_AMOUNT) );
        }
        random_rooms=find_object( temp );
        if(!random_rooms)
            random_rooms=load_object( temp );
        inv_here[i]->move(random_rooms);
        message_vision("$N从半空中跌了下来，不知道是怎么回事。\n",inv_here[i]);
    }
}

int do_xunren(string arg)
{
    object ob=this_object(),me=this_player(),target,rooms;
    int temp_mark;

    if( !can_use( "xr shuijing", me ) )
        return 0;
    // 不受忙时限制。
    //    if( hj_busy_now( me ) ) return notify_fail("你还有别的事情忙着呢！\n");
    if(!arg)
        return notify_fail("你要寻找什么人？\n");
    if( arg == me->query("id") )
        return notify_fail("幻境里虽然有些妖魔鬼怪，但你"+me->query("name")+"还是一个而已，没有更多的了。\n");
    target = find_player(arg);
    if(!target)
        return notify_fail("现在并没有这个玩家在线，莫要说在这里了。\n");
    rooms = (environment(target));
    if( !rooms || !rooms->query("room_mark") )
        return notify_fail("幻境·密林里并没有这个玩家。\n");
    temp_mark = rooms->query("room_mark");
    message_vision(CYN"$N"NOR+CYN"拿起"NOR"$n"NOR+CYN"凝神注视着，似要从中看出什么来。\n"NOR,me, ob);
    add("use_times",-1);
    // 寻错的几率降低了。
    if( !random(5) )
    {
        temp_mark += random(2) - random(2);
        if( temp_mark < 1 || temp_mark > HJ_ROOM_AMOUNT )
            temp_mark = 1+random( HJ_ROOM_AMOUNT );
    }
    write(query("name")+"里隐约显现着出标记，似乎是 "+chinese_number(temp_mark)+" 。\n");
    if( query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_kuitan(string arg)
{
    object target,*inv,me=this_player();
    int i;
    string target_name;

    if( !can_use( "kt shuijing", me ) )
        return 0;
    // 不受忙时限制。
    //    if( hj_busy_now( me ) ) return notify_fail("你还有别的事情忙着呢！\n");
    if(!arg)
        return notify_fail("你要窥探谁的行囊？\n");
    target = present(arg , environment( me ) );
    if(!target)
        return notify_fail("这里没有这个人。\n");
    if(!target->is_character())
        return notify_fail("这不是活物！\n");
    if(target->query("hj_game/npc"))
        return notify_fail("这不是与你一样的玩家勇士。\n");
    if(!target->query_temp("hj_hp") || target->query_temp("hj_hp") <1 ||
       target->query_temp("huanjing") != "start" )
        return notify_fail(target->query("name")+"已没有丝毫幻境里的气息，算了吧。\n");
    if(!living(target))
        return notify_fail("这个游戏里必须是清醒的对手才能进行操作。\n");
    inv = all_inventory(target);
    if(target == me)
        target_name="你";
    else
        target_name = target->query("name");
    tell_object(me,"你悄悄地拿起水晶，仔细地看着……\n");
    if( !inv || sizeof(inv)<1 )
        return notify_fail(target_name+"身上没带着任何东西。\n");
    for(i=0;i<sizeof(inv);i++)
    {
        if( inv[i]->query("hj_game/obj") && random(3) )
        {
            tell_object(me,sprintf("%s身上似乎带有一%s%s。\n",
                target_name,inv[i]->query("unit"),inv[i]->query("name")));
        }
    }
    // 使用忙时取消，不再给对方提示。
    //     if( target != me) tell_object(target,HIB"你只觉得似乎有些异样的眼光在探视着自己一般……\n"NOR);
    //    tell_object(me,"你盯着看久了，竟然觉得有些累似的。\n");
    //    me->start_busy(5+random(6));
    add("use_times",-1);
    if(query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

int do_dingwei( string arg )
{
    object me = this_player(), ob = this_object(), the_room;
    string room_name;

    if( !can_use( "dw zhiyi", me ) )
        return 0;
    if( hj_busy_now(me) )
        return notify_fail("你还忙着呢。\n");
    if( !arg || (arg != "here" && arg != "back") )
        return notify_fail("你要将这里定位(dingwei here)还是要返回(dingwei back)之前定位的地点？\n");
    if( arg == "here" )
    {
        message_vision(CYN"$N"NOR+CYN"拿出$n"NOR+CYN"，做了一个标记。\n"NOR, me, ob );
        set( "dingwei_" + me->query("id"), environment(me)->query("room_mark") );
        me->start_busy(1);
        return 1;
    }
    // 否则就是返回该地点
    if( !query( "dingwei_" + me->query("id") ) )
        return notify_fail("这"+query("name")+"没有你做的定位标记，你想回到哪里去？\n");
    room_name = HJ_DIR + "hj_room" + query("dingwei_" + me->query("id") );
    the_room = find_object( room_name );
    if( !the_room )
        the_room = load_object( room_name );
    if( !the_room )
        return notify_fail("你先前定下的标记不知怎么的消失了，回不去。\n");
    message_vision(CYN"$N"NOR+CYN"举起$n"NOR+CYN"，大声喝道：“去！”\n"NOR, me, ob);
    message_vision(HIW"$N"HIW"忽地身形一晃，消失不见了。\n"NOR, me);
    me->move( the_room );
    message_vision(HIW"$N"HIW"突然出现在这里。\n"NOR, me );
    me->start_busy(1);
    add( "use_times", -1 );
    if(query("use_times") <=0 )
    {
        remove_call_out("delete_me");
        call_out("delete_me",1);
    }
    return 1;
}

