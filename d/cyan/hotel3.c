// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "四海客栈二楼");
    set("long", @LONG
爬上二楼，只见到客栈四面镂空，数根紫漆的大柱支撑着屋顶，倒像是名
胜的亭阁。扶栏边上凌乱地摆着几张桌椅，小二正躺在一张桌上，闭目假寐。
一阵阵强冽的山风扑面而过，你突然觉得若是在此处凭风痛饮，必将为人生一
大乐事，不亦快哉。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/desk2":1,
	__DIR__"obj/chair":2,
	__DIR__"npc/wailencer":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"down" : __DIR__"hotel2",
	]) );

	//565698


	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",100);
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


