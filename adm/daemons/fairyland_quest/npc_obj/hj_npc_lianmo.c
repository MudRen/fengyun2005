//                标准描述长度示例                                   |
// 幻境新添 NPC，炼魔匠
// by naihe  2003-11-05  于茂名
// 宝石的要求太高，降低点 05-9-1 14:43

#include <ansi.h>
#include "errs_func.h"
// 里面有个 errs() 代替 notify_fail() ，即 write(msg), return 1;
inherit NPC;

#include "hj_settings/room_amount_hj.h"
#define        MY_ROOM_MARK        HJ_ROOM_AMOUNT-9
        // 此NPC仅出现在 HJ 密林西南方角落处才有效
#include "zj_lm_tarder_prefunc.h"

#define        SXF            20
        // 价格，即手续费

void create()
{
    set_name( "炼魔匠", ({ "lianmo jiang", "jiang" }) );
    set("nickname", HIM"呼风唤雨 法力无穷"NOR );

    set("long", "这是一位魔力强大的炼魔匠，专接改造各类魔法水晶的生意。
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  将某魔法水晶改成 "HIW"狂风水晶"NOR"： <lm kfsj 水晶的ID>
  将某魔法水晶改成 "MAG"暴雨水晶"NOR"： <lm bysj 水晶的ID>
  将某魔法水晶改成 "HIC"落雷水晶"NOR"： <lm llsj 水晶的ID>
  将某魔法水晶改成 "HIG"引电水晶"NOR"： <lm ydsj 水晶的ID>
  将某魔法水晶改成 "YEL"滚石水晶"NOR"： <lm gssj 水晶的ID>
  将某魔法水晶改成 "RED"飞火水晶"NOR"： <lm fhsj 水晶的ID>
  将某魔法水晶改成 "BLU"夺魂水晶"NOR"： <lm dhsj 水晶的ID>
需任意宝石 2 颗，及幻境得分 "+SXF+" 点 / 次。

修补某魔法水晶（将之使用次数恢复）：<lm up 水晶的ID>
需任意宝石 1 颗，幻境得分 "+(SXF/2)+" 点 / 次。
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    set("gender","女性");
    set("age",91);
    set("per",11);
    set("attitude","friendly");
    set("no_refresh",1);
    set("hj_game/npc","lianmo");

    setup();
}

void init()
{
    add_action("do_lianmo", ({ "lianmo", "lm" }) );
}

// 该函数复制 zhujian shi 的，一些函数名懒得改了
// 而且又懒得做成 #include ，就这样吧。
int do_lianmo( string arg )
{
    object me = this_player(), bs1, bs2, bs3, *all_mine, sword;
    string sword_id, type, *list, t;
    int i, set, score_need;

    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    if( !arg || sscanf( arg, "%s %s", type, sword_id ) != 2 )
        return errs("你是想提炼魔法水晶吗(look lianmo jiang)？\n");

    if( query("working") )
        return errs("我这还有点工作没完成，请稍等一会儿吧。\n");

    list = ({ "kfsj","bysj","llsj","ydsj","gssj","fhsj","dhsj" });
    // 这里的顺序和 hj_obj_weapon.c 里的顺序是一样的。

    set = member_array( type, list );
    if( set == -1 && type != "up" )
        return errs("咳…… \""+type+"\" 这种魔法水晶，我可是听都没听过啊……\n");

    set += 9;
    // 配合 hj_obj_weapon.c 的设置。

    sword = present( sword_id, me );
    if( !sword ) return errs("你可没带着这样的水晶，你以为我是那个什么奈何啊，懂得凭空变给你？\n");
    if( sword->query("hj_game/obj") != "magic" )
        return errs( sword->query("name")+"不是可以提炼的魔法水晶。\n");
    // 如果是其他各类水晶……哈哈哈，也不认识

    score_need = (type == "up" ? SXF/2 : SXF);
    if( me->query_temp("hj_score") < score_need +1 )
        return errs("你身无分文，如何表示你的诚意呀？\n");
    // ok. up it.
    if( type == "up" )
    {
        if( sword->query("use_times") >= sword->query("real_use_times") )
            return errs("这水晶里还充满了魔力，还是不必提炼了吧。\n");

        all_mine = all_inventory(me);
        // 玩家身上肯定有sj，不必进行 !all_mine 的判断
        /*
        for(i=0;i<sizeof(all_mine);i++)
        {
            // 任意宝石
            if( all_mine[i]->id("baoshi")
              && all_mine[i]->query("hj_game/obj") == "other" )
            {
                if( !bs1 ) bs1 = all_mine[i];
                else if( !bs2 ) bs2 = all_mine[i];
                else { bs3 = all_mine[i]; break; }
            }
        }
        if( !bs1 || !bs2 || !bs3 )
            return errs("这……这需要三颗宝石，你好象不够吧。\n");
        destruct( bs1 );
        destruct( bs2 );
        destruct( bs3 );
        */
        // 改为任意宝石一颗即可
        for(i=sizeof(all_mine)-1; i>=0; i-- )
        {
            if( all_mine[i]->id("baoshi")
              && all_mine[i]->query("hj_game/obj") == "other"
            )
            {
                bs1 = all_mine[i];
                break;
            }
        }
        if( !bs1 )
            return errs("这需要一颗宝石，你好象没有吧。\n");
        destruct( bs1 );
        // 全部OK，进行设置及描述等
        me->add_temp("hj_score", -score_need );
        me->start_busy(1);
        sword->set("use_times", sword->query("real_use_times") );
        if( sword->query("use_times") < 1 ) sword->set("use_times", 1);

        t = NOR+CYN;
        message_vision( sprintf(
            CYN"$N%s拿出一%s%s%s递给了$n%s，说道：“麻烦你帮我炼炼这水晶。”\n"
            "$N%s说罢，又拿出了一颗宝石，还夹了点什么，一并塞给了$n%s。\n"
            "只见$n%s接过了水晶，敲敲摸摸只弄了几下，就把它递给了$N%s。\n"
            "$n%s说道：“好啦，这水晶已经修好了，保证好用。”\n"NOR,
                t, sword->query("unit"), sword->query("name"), t, t,
                t, t,
                t, t,
                t), me, this_object() );
        return 1;
    }

    // 那么就是换sj喽
    // 太烂的不行(使用了很多次的)
    if( sword->query("use_times") < sword->query("real_use_times")/2 )
        return errs("这水晶的灵气已经衰败，你还是另请高明吧。\n");
    /*
    bs1 = present( "red baoshi", me );
    bs2 = present( "green baoshi", me );
    bs3 = present( "blue baoshi", me );
    if( !bs1 || bs1->query("hj_game/obj") != "other"
      || !bs2 || bs2->query("hj_game/obj") != "other"
      || !bs3 || bs3->query("hj_game/obj") != "other"
    )
        return errs("这……这需要各色宝石各一颗，你好象不够吧。\n");
    destruct( bs1 );
    destruct( bs2 );
    destruct( bs3 );
    */
    // 改为任意2颗宝石
    all_mine = all_inventory(me);
    for(i=sizeof(all_mine)-1; i>=0; i-- )
    {
        if( all_mine[i]->id("baoshi")
            && all_mine[i]->query("hj_game/obj") == "other"
        )
        {
            if( !bs1 )
                bs1 = all_mine[i];
            else
            {
                bs2 = all_mine[i];
                break;
            }
        }
    }
    if( !bs1 || !bs2)
        return errs("这需要两颗宝石，你好象不够吧。\n");
    destruct( bs1 );
    destruct( bs2 );
    // 那么就OK喽
    me->add_temp("hj_score", -score_need );
    me->start_busy(1);

    t = NOR+CYN;
    /*
    message_vision( sprintf(
        CYN"$N%s拿出一%s%s%s递给了$n%s，说道：“麻烦你，我想把它改成 \"%s\" 。”\n"
        "$N%s说罢，又拿出了"HIR"红%s、"HIG"绿%s、"HIB"蓝%s共三颗宝石，还夹了点什么，一并塞给了$n%s。\n"
        "$n%s接过了水晶，说道：“好罢，稍后我就送去给你，放心好啦……”\n"NOR,
            t, sword->query("unit"), sword->query("name"), t, t, type,
            t, t, t, t, t,
            t, t), me, this_object() );
    */
    message_vision( sprintf(
        CYN"$N%s拿出一%s%s%s递给了$n%s，说道：“麻烦你，我想把它改成 \"%s\" 。”\n"
        "$N%s说罢，又拿出了两颗宝石，还夹了点什么，一并塞给了$n%s。\n"
        "$n%s接过了水晶，说道：“好罢，稍后我就送去给你，放心好啦……”\n"NOR,
            t, sword->query("unit"), sword->query("name"), t, t, type,
            t, t, t, t, t,
            t, t), me, this_object() );

    destruct(sword);
    set("working", 1);
    remove_call_out( "send_sj" );
    call_out( "send_sj", 5 + random(11), me, me->query_temp("this_time_mark"), set );
    // 稍微等待一下

    return 1;
}

void send_sj( object me, int me_mark, int set )
{
    object s;
    string t;

    set("working", 0);
    if( !me || !me_ok(me) || !me_mark || me->query_temp("this_time_mark") != me_mark )
        return;

    s = new( __DIR__"hj_obj_weapon" );
    s ->setme( set );
    t = NOR+CYN;

    if( environment(me) == environment(this_object()) )
        message_vision( sprintf(
        CYN"$n%s把一%s%s%s递给了$N%s，说道：“你要改的水晶已经改好了，拿去用吧。”\n"NOR,
        t, s->query("unit"), s->query("name"), t, t ), me, this_object() );
    else message_vision( sprintf(
        CYN"只见一位%s%s匆匆地走了过来，拿出一%s%s%s交给了$N%s。\n"
        "%s%s说道：“你要改的水晶已经改好了，拿去用吧。”说完，%s%s又匆匆地离开了。\n"NOR,
        query("name"), t, s->query("unit"), s->query("name"),t, t,
        query("name"), t, query("name"), t ), me );

    s->move( me );
}