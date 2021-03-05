// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "长空栈道");
    set("long", @LONG
过到这里，你发觉此处尚且只是山腰，面前一条古旧的栈道紧贴着山壁，
栈道外云雾迷茫。因为多年没有人修葺，栈道上铺架的短木板已经残缺不齐，
朽坏泰半，尚存的一些长满了绿色的青苔，在阵阵的山风里摇曳，发出吱呀吱
呀的声响。
LONG
NOR
        );
	set("objects", ([


	]));

	set("no_fly",1);
	set("item_desc", ([

	"木板":"栈道上铺架的短木板已经残缺不齐。\n",
	"短木板":"栈道上铺架的短木板已经残缺不齐。\n",

	"青苔":"栈道上爬满青苔，还是小心为上。\n",
	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"east" : __DIR__"bottom3",
  		"west" : __DIR__"bottom1",
	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",-100);
	setup();
}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (!random(3))
	{
		tell_object(me,HIG"你脚下一滑，在栈道上打了个趔趄，险些摔了出去！\n"NOR);
		me->perform_busy(2);
		return notify_fail(" ");
	}
	else
		tell_object(me,"你一步一脚印，慢慢地沿着栈道前行．．．\n"NOR);
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


