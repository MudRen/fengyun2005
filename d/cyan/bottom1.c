// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "古瞭望台下");
    set("long", @LONG
慢慢地醒转过来，仰头上望，只见断崖千许，直没入云雾之中。穿过了千
尺云天坠到这里，你竟然还活着，忍不住为自己暗自庆幸，这才四处打量。此
处是一个小小的低谷，三面背临山壁，谷中虬节着几棵的老松，有淡淡的雾气
徘徊低漾。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/pine2":1,
	]));
	set("no_fly",1);
	set("item_desc", ([

	"cliff":"仰头上望，只见断崖千许，直没入云雾之中。\n",
	"崖":"仰头上望，只见断崖千许，直没入云雾之中。\n",
	"断崖":"仰头上望，只见断崖千许，直没入云雾之中。\n",

	"山壁":"坚硬的灰色岩石所构成的山壁。\n",

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"east" : __DIR__"bottom2",
	]) );

	set("coor/x",-70);
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


