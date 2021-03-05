// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit __DIR__"ann_room.c";

void create()
{
	object river,stone;
	set("short", "16:04");
        set("long", @LONG
就是这里。
LONG
        );
	set("objects", ([
		__DIR__"npc/mengye" : 1,
	]));
	set("exits",([
  		"up" : "enterance",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
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
