// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "皓月宫");
        set("long", @LONG
转到峰上，方知此处别有异趣，景色不比从前。只见数座悬栏飞虹似横跨
南北，将相思一线的山顶尽数相连，廊外山风料峭，云生雾舞，凭栏而望，一
脉山水尽入眼帘。前方不远处就是一个悬廊入口，抬眼看去，只见廊前石坊上
刻着数个大字：

　　　　　　　　　　　[1;37m皓　　　　月　　　　　宫[0;32m

LONG
NOR
        );
	set("objects", ([
//		__DIR__"obj/rock4" : 1,
	]));
	set("item_desc", ([
//		"石坊": (: look_stone :),
	]) );
	set("exits",([
  		"northdown" : __DIR__"shipai",
  		"east" : __DIR__"cansan",
  		"west" : __DIR__"zoulang",
	]) );

	set("outdoors", "xiangsi");

	set("coor/x",20);
	set("coor/y",-20);
	set("coor/z",20);
	setup();
}

string look_stone()
{
	object me = this_player();
	tell_object(me,"石坊背面雕着一行小字：\n尝藏逃情於廊下，不日却踪迹全无．．天欲令我断情耶？\n");
	me->set_temp("annie/xiangsi_master",1);
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


