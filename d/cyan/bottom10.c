// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", WHT"浓雾之中"NOR);
    set("long", @LONG
除了雾，还是雾。侧耳倾听，附近死一般的寂静，没有一丝鸟啼虫鸣，
回响着的只有你的脚步；举目四顾，周围是白茫茫的一片，近在咫尺的景物
都不能看得清楚，只能如盲人一般，慢慢地在身边流动的冷雾中向前摸索，
难知身在何处。
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"east" : __DIR__"bottom11",
  		"west" : __DIR__"bottom4",
	]) );

	set("coor/x",-30);
	set("coor/y",30);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	tell_object(me,CYN"你浑身戒备，小心翼翼地向雾气中走去．．．\n"NOR);
	me->perform_busy(1);
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


