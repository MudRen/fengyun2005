//                标准描述长度示例                                   |
// 玩家与幻境之启动房间 之进入间
// 所有售票、检票等相关工作在此进行，符合条件的玩家，将可以转移至下一个通道房间内。
// by naihe  2002-11-03  于茂名

// 已经改变了许多许多许多了……
// naihe 17:07 03-11-1 

#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
#include <ctime_format_func.h>

// 该文件定义游戏地图大小
#include "npc_obj/hj_settings/room_amount_hj.h"
// 该文件定义游戏版本号  HJ2003_VERSION
#include "npc_obj/hj_settings/game_version.h"

// ##################################
// ##########  一些宏定义 ###########
// ##################################
#define        HJ_DOOR_DATA    "/data/huanjing/door_data"
// 储存资料的文件名
#define        HJ_ROOM_CREATE_D    "/adm/daemons/hj_room_created"
// 该文件拥有足够权限进行写文件的操作。

#ifndef        HJ_DIR
#define        HJ_DIR        __DIR__
#endif


////////////////////////////////////////////////////
//// 以下数值可以指令 (mewiz) 更改，并自动储存 /////
////////////////////////////////////////////////////

int GAME_OPEN = 1;
// 本游戏是否开放。 1开放，0关闭
// 关闭时，任何人不得进入（巫师进入了也无法游戏）
// 可以用 mewiz 指令更改值，重启动后亦不会恢复！

int FREE_GAME = 0;
// 免费游戏， 1 开放，0关闭
// 本设置必须在 GAME_OPEN 为开放状态时才有效。
// 说明同上

int MAX_HJ_ENTER = 10;
// 最大场内人数。超过此人数时，玩家不得继续进入游戏。

int MP_GOLD = 20;
// 门票价格（黄金），使用钱庄转帐

int MSG_GOLD = 5;
// 信息价格，使用钱庄转帐

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////

// ##################################
// ##########  各类统计  ############
// ##################################

// 进入人次，收入情况
int in_times, max_in_hj, in_money, buy_piao_times, buy_sm_times, buy_msg_times;

mapping player_level_info = ([ ]);

// ##################################
// ##################################


string look_ban();
string look_pai();
string del_player_level( string id );
void lucky( object me );

string query_save_file()
{
    return HJ_DOOR_DATA;
}

// 这个方法使被房间记录的数据不被清除。至于非本房间所属NPC、物品，若想不被更新，则需要再其上设置 no_refresh 标记
void reset()
{
    ::reset();
    set("no_clean_up", 1);
    set("no_magic", 1);
    set("no_fly",1);
}

// 设置这里的随机颜色地点名
void hjset_short()
{
    string *color, cl1, cl2, cl3, cl4, cl5, cl6, cl7;
    int size;

    color = ({ HIY, HIR, HIB, HIG, HIC, HIW, HIM });

    // 随机去掉4个颜色，那么7个字相同颜色的概率就大了很多很多
    if( !random(5) )
    {
        size = 4;
        while( size-- ) color -= ({ color[ random( sizeof(color) ) ] });
    }

    size = sizeof( color );
    cl1 = color[ random(size) ];
    cl2 = color[ random(size) ];
    cl3 = color[ random(size) ];
    cl4 = color[ random(size) ];
    cl5 = color[ random(size) ];
    cl6 = color[ random(size) ];
    cl7 = color[ random(size) ];

    set("color_short_hj",cl1+"遥"+cl2+"远"+cl3+"传"+cl4+"说"+cl5+"之"+cl6+"起"+cl7+"缘"NOR);
    set("short", MAG"幻境2003 "+HJ2003_VERSION+NOR );

    if( cl1 == cl2 && cl1 == cl3 && cl1 == cl4 && cl1 == cl5 && cl1 == cl6 && cl1 == cl7 )
        set("same_color", 1);
    else set("same_color", 0);
}

