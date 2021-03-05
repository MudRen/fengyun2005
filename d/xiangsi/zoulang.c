// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();
string look_stone2();

void create()
{
	set("short", "杨木走廊");
        set("long", @LONG
走廊飞架在山巅之间，将原本隔开数十丈的几处山头连在一起，下临百
丈涧谷，仿佛悬空而建。赤足走在廊上，但觉脚下木质甚是温暖，展眉扶栏
之外，只见左右空空，云海翻涌蒸腾。踩在廊上浮动的云气里，微凉的山风
穿廊而过，只教人心弛神醉，如履仙邦。
LONG
        );
	set("objects", ([
//		__DIR__"obj/rock4" : 1,
	]));
	set("exits",([
  		"east" : __DIR__"haoyue",
  		"south" : __DIR__"hanquan",
	]) );
	set("item_desc", ([
		"走廊": (: look_stone :),
		"白骨": (: look_stone2 :),
	]) );

	set("indoors", "xiangsi");

	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

string look_stone()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 2)
		return "楠木铺架的走廊，踩上去甚是温暖。\n";
	tell_object(me,"走廊的角落里有着一排小小的爪印，凌凌散散的还有几根小小的白骨。\n");
	me->set_temp("annie/xiangsi_master",3);
	return " ";
}

string look_stone2()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 3)
		return "你要看什麽？\n";
	tell_object(me,"几根老鼠的白骨头。\n");
	return " ";
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


