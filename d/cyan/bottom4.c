// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", HIR"无还之道"NOR);
    set("long", @LONG
一阵冰寒的阴风突然自你身边拂过，那是一种浸入骨髓的寒意与阴冷，
本不该存在于人世之间。浓雾中传来了一阵阵凄厉诡谲的尖啸，你心头有种
不祥的预感，只觉得再向前去，就会走进不存在于这个人间的世界，而且再
难回头。
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
  		"north" : __DIR__"bottom5",
  		"east" : __DIR__"bottom10",
  		"west" : __DIR__"bottom3",
	]) );

	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir == "west")
		return notify_fail("这个方向的阴风骤变得强烈无比，你顿觉举步唯艰。\n");

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