mapping who_in_hj()
{
    object rooms, *in_env;
    int i,j,amount;
    string msg, *all_ip=({});

    msg = "";
    // 包括正待进入的两个地点
    rooms = find_object( __DIR__"room_master_hj");
    if( rooms )
    {
        in_env = all_inventory( rooms );
        if( in_env && sizeof(in_env) )
        {
            for( j=0;j<sizeof(in_env);j++ )
            {
                if( userp(in_env[j]) )
                {
                    amount++;
                    msg += sprintf( "%s\n",
                        in_env[j]->short());
                    all_ip += ({ query_ip_name( in_env[j] ) });
                }
            }
        }
    }

    rooms = find_object( __DIR__"room_readygo_hj");
    if( rooms )
    {
        in_env = all_inventory( rooms );
        if( in_env && sizeof(in_env) )
        {
            for( j=0;j<sizeof(in_env);j++ )
            {
                if( userp(in_env[j]) )
                {
                    amount++;
                    msg += sprintf( "%s\n",
                        in_env[j]->short());
                    all_ip += ({ query_ip_name( in_env[j] ) });
                }
            }
        }
    }

    // 密林内玩家
    for( i=1;i<=HJ_ROOM_AMOUNT;i++ )
    {
        rooms = find_object( __DIR__"hj_room"+i );
        if( !rooms ) continue;
        in_env = all_inventory( rooms );
        if( !in_env || !sizeof(in_env) ) continue;
        for( j=0;j<sizeof(in_env);j++ )
        {
            if( userp(in_env[j]) )
            {
                amount++;
                msg += sprintf( "%s\n",
                    in_env[j]->short());
                all_ip += ({ query_ip_name( in_env[j] ) });
            }
        }
    }

    if( !amount ) msg = "幻境内现在没有任何玩家。\n";
    else  msg = "包括正待进入的以及幻境密林内，现在共有"+chinese_number( amount )+"位玩家：\n" + msg;

    if( amount > max_in_hj )
    {
        max_in_hj = amount;
        save();
    }

    set( "all_ip_in_hj", all_ip );
    return ([ "amount": amount, "info": msg ]);
}


// 奈何按：门口的效果写了2个小时！单单是描述的几句文字，大小地方
//         改了8次，嘿。
void hjset_long()
{
    mapping temp;
    string temp_str, longs;

    if( !GAME_OPEN ) temp_str = HIR"     (游戏关闭)"NOR;
    else if( FREE_GAME )
        temp_str = sprintf( HIC"(免费开放·场内%2d人)"NOR,
                who_in_hj()["amount"] );
    else temp_str = sprintf( HIG"(正常开放·场内%2d人)"NOR,
                who_in_hj()["amount"] );

    longs= "\n        　 "HIW"╭──────────────────────╮     
           "NOR+WHT"╰╮   "NOR+WHT"幻境 · "+query("color_short_hj")+NOR+WHT" · 幽灵显现"NOR+WHT"   ╭╯     
           "NOR+HIW"╭╯            "NOR+WHT"BY naihe 2003.10"NOR+HIW"            ╰╮     
           "NOR+WHT"╰──────────────────────╯     "NOR"
                         "+temp_str+"

    你踏进了一处幽暗的所在，四周似有隐约光亮，却又无法觅其源头。一块
  巨大的木板(ban)飘忽地于你身前不远之处隐现，巨板下带着一块小木牌(pai)。
这里便是传说中的“幻境”与现实之间的接口，由此而进，你将随之步入那神秘的
                          幻境之地，不复存在……

    ----------------------------------------------------------------\n";

    // 格式
    //    set("player_msg3", ([ "id": "12345678", "time":"03.10.24", "msg":"啦啦" ]) );
    if( query("player_msg1") )
    {
        temp = query("player_msg1");
        longs += sprintf("    【 %-8s 发布消息(%8s):%-32s】\n", 
            temp[ "id" ], temp[ "time" ], temp["msg"] );
    }
    if( query("player_msg2") )
    {
        temp = query("player_msg2");
        longs += sprintf("    【 %-8s 发布消息(%8s):%-32s】\n", 
            temp[ "id" ], temp[ "time" ], temp[ "msg" ] );
    }
    if( query("player_msg3") )
    {
        temp = query("player_msg3");
        longs += sprintf("    【 %-8s 发布消息(%8s):%-32s】\n", 
            temp[ "id" ], temp[ "time" ], temp[ "msg" ] );
    }

    if( !query("player_msg1") && !query("player_msg2") && !query("player_msg3") )
        longs += sprintf("             【 %s 】\n", "现在没有玩家发布信息 (指令：hjmsg 内容)");

    set( "long", longs + 
"    ----------------------------------------------------------------\n" );
}

