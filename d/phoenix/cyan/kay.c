// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "弑马台");
    set("long", @LONG
走到这里，一片毫无蔽掩的岩地突兀地自黄树林中显现。岩地尽处是一条
光泽明润的青色石槽，似是新近方打造而成，石槽边缘有一块如镜面光滑的碑
状黑石，石头上尚未刻下任何文字。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock3":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"west" : "forest1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",20);
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


