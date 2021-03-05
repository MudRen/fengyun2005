// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "凌云顶");
    set("long", @LONG
凌云顶四面怪石嶙峋、林木葱葱、崖壁陡峭，登上此处，已可将整座明霞
山的脉势一览无疑，极目远眺，更可见到西边的黑松城堡、以及更远处的风云
城，只是此时的风云城看上去破破烂烂，你记忆中耸入云霄的黄金塔亦不见踪
影。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock2":1,
	__DIR__"obj/woods":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"southdown" : "peak1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",0);
	set("coor/y",40);
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