void create()
{
    restore();
    // 载入历史统计
    if( !query("begin_time") )
        set("begin_time", time() );

    hjset_short();
    hjset_long();

    // 这是个长期公布的信息
    if( random(3) )
        set("player_msg1", ([ "id": "naihe", "time":"03.10.24",
            "msg":"最佳字体：宋体小四(12)或小五(10)" ]) );

    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("valid_startroom", 1);

    set("item_desc",([
        "ban": (: look_ban :),
        "pai": (: look_pai :),
    ]));

    set("exits", ([
        "down":"/d/fy/fqkhotel",  // 扬州中央广场使用 jump 指令进入。
        "enter":__DIR__"room_master_hj",
        "up":__DIR__"room_cession_hj",
        ]));

// 附： cs 代码：
/*
void init()
{
    add_action("do_enter_hj", "jump");
}

int do_enter_hj(string arg)
{
    object rooms, me=this_player();
    if( !arg || arg != "up" ) return 0;

    rooms = find_object( "/adm/daemons/huanjing2003/room_door_hj" );
    if( !rooms ) rooms = load_object( "/adm/daemons/huanjing2003/room_door_hj" );
    if( !rooms ) return 0;

    tell_room( environment(me), me->query("name")+"使劲地往上一跳，突然卷来一阵旋风，"+me->query("name")+"顿时被风刮得不知所踪。\n", me);
    me->move(rooms);
    write("你使劲地往上一跳，忽地平地卷起一阵旋风，恍惚中你已来到了「幻境」。\n");
    tell_room( rooms, "忽然一阵旋风袭过，"+me->query("name")+"已出现在这里。\n", me );
    return 1;
}
*/

    setup();
}

void init()
{
    object me = this_player();
    
    if( !userp(me) || !living(me) )
        return;
    me->delete_temp( "hj2003-valid_enter" );
    if( me->query_temp( "hj_apply_short" ) )
    {
        me->delete_temp( "hj_apply_short" );
        me->delete_temp( "apply/short" );
    }
    if( wizardp(me) )
    {
        add_action("do_mewiz","mewiz");
        add_action("do_create_room_file", "create_room_file");
    }
    add_action("do_maipiao","maipiao");
    add_action("do_goumai","goumai");
    add_action("do_msg", "hjmsg");
    add_action("do_top", "top");
    add_action("do_huanjing", "huanjing");
    add_action("do_who_in_hj", "gwho");
    add_action("do_look", "look");

    if( !me->query("huanjing2003")
      || !mapp(me->query("huanjing2003"))
    )
    {
        me->delete("huanjing2003");
        me->set("huanjing2003/welcome_to_hj_time", ctime_format() );
    }

    // 这两句是删除以前的版本时，给玩家添加的信息的。
    me->delete("aaaaa_hj_award");
    me->delete("aaaaa_hj_gift");

    // 删除非法的 level 。
    if( me->query("huanjing2003/lv") && undefinedp( player_level_info[getuid(me)] ) )
    {
        me->delete("huanjing2003/lv");
        me->save();
        call_out( "xxxxx", 1, me );
    }
    hjset_short();
    hjset_long();
    if( query("same_color") )
    {
        me->start_busy(5);
        lucky( me );
    }
}

void xxxxx( object me )
{
    if( !me ) return;
    message_vision( "$N只觉得身体发生了一些变化，$N的“幻境”等级被删除了……请联系幻境巫师。\n", me);
}


