// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	// 骷髅士兵，骷髅将军，骷髅大将军

	set("short", MAG"葬魂谷"NOR);
    set("long", @LONG
从方才的战场走到这里，血腥味顿时淡了许多，呼吸间浓厚的阴寒之气
却骤然明显起来。寸草不生、一片荒芜的土地间，透着缕缕死物腐朽败坏的
气息，似是死在战场上的怨魂仍留在这里，徘徊着不肯离去，而东边的雾气
里，隐隐传来一阵阵凄厉的哀鸣。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/ghost1":1,
	__DIR__"npc/ghost2":1,
	__DIR__"npc/ghost3":1,
	__DIR__"npc/ghost4":1,

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
  		"north" : __DIR__"bottom11",
  		"west" : __DIR__"deadforest2",
  		"east" : __DIR__"bottom13",
	]) );

	set("coor/x",-20);
	set("coor/y",20);
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


