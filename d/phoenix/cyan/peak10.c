// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "观星台");
    set("long", "

　　　这　　里　　没　　有　　什　　么　　特　　别　　。

"
NOR
        );
	set("objects", ([

	__DIR__"npc/ho":1,

	]));
	set("item_desc", ([
	]) );
	set("exits",([
  		"southdown" : "peak7",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",80);
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


