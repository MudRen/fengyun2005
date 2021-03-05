// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	// 骷髅土卒，骷髅士兵，骷髅将军，骷髅大将军

	set("short", HIR"血战杀场"NOR);
    set("long", @LONG
走到山阴处的一处腹地，你倒抽了一口凉气，只见谷地中尸横遍野，四
处都是残坏的刀枪盾戟，几株大树被烧的焦黑躺倒在地，累累的白骨中余烬
似乎犹然未熄。空气中飘荡着淡淡的血腥气味，几乎还能听见士兵临死前的
呼喊，仿佛战事只是刚刚结束。
LONG
NOR
        );
	set("objects", ([

	__DIR__"npc/skeleton1":2,
	__DIR__"npc/skeleton2":2,
	__DIR__"npc/skeleton3":1,
	__DIR__"npc/skeleton4":1,

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
  		"south" : __DIR__"bottom12",
  		"east" : __DIR__"bottom16",
  		"west" : __DIR__"bottom10",
	]) );

	set("coor/x",-20);
	set("coor/y",30);
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


