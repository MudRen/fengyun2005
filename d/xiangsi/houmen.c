// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	object fishbone;
	set("short", "后山门");
        set("long", @LONG
飞廊的尽处是一圈红瓦白墙，白墙的一角堆积着成摞的木板，一扇不大的
木门开在墙上，半掩着墙外风光。回身后顾，这里已经是群峰中最高的一处山
头，皑皑的白雪所覆，在这四季如春的江南蔚为奇观。
LONG
        );
	set("objects", ([
		__DIR__"npc/leng2" : 1,
		__DIR__"obj/muban" : 1,
	]));
	set("exits",([
  		"east" : __DIR__"nanzoulang",
  		"northup" : __DIR__"huxian",
	]) );

	set("indoors", "xiangsi");

	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
    replace_program(ROOM);
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
