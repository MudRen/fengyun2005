// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "千方雾障");
    set("long", @LONG
走近此处，只见青山碧水全然隐去，层层叠叠的浓雾从四面八方集涌而
来，眨眼间就将你身边的世界吞没，视线可及之处，无不是一片茫茫雾气，
就连道路也消失在你的眼前。是进？是退？你止住脚步，四顾茫然。
LONG
    );
    set("objects", ([
	__DIR__"npc/gongsun" : 1,
      ]));
    set("exits",([
	"east" : __DIR__"liangjie",
	"west" : __DIR__"jieyu",
      ]) );
    
    set("outdoors", "xiangsi");
    
    set("coor/x",-5);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}

int	valid_leave(object who, string dir)
{
    tell_object(who,CYN"你左绕右绕，小心翼翼的穿过雾障前行。\n"NOR);
    if (userp(who))	who->perform_busy(1);
    return ::valid_leave(who,dir);
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

