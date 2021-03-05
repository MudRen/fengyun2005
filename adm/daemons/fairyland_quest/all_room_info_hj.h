//                标准描述长度示例                                   |

void delete_exit();
void back_exit();
void add_exit();
void back_exit2();
void full_all( object me );

string the_exit;
string the_exit2;

#include    "npc_obj/hj_settings/room_amount_hj.h"


void create()
{
    set("room_mark",mark);
    set("short",MAG"幻境"NOR+GRN"·迷失之宝物隐匿之林"NOR);

    set("long","这里是一片望不到边的密林，气息却很是古怪。周围的树木都高大粗壮、枝
藤纠结，你见不到日月光亮，周围也悄无声息。脚下的土地上树木的根须蔓延纠
缠，你好不容易才勉强踏得几条小径往四处通去。\n");

    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
    set("invalid_startroom",1);
    set("no_fly", "1");

// 下面是对应的出口。

    set("exits",([
        "east":__DIR__"hj_room"+( mark +1),
        "west":__DIR__"hj_room"+( mark -1),
        "south":__DIR__"hj_room"+( mark +10),
        "north":__DIR__"hj_room"+( mark -10),
        "northeast":__DIR__"hj_room"+( mark -9),
        "northwest":__DIR__"hj_room"+( mark -11),
        "southeast":__DIR__"hj_room"+( mark +11),
        "southwest":__DIR__"hj_room"+( mark +9),
    ]));

    if( mark <= 10 ) // 方阵型房间，最上面一横无 北向 方向
    {
        if(query("exits/north")) delete("exits/north");
        if(query("exits/northeast")) delete("exits/northeast");
        if(query("exits/northwest")) delete("exits/northwest");
    }

    if( (mark % 10) == 1 ) // 方阵型房间，最左边一竖无 西向 方向
    {
        if(query("exits/west")) delete("exits/west");
        if(query("exits/southwest")) delete("exits/southwest");
        if(query("exits/northwest")) delete("exits/northwest");
    }

    if( (mark % 10) == 0 ) // 方阵型房间，最右边一竖无 东向 方向
    {
        if(query("exits/east")) delete("exits/east");
        if(query("exits/southeast")) delete("exits/southeast");
        if(query("exits/northeast")) delete("exits/northeast");
    }

    if( mark >= (HJ_ROOM_AMOUNT - 9) ) // 方阵型房间，最下面一横无 南向 方向
    {
        if(query("exits/south")) delete("exits/south");
        if(query("exits/southeast")) delete("exits/southeast");
        if(query("exits/southwest")) delete("exits/southwest");
    }

// 总共的房间数必须是整十数。

    set("all_exit","ok");


// 西北方即 1 号房间，有特殊文件支持
// 其余各点如下：

// 第一横最后一个房间加入支持铸剑指令的NPC，即右上角（东北方）
    if( mark == 10 )
        set("objects", ([ __DIR__"npc_obj/hj_npc_zhujian" : 1 ]));

// 最后一横第一个房间加入支持炼魔指令的NPC，即左下角（西南方）
    if( mark == HJ_ROOM_AMOUNT - 9 )
        set("objects", ([ __DIR__"npc_obj/hj_npc_lianmo" : 1 ]));

// 最后一个号码的房间加入支持交易指令的 NPC，即右下角（东南方）
    if( mark == HJ_ROOM_AMOUNT )
        set("objects", ([ __DIR__"npc_obj/hj_npc_trader" : 1 ]));

    setup();
}


void init()
{
// 所有的共有动作(即 all_room_info_hj.h 及 1_room_info_special.h 共有)
#include "all_common_init.h"

    if( this_object()->query("all_exit") == "ok" )
    {
        if( !random(3) ) delete_exit();
        else if( !random(2) ) add_exit();
    }
}

// 所有的共有函数(即 all_room_info_hj.h 及 1_room_info_special.h 共有)
#include "all_common_func.h"


void delete_exit()
{
    string *the_exits;

    if( query("all_exit") != "ok" ) return;


    the_exits = ({    "east", "west", "north", "south",
        "northeast", "northwest", "southeast", "southwest", });

    the_exit = the_exits[ random(8) ];

    if( query("exits/"+ the_exit) )
        delete( "exits/" + the_exit );
    else the_exit = "none";

    if(the_exit != "none")
    {
        set("all_exit","be_delete");
        if(random(3) == 1) message("vision",HIB"你似乎看到几棵树木的位置移动了一下！……\n"NOR,this_object());
        remove_call_out("back_exit");
        call_out("back_exit",30+random(90));
    }
}

void back_exit()
{
    int temp;
    mapping the_marks;

    if( query("all_exit") == "ok" || query("all_exit") != "be_delete" )
        return;

    temp = mark;

    the_marks = ([
        "east"        : temp + 1,
        "west"        : temp - 1,
        "south"        : temp + 10,
        "north"        : temp - 10,
        "northeast"    : temp - 9,
        "northwest"    : temp - 11,
        "southeast"    : temp + 11,
        "southwest"    : temp + 9,
    ]);

    if( !undefinedp( the_marks[ the_exit ] ) )
        set( "exits/" + the_exit , __DIR__"hj_room" + the_marks[ the_exit ] );

    if(random(3) == 1) message("vision",HIB"你似乎看到几棵树木的位置移动了一下！……\n"NOR,this_object());
    set("all_exit","ok");
}

void add_exit()
{
    string temp_add_exit, *the_exits;

    if( query("all_exit") != "ok" ) return;

    the_exits = ({    "east", "west", "north", "south",
        "northeast", "northwest", "southeast", "southwest", });


    the_exit2 = the_exits[ random(8) ];
    temp_add_exit=__DIR__"hj_room"+(1+random( HJ_ROOM_AMOUNT ));

    if( !query("exits/"+ the_exit2) )
        set( "exits/"+ the_exit2, temp_add_exit );
    else the_exit2 = "none";

    if( the_exit2 != "none" )
    {
        set("all_exit","be_add");
        if(random(3) == 1) message("vision",HIB"你似乎看到几棵树木的位置移动了一下！……\n"NOR,this_object());
        remove_call_out("back_exit2");
        call_out("back_exit2",30+random(90));
    }
}

void back_exit2()
{
    if( query("all_exit") == "ok" || query("all_exit") != "be_add" )
        return;

    delete( "exits/" + the_exit2 );

    if(random(3) == 1) message("vision",HIB"你似乎看到几棵树木的位置移动了一下！……\n"NOR,this_object());
    set("all_exit","ok");
}