void lucky( object me )
{
    if(!me || !environment(me) || environment(me) != this_object() ) return;

    message_vision("
$N刚走过来，突然一阵轰动之声大作，只见旁边冲出来几个怪模怪样的人！
其中一个样貌古怪的女子说对着$N说道：“恭喜恭喜！幻境正在发放特别奖励，你是这次的幸运者！”
另外一个比较像正常人的男子接着说道：“你若要进入幻境的话，将获得特别的奖励！”
只见他手一挥似的动作，$N觉得微微一震，就像被什么东西轻轻碰撞了一下一般！
这几个人忽来忽去，说话间竟然就此退下，往里面进去了。\n\n",me);
    me->set("huanjing2003/gift","幸运");
    me->save();
}

int do_look(string arg)
{
    if( !arg ) hjset_long();
    return 0;
}

string look_pai()
{
    return "#################################################################################
本游戏需要买票进入，除非游戏免费开放。价格 "+HIR+MP_GOLD+NOR" GOLD，指令："HIY"(maipiao)"NOR"
常年发售游戏说明手册，价格 "HIR"1"NOR" GOLD。指令： "HIY"(goumai shuoming)"NOR"
玩家可以发布信息，价格 "+HIR+MSG_GOLD+NOR" GOLD。指令："HIY"(hjmsg)"NOR"
玩家可以查询谁在幻境游戏里，指令："HIY"(gwho)"NOR"
幻境游戏相关公告及资讯，指令："HIY"(huanjing list)"NOR"
#################################################################################\n";
}

int do_who_in_hj()
{
    write( who_in_hj()[ "info" ] );
    return 1;
}

int do_huanjing( string arg )
{
    string *dirs, msg;
    int i;

    if( !arg ) return notify_fail("这个指令可以让你查看幻境游戏的一些公告和其他信息。\n请输入 (huanjing list) 指令查看列表。\n");

    if( arg == "list" )
    {
        dirs = get_dir( __DIR__"other_info/" );
        if( !dirs || sizeof( dirs ) < 1 )
            return notify_fail("现在没有任何记录。\n");
        msg = "============= 下面是幻境游戏的公告及信息记录：=============\n\n";

        for( i=0; i<sizeof( dirs ); i++ )
        {
            msg += sprintf( "『幻境游戏活动记录』  --  %s\n",
                replace_string( dirs[i], ".naihe", "" ) );
        }

        msg += "\n========== 请以指令 (huanjing 记录名) 查看内容 ===========\n";
        this_player()->start_more("", msg,0 );
        return 1;
    }

    if( file_size( __DIR__"other_info/"+ arg +".naihe" ) < 1 )
        return notify_fail("无该记录或该记录无内容。\n");

    msg = read_file( __DIR__"other_info/"+ arg + ".naihe" );
    if( !msg ) return notify_fail("无法读取该记录内容。\n");

    msg = "============== "+arg+ " 内容全文 ==============\n\n"+ msg + "\n\n===================================================\n";
    this_player()->start_more("", msg,0 );
    return 1;
}


int do_goumai(string arg)
{
    object me=this_player(),gold;

    // 已删除此物件
    return notify_fail("请直接输入 help hj2003 查询游戏说明。\n");

    if(!arg || arg!="shuoming")
        return notify_fail("购买游戏说明手册，价格1 GOLD，指令 <goumai shuoming> 。\n");

    gold = present("gold_money",me);
    if(!gold) return notify_fail("你身上没有黄金。\n");
    gold->add_amount(-1);
    new(__DIR__"other_obj/obj_shows")->move(me);
    message_vision("$N掏出一两黄金，买下了一本游戏说明手册。\n",me);
    in_money ++;
    buy_sm_times ++;
    save();
    return 1;
}

string look_ban()
{
    object out_room;

    write("
       ┏━━━━━━━━━━━━━━━━┓
       ┃ "WHT"幻境·"+query("color_short_hj")+NOR+WHT"·幽灵显现"NOR" ┃
       ┗━━━━━━━━━━━━━━━━┛
");

    out_room = find_object( __DIR__"room_gameover_hj" );
    if( !out_room ) out_room = load_object( __DIR__"room_gameover_hj" );
    if( out_room ) write( out_room->get_TOP_pic()+"\n"NOR);

    if(wizardp(this_player()))
        write("\n你是巫师，可使用 <mewiz> 指令。具体请查询 <mewiz> 。");

    return "\n";
}

int do_top(string arg)
{
    if( !arg || (arg != "hj" && arg != "huanjing") )
        return 0;

    write("大木板上正写着最高成绩记录呢。\n");
    return 1;
}

int do_msg( string arg )
{
    object me = this_player();
    string time;

    if( !arg ) return notify_fail("<hjmsg> 指令可以让你在幻境入口处发布信息。
每次发布信息需要 "HIR+MSG_GOLD+" 两黄金 "NOR"，在钱庄自动转帐。
你只能发布长度不超过16个汉字的信息。
你发布的信息可能会被系统在任何时候清理，或者被其他人新发布的信息所清理。
指令格式： msg 内容\n");

    if( strlen( arg ) > 16 )
        return notify_fail("你只能发布长度最多为16个汉字的信息。\n");

    if( arg == "clean" && wizardp(me) )
    {
        message_vision("$N把正在发布的信息都清除了。\n",me);
        delete("player_msg1");
        delete("player_msg2");
        delete("player_msg3");
        hjset_long();
        save();
        return 1;
    }

    if( me->query("deposit") < MSG_GOLD * 10000 )
        return notify_fail("你的钱庄存款不够，无法发布信息。\n");

    // OK,发表。

    me->add("deposit", - MSG_GOLD*10000 );

    if( query("player_msg2") )
        set( "player_msg1", query("player_msg2") );
    if( query("player_msg3") )
        set( "player_msg2", query("player_msg3") );

    time = ctime_format( "Y.M.D" );
    set( "player_msg3", ([ "id": me->query("id") , "time": time, "msg": arg ]) );
    hjset_long();
    message_vision("$N支付了"+chinese_number(MSG_GOLD)+"两黄金，发布了一则短消息。\n",me);

    in_money += MSG_GOLD;
    buy_msg_times ++;

    save();
    return 1;
}

int do_mewiz(string arg)
{
    int temp, time, i;
    object ts;
    string msg, *key;
    mixed ppp;

    if(!wizardp(this_player())) return 0;

    if(!arg) return notify_fail(
"可操作参数如下(例如 <mewiz open 1>：
open 1          --> 游戏启动
open 0          --> 游戏关闭
free 1          --> 允许免费游戏
free 0          --> 关闭免费游戏
mpgold 数量     --> 门票价格(黄金)
msggold 数量    --> 公布信息价格(黄金)
maxenter 数量   --> 最大进场人数，场内玩家到达此数量时，不再放人进场
ts              --> 领取巫师专用的 幻境工具
ck              --> 查询当前游戏的所有设置状态
cklevel         --> 查询所有幻境玩家的 level 状态
dellv ID        --> 清除某玩家在这里的 level 记录(并不清除其实际有效 level)\n");

    if( arg == "ts" )
    {
        ts = new( __DIR__"npc_obj/hj_wiztools" );
        ts->move(this_player());
        write("OK，已取得一个 幻境巫师工具。\n");
        return 1;
    }

    if( arg == "cklevel" )
    {
        if( !player_level_info || !sizeof(player_level_info) )
            return notify_fail("现在还没有任何玩家的 level 记录。\n");

        key = keys( player_level_info );
        msg = "共有 "+sizeof(key)+" 个记录。详细资料如下：\n\n";
        for( i=0;i<sizeof(key);i++ )
        {
            ppp = player_level_info[ key[i] ];
            if( !mapp(ppp) ) continue;
            time ++;
            msg += sprintf( "%s(%s)  LV %d    (%s)\n",
                ppp["name"], key[i], ppp["lv"], ctime_format( ppp["time"] ) );
        }
        msg += "\n有效记录共 "+time+" 个。\n";
        this_player()->start_more("", msg,0 );
        return 1;
    }

    if( sscanf( arg, "dellv %s", msg ) )
    {
        if( getuid( this_player() ) != "debug" )
            return notify_fail("本指令只能由奈何执行。\n");
        write( del_player_level( msg ) );
        return 1;
    }

    if(arg == "ck")
    {
        time = query("begin_time");
        temp = time() - time;

        msg = sprintf("
************************************************************
%s         最大入场人数限制：%d
%s
系统启动于：%s 。
现在是：    %s 。

    "HIY"至今已过了 %d 天 %d 小时 %d 分钟 %d 秒"NOR"

总入场人次(包括巫师)："HIG"%-10d"NOR" 最大同时在场："HIC"%d"NOR"
    (平均每 %d 天 %d 小时 %d 分 %d 秒进场一人次)
总收入："HIY"%d"NOR" 黄金 (售票 %d 张，发布信息 %d 次，售出说明 %d 本)
(门票 %d GOLD / 张，说明 1 GOLD / 本，发布信息 %d GOLD / 次)
************************************************************\n",
            GAME_OPEN ? HIG"主游戏  -->启动中"NOR : HIR"主游戏  -->关闭中"NOR,
            MAX_HJ_ENTER,
            FREE_GAME ? HIY"现在是免费游戏。"NOR : HIG"现在是正常游戏，非免费。"NOR, 
            ctime_format( time ), ctime_format(), 
            temp / 86400, (temp % 86400) / 3600,
            (temp % 86400 % 3600) / 60, temp % 86400 % 3600 % 60,
            in_times, max_in_hj,
            in_times ? (temp / in_times) / 86400 : 0,
            in_times ? ((temp / in_times) % 86400) / 3600 : 0,
            in_times ? ((temp / in_times) % 86400 % 3600) / 60 : 0,
            in_times ? ((temp / in_times) % 86400 % 3600) % 60 : 0,
            in_money, buy_piao_times, buy_msg_times, buy_sm_times,
            MP_GOLD, MSG_GOLD );
        write( msg );
        return 1;
    }

    if( sscanf(arg, "open %d", temp) )
    {
        if(temp!= 1 && temp!=0) return notify_fail("只能设置 1 或 0 来开启/关闭游戏。\n");

        GAME_OPEN = temp;
        write("设置成功。请用 <mewiz ck> 指令查询当前状态。\n");
        hjset_long();
        save();
        return 1;
    }

    if( sscanf(arg, "free %d", temp) )
    {
        if(temp!= 1 && temp!=0) return notify_fail("只能设置 1 或 0 来开启/关闭免费游戏。\n");

        FREE_GAME = temp;
        write("设置成功。请用 <mewiz ck> 指令查询当前状态。\n");
        hjset_long();
        save();
        return 1;
    }

    if( sscanf( arg, "mpgold %d", temp ) )
    {
        if( temp< 1 || temp > 1000 ) return notify_fail("设置门票价格，范围 1-1000 黄金。\n");

        MP_GOLD = temp;
        write("设置成功。请用 <mewiz ck> 指令查询当前状态。\n");
        hjset_long();
        save();
        return 1;
    }

    if( sscanf( arg, "msggold %d", temp ) )
    {
        if( temp< 1 || temp > 1000 ) return notify_fail("设置发布信息价格，范围 1-1000 黄金。\n");

        MSG_GOLD = temp;
        write("设置成功。请用 <mewiz ck> 指令查询当前状态。\n");
        hjset_long();
        save();
        return 1;
    }

    if( sscanf( arg, "maxenter %d", temp ) )
    {
        if( temp< 1 || temp > 100 ) return notify_fail("设置最大进场人数，范围 1-100 。\n");

        MAX_HJ_ENTER = temp;
        write("设置成功。请用 <mewiz ck> 指令查询当前状态。\n");
        hjset_long();
        save();
        return 1;
    }

    write("格式有误。请直接输入 <mewiz> 指令查询正确用法。\n");
    return 1;
}


int do_maipiao( )
{
    object me=this_player(),piao,gold;

    if( me->query("deposit") < MP_GOLD * 10000 )
        return notify_fail("你的钱庄存款不足以购买一张门票。门票价格是 "+MP_GOLD+" 两黄金。\n");

    piao = new(__DIR__"other_obj/obj_menpiao");
    me->add("deposit", - MP_GOLD*10000);
    piao->move(me);
    message_vision("$N支付了"+chinese_number(MP_GOLD)+"两黄金，买下了一张门票。\n",me);

    in_money += MP_GOLD;
    buy_piao_times ++;

    save();
    return 1;
}

int do_create_room_file()
{
    object me = this_player();
    int last_num;

    if( !wizardp(me) || getuid(me) != "debug" )
        return notify_fail("本指令只能由 奈何 执行。\n");

    if( me->query_temp("hj_create_room") != 1 )
    {
        me->set_temp("hj_create_room", 1);
        return notify_fail("本指令将直接建立 .c 文件！它将建立文件名为：\n "+
__DIR__ + "hj_room1.c  至 "+ __DIR__ + "hj_room"+ HJ_ROOM_AMOUNT+ ".c 
共 "+HJ_ROOM_AMOUNT +" 个文件！你如果确定，请再次输入本指令。\n");
    }

    me->delete_temp("hj_create_room");

    if( file_size( HJ_ROOM_CREATE_D +".c" ) < 0 )
        return notify_fail("无法找到 "+ HJ_ROOM_CREATE_D+" 文件。\n");

    last_num = HJ_ROOM_AMOUNT;
    write( HJ_ROOM_CREATE_D->create_room( me, __DIR__, last_num ) );
    return 1;
}


int valid_leave(object me, string dir)
{
    object menpiao;
    mapping conditions;
    
    if( dir != "enter" )
        return ::valid_leave(me,dir);
    if( !userp(me) )
        return notify_fail("猪头不得进入！！！\n");
    // 气死我了，居然有一堆NPC走了进去
    //     if( wizardp(me) ) return ::valid_leave(me,dir);
    // 巫师亦不能免费。
    if(GAME_OPEN != 1) return notify_fail("游戏并未开放。\n");
    if( me->query("scheming") )
        return notify_fail("正在执行离线计划者不得入内。\n");
    if( !interactive(me) )
        return notify_fail("断线者不得入内。\n");
    // 检测玩家状态
    conditions = me->query_all_condition();
    if( conditions && sizeof( conditions ) > 0 )
        return notify_fail("你现在身体状况不正常或你设置开启了门派任务，请关闭门派任务(family_job)或稍后再试。\n");
    // 查看场内情况
    if( who_in_hj()[ "amount" ] >= MAX_HJ_ENTER )
        return notify_fail("现在已经有太多人在幻境里了，请稍候再尝试进入。\n");
    if( query("all_ip_in_hj") && sizeof( query("all_ip_in_hj") )
      && member_array( query_ip_name(me), query("all_ip_in_hj") ) != -1
    )
        return notify_fail("幻境里已经有与你同IP的玩家了，同一IP只能进入一个玩家。\n");
    if( FREE_GAME == 1 )
    {
        in_times++;
        save();
        write("现在正进行免费游戏活动，谢谢参与游戏。\n");
    }
    else
    {
        menpiao = present("men piao",me);
        if(!menpiao || !menpiao->query("hj menpiao") )
            return notify_fail("请先购票，方可入内。请查看牌子上的说明。\n");
        destruct(menpiao);
        message_vision("$N掏出一张门票塞进门边的小盒子里，随即往里边走了进去。\n",me);
        in_times++;
        save();
    }
    me->set_temp("hj2003-valid_enter", 1);
    me->delete_temp( "hj2003-enter_timeout" );
    call_out("player_timeout", 180, me);
    return ::valid_leave(me, dir);
}

void player_timeout(object me)
{
    if( !me || !environment(me) || environment(me)->query("room_mark")
      || present("qixing deng",me ) || environment(me) == this_object()
      || strsrch( base_name( environment(me) ), "room_gameover_hj" ) != -1 )
        return;
    if( !me->query_temp( "hj2003-enter_timeout") )
    {
        me->set_temp( "hj2003-enter_timeout", 1);
        tell_object( me, HIR"\n游戏提示：请尽快进入游戏(xuanze 国度名，例如 xuanze feng)，否则将被踢出游戏！\n\n"NOR );
        call_out( "player_timeout", 180, me);
        return;
    }
    message_vision( "$N呆在这里太久了，忽然感到一阵震荡！\n",me);
    me->move( this_object() );
    message_vision( "$N被一阵莫名的震荡送到了这里。\n",me);
}

void save_player_level( string name, string id, int lv, int time )
{
    player_level_info[ id ] = ([ "name":name, "lv":lv, "time":time ]);
    save();
}

string del_player_level( string id )
{
    if( !id ) return "要清除哪一位玩家的 level 记录？\n";
    if( undefinedp( player_level_info[id] ) )
        return "没有这个玩家的 level 记录。\n";

    map_delete( player_level_info, id );
    save();
    return "该玩家的 level 记录已清除，其 level 记录将于下次进入本地时被清除。\n";
}
