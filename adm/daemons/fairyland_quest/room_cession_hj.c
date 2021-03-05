//                标准描述长度示例                                   |
// 自由转让 幻境游戏内 EXP POT 的房间
// by naihe  2002-11-09  于茂名

#include <ansi.h>
inherit ROOM;
#include <ctime_format_func.h>

#include "z_hj_log_func.h"
// 此文件中定义了LOG文件的文件名：HJ1_LOG_FILE
// 以及 hj_log_file(string log_msg) 函数。
// 本文件及 游戏出口处 都使用 hj_log_file() 函数，而不直接使用 log_file() .

void create()
{
    set("short", "幻境游戏奖品转让处");
    set("long", "
    幻境游戏是一个没有EXP、没有SKILLS要求的游戏，人人可玩，
并且效果一样。更重要的是，它允许你在自己的主ID练功时，使用
一个别的ID（甚至是新注册的ID）来进行游戏，并且：

       "HIR"游戏得到的经验值、潜能值允许转让给登记的ID"NOR"

    将两个ID都登记一次，即可相互转让在游戏里得到的 EXP/POT 。
    "HIG"<dengji 人物ID>"NOR"   登记你的相互ID(主ID及大米各登记一次)
    "HIG"<checkme>"NOR"         查询自己的未转出的 EXP/POT 情况
    "HIG"<take exp / pot 点数>"NOR"  把 EXP/POT 兑现
    "HIG"<zhuan exp / pot 点数>"NOR" 把 EXP/POT 转给登记ID并同时兑现

    更详细的说明，请输入<help here> 指令。\n\n");
    set("no_fight", "1");
    set("no_fly", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("valid_startroom", 1);
     set("no_magic", 1);

    set("exits", ([
        "down":__DIR__"room_door_hj",
        ]));

    setup();
}

void init()
{
    add_action("do_zhuan","zhuan");
    add_action("do_take", "take");
    add_action("do_checkme","checkme");
    add_action("do_dengji","dengji");
    add_action("do_help","help");
}

int do_help(string arg)
{
    string msg;
    if(!arg || arg!="here") return 0;

    msg = "###########  幻境游戏登记ID详细说明 #############
    为了防止出现“众多大米造就一个获益ID”的情况，
故实行“相互登记”的规则。在这里，你只需要把任何
两个ID都登记上对方的ID，就可以完成登记手续，而在
接下来的任何时候，无论你用哪一个ID进行游戏，它所
得到的经验值和潜能值，都可以转让给另一个ID。举例：

    我希望能够把这两个ID的得益相互转让：
    \"naihe\" ----> 主ID  \"money\" ----> 大米ID\n";

    msg += "
    那么，我先用\"naihe\"输入指令：<dengji money>，
再用\"money\"输入指令：<dengji naihe>，即可完成。
完成以后，在日后进行游戏时，无论是\"naihe\"还是
\"money\"所得到的经验、潜能奖励，都可以在相互之间
随意转让了。

    祝游戏愉快！
                           by naihe 2003-10-22
#################################################\n";

    this_player()->start_more("", msg,0 );
    return 1;
}

int do_dengji(string arg)
{
    object me = this_player();

    if( me->query( "huanjing2003/together_id" ) )
        return notify_fail("你已经登记过你的相互ID了，请输入 <checkme> 指令查看。\n如需更改，请以 <mto> 指令发送信件，联系巫师奈何(naihe)。\n");
    if(!arg) return notify_fail("你还未登记你的相互ID，请输入一个ID。请注意，登记后，你不能再次更改这个ID。\n如有不明白之处，请输入 <help here> 查询。\n");
    if( arg == me->query("id") ) return notify_fail("不必登记自己，可直接转让。\n");

    me->set("huanjing2003/together_id", arg );

    write("登记成功！如果 \""+arg+"\" 未登记你的这个ID，请登记它，否则无法相互转让。\n");
    return 1;
}

int do_take( string arg )
{
    object me = this_player();
    int amount;
    string type;

    if(!arg) return notify_fail("指令的正确格式请输入 <look> 查看。\n");

    if( sscanf(arg, "exp %d", amount) )
        type = "exp";
    if( type != "exp" && sscanf(arg, "pot %d", amount) )
        type = "pot";

    if( type != "exp" && type != "pot" )
        return notify_fail("指令的正确格式请输入 <look> 查看。\n");

    if(amount < 1 || !me->query("huanjing2003/" + type )
      || me->query("huanjing2003/" + type ) < amount )
        return notify_fail("你没有足够的 "+type+" 可以兑现或数值不正确。请输入<checkme>查询。\n");

    if( type == "exp" )
    {
        if( amount < 1000 )
            return notify_fail("EXP 兑现，每次至少 1000 点。\n");
        me->add("huanjing2003/exp",-amount);
        me->add("combat_exp",amount);
    }
    if( type == "pot" )
    {
        if( amount < 500 )
            return notify_fail("POT 的兑现，每次至少 500 点。\n");
        me->add("huanjing2003/pot", -amount);
        me->add("potential", amount);
    }

    message_vision( sprintf("$N将 %d 点幻境游戏奖励的 %s 兑现成了MUD里的 %s 。\n", amount, type, type), me );

    hj_log_file( sprintf("\n%s(%s)兑现了 %d 点幻境 %s 。(%s)\n",
        me->query("name"), getuid(me), amount, type, ctime_format() ));
    return 1;
}


int do_zhuan(string arg)
{
    object me=this_player(),target;
    int amount;
    string target_id, type = ".";

    // 无论格式正确与否，先给提示。
    target_id = me->query("huanjing2003/together_id");
    if( !target_id ) return notify_fail("你并未登记你的相互ID！\n");

    target = find_player( target_id );
    if( !target )
        return notify_fail("你所登记的ID \""+target_id+"\" 并不在线，不能转让。\n");
    if( target->query("huanjing2003/together_id") != getuid(me) )
        return notify_fail("你所登记的ID \""+target_id+"\" ，对方并没有登记你的ID，不能转让。\n");

    // ok.
    if(!arg) return notify_fail("指令的正确格式请输入 <look> 查看。\n");

    if( sscanf(arg, "exp %d", amount) )
        type = "exp";
    if( type != "exp" && sscanf(arg, "pot %d", amount) )
        type = "pot";

    if( type != "exp" && type != "pot" )
        return notify_fail("指令的正确格式请输入 <look> 查看。\n");

    if(amount < 1 || !me->query("huanjing2003/" + type )
      || me->query("huanjing2003/" + type ) < amount )
        return notify_fail("你没有足够的 "+type+" 可以转让或数值不正确。请输入<checkme>查询。\n");

    if( type == "exp" )
    {
        if( amount < 1000 )
            return notify_fail("EXP 的转让每次至少 1000 点。\n");
        me->add("huanjing2003/exp",-amount);
        target->add("combat_exp",amount);
    }
    if( type == "pot" )
    {
        if( amount < 500 )
            return notify_fail("POT 的转让每次至少 500 点。\n");
        me->add("huanjing2003/pot", -amount);
        target->add("potential", amount);
    }

    message_vision( sprintf("$N将 %d 点幻境游戏奖励的 %s 转给了$n。\n",amount,type ),
        me, target );

    hj_log_file( sprintf("\n%s(%s)转让 %d 点幻境 %s 予 %s(%s) 。(%s)\n",
        me->query("name"), getuid(me), amount, type,
        target->query("name"),getuid(target),ctime_format() ));

    return 1;
}


int do_checkme()
{
    object me=this_player();

    if( me->query("huanjing2003/exp") > 0 )
        write(HIY"你有 "+me->query("huanjing2003/exp")+" 点在本游戏里获得的经验值。\n"NOR);
    else write(HIY"你没有在本游戏里获得的经验值。\n"NOR);

    if( me->query("huanjing2003/pot") > 0 )
        write(HIY"你有 "+me->query("huanjing2003/pot")+" 点在本游戏里获得的潜能值。\n"NOR);
    else write(HIY"你没有在本游戏里获得的潜能值。\n"NOR);

    write("你可以直接把它们兑换成你的经验值或潜能值；或者把它们转给你所登记的相互ID。\n");

    if( me->query("huanjing2003/together_id") )
        write("你登记的相互ID是：\""+me->query("huanjing2003/together_id")+"\"\n");
    else write("你还未登记相互ID，不能转让这些得分。需要转让时，请先登记。\n");

    return 1;
}

