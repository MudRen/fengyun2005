// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", BLU"亘古魂幡"NOR);
    set("long", @LONG
一刹那间，你就明白了死地存在的原因。有杆深紫色的巨大旗幡插在这
里的一方祭坛中央，旗幡上用古篆描绘着[45m[1;37m亡者不息[2;37;0m四个大字，周围盘旋飞舞
着无数半明半晦的魂灵，整面魂幡正如水波般起伏荡漾，向外散出一重重枯
萎凋零的气息。
LONG
NOR
        );
	set("objects", ([
		__DIR__"npc/flag":1,
		__DIR__"obj/altar":1,
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
  		"west" : __DIR__"bottom13",
	]) );

	set("coor/x",-10);
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


