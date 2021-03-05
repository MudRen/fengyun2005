// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();
string look_stone2();
string look_stone3();

void create()
{
	set("short", "楠木走廊");
        set("long", @LONG
走廊飞架在山巅之间，将原本隔开数十丈的几处山头连在一起，下临百
丈涧谷，仿佛悬空而建。赤足走在廊上，但觉脚下木质甚是温暖，展眉扶栏
之外，只见左右空空，云海翻涌蒸腾。踩在廊上浮动的云气里，微凉的山风
穿廊而过，只教人心弛神醉，如履仙邦。
LONG
        );
	set("objects", ([
//		__DIR__"obj/desk2" : 1,
	]));
	set("exits",([
  		"east" : __DIR__"hanquan",
  		"west" : __DIR__"houmen",
  		"south" : __DIR__"wangji",
	]) );

	set("item_desc", ([
		"走廊": (: look_stone :),
		"爪印": (: look_stone2 :),
		"痕迹": (: look_stone3 :),
	]) );
	set("indoors", "xiangsi");

	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
}


string look_stone()
{
	object me = this_player();
	if (REWARD_D->riddle_check(me,"两世恩怨") != 1 
		&& REWARD_D->riddle_check(me,"两世恩怨") != 2	// if the bag is lost before the 月神
		&& REWARD_D->riddle_check(me,"两世恩怨") != 9	// if the bag is lost before the 李坏
		)
		return "楠木铺架的走廊，踩上去甚是温暖。\n";
	tell_object(me,"走廊的角落里有着一排小小的爪印，还有什么东西被拖动过的痕迹。\n");
	me->set_temp("annie/xiangsi_master",2);
	return " ";
}

string look_stone2()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 2)
		return "你要看什麽？\n";
	tell_object(me,"爪印散成碎落梅花的样子，看起来像是小猫留下的。\n");
	return " ";
}

string look_stone3()
{
	object me = this_player();
	if (me->query_temp("annie/xiangsi_master") < 2)
		return "你要看什麽？\n";
	tell_object(me,"尘上的痕迹一直望东边去了，消失在不远处。\n");
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


