// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "四海客栈外");
    set("long", @LONG
你好奇地走近四海客栈，只觉得匪夷所思。在一年到头都不一定凑得齐手
指头那么多个游客“到此一游”的凌云峰顶，连鸟儿都未必肯在这里筑巢，怎
会有素来标榜不做赔本买卖的商人，浪费人力财力在此开间铁定没有油水的客
栈？
LONG
NOR
        );
	set("objects", ([

	__DIR__"npc/rabbit":2,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"out" : __DIR__"peak2",
  		"enter" : __DIR__"hotel2",
	]) );

	set("outdoors", "cyan");

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",90);
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


