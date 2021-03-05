//                标准描述长度示例                                   |
// 幻境新添 NPC，铸剑师
// by naihe  2003-11-05  于茂名
// 宝石的要求太高，降低点 05-9-1 14:43

#include <ansi.h>
#include "errs_func.h"
// 里面有个 errs() 代替 notify_fail() ，即 write(msg), return 1;
inherit NPC;


#include "hj_settings/room_amount_hj.h"
#define        MY_ROOM_MARK        10
        // 此NPC仅出现在 HJ 密林东北方角落处才有效
#include "zj_lm_tarder_prefunc.h"


#define        SXF            20
        // 价格，即手续费

void create()
{
    set_name( "铸剑师", ({ "zhujian shi", "shi" }) );
    set("nickname", HIW"锈剑生辉 断刃复回"NOR );

    set("long", "这是一位手艺精湛的铸剑师，专接改造各类剑器的生意。
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    将某剑器改成 "GRN"青铜之剑"NOR"： <zj qtj 剑的ID>
    将某剑器改成 "HIW"白银之剑"NOR"： <zj byj 剑的ID>
    将某剑器改成 "HIY"黄金之剑"NOR"： <zj hjj 剑的ID>
    将某剑器改成 "HIW"灵气之剑"NOR"： <zj lqj 剑的ID>
    将某剑器改成 "HIM"盈动之剑"NOR"： <zj ydj 剑的ID>
    将某剑器改成 "HIY"耐力之剑"NOR"： <zj nlj 剑的ID>
    将某剑器改成 "HIW"迅隐之剑"NOR"： <zj xyj 剑的ID>
    将某剑器改成 "HIB"夺魂之剑"NOR"： <zj dhj 剑的ID>
    将某剑器改成 "HIR"必胜之剑"NOR"： <zj bsj 剑的ID>
需任意宝石 2 颗，及幻境得分 "+SXF+" 点 / 次。

修补某剑器（将之使用次数恢复）：<zj up 剑的ID>
需任意宝石 1 颗，幻境得分 "+(SXF/2)+" 点 / 次。
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    set("gender","男性");
    set("age",35);
    set("per",19);
    set("attitude","friendly");
    set("no_refresh",1);
    set("hj_game/npc","zhujian");

    setup();
}

void init()
{
    add_action("do_zhujian", ({ "zhujian", "zj" }) );
}

int do_zhujian( string arg )
{
    object me = this_player(), bs1, bs2, bs3, *all_mine, sword;
    string sword_id, type, *list, t;
    int i, set, score_need;

    if( !ob_ok() || !me_ok(me) ) return 0;
    if( me->is_busy() || me->query_temp("hj_need_waiting") )
        return errs("你还忙着呢。\n");

    if( !arg || sscanf( arg, "%s %s", type, sword_id ) != 2 )
        return errs("你是想铸剑吗(look zhujian shi)？\n");

    if( query("working") )
        return errs("我这还有点工作没完成，请稍等一会儿吧。\n");

    list = ({ "qtj","lqj","byj","ydj","hjj","nlj","xyj","dhj","bsj"});
    // 这里的顺序和 hj_obj_weapon.c 里的顺序是一样的。

    set = member_array( type, list );
    if( set == -1 && type != "up" )
        return errs("我这里可造不了 \""+type+"\" 这种剑，你还是另请高明吧。\n");

    sword = present( sword_id, me );
    if( !sword ) return errs("你可没带着这样的剑，你以为我是那个什么奈何啊，懂得凭空变把剑给你？\n");
    if( sword->query("hj_game/obj") != "sword" )
        return errs( sword->query("name")+"不是可以铸造的剑器。\n");
    // 如果是“神力之剑”拿来改，那……哈哈哈，不认识

    score_need = (type == "up" ? SXF/2 : SXF);
    if( me->query_temp("hj_score") < score_need +1 )
        return errs("阁下身无分文，还是不要诸多要求的好，有什么剑就将就着用吧。\n");

    // ok. up 剑
    if( type == "up" )
    {
        if( sword->query("use_times") >= sword->query("real_use_times") )
            return errs("这剑好好的，还锋利得很呢，还是不必修了吧。\n");
        all_mine = all_inventory(me);
        // 玩家身上肯定有剑，不必进行 !all_mine 的判断

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
            CYN"$N%s拿出一%s%s%s递给了$n%s，说道：“麻烦你帮我修修这剑。”\n"
            "$N%s说罢，又拿出了一颗宝石，还夹了点什么，一并塞给了$n%s。\n"
            "只见$n%s接过了剑，敲敲摸摸只弄了几下，就把它递给了$N%s。\n"
            "$n%s说道：“好啦，这剑已经修好了，保证好用。”\n"NOR,
                t, sword->query("unit"), sword->query("name"), t, t,
                t, t,
                t, t,
                t), me, this_object() );
        return 1;
    }
    // 那么就是换剑喽
    // 太烂的不行(使用了很多次的)
    if( sword->query("use_times") < sword->query("real_use_times")/2 )
        return errs("这剑刃口都卷了，你还是另请高明吧。\n");
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
        "$n%s接过了剑，说道：“好罢，稍后我就送去给你，放心即可。”\n"NOR,
            t, sword->query("unit"), sword->query("name"), t, t, type,
            t, t, t, t, t,
            t, t), me, this_object() );
    */
    message_vision( sprintf(
        CYN"$N%s拿出一%s%s%s递给了$n%s，说道：“麻烦你，我想把它改成 \"%s\" 。”\n"
        "$N%s说罢，又拿出了两颗宝石，还夹了点什么，一并塞给了$n%s。\n"
        "$n%s接过了剑，说道：“好罢，稍后我就送去给你，放心即可。”\n"NOR,
            t, sword->query("unit"), sword->query("name"), t, t, type,
            t, t, t, t, t,
            t, t), me, this_object() );
    destruct(sword);
    set("working", 1);
    remove_call_out( "send_sword" );
    call_out( "send_sword", 5+random(11), me, me->query_temp("this_time_mark"), set );
    // 稍微等待一下
    return 1;
}

void send_sword( object me, int me_mark, int set )
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
        CYN"$n%s把一%s%s%s递给了$N%s，说道：“你要改的剑已经改好了，保证好用。”\n"NOR,
        t, s->query("unit"), s->query("name"), t, t ), me, this_object() );
    else message_vision( sprintf(
        CYN"只见一位%s%s匆匆地走了过来，拿出一%s%s%s交给了$N%s。\n"
        "%s%s说道：“你要改的剑已经改好了，保证好用。”说完，%s%s又匆匆地离开了。\n"NOR,
        query("name"), t, s->query("unit"), s->query("name"),t, t,
        query("name"), t, query("name"), t ), me );

    s->move( me );
}