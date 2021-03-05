// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "低风岩");
    set("long", @LONG
走到这里，你但觉山上狂凛的风势立时减弱，原来是一块棱角锋锐的大石
拦阻在风口之上，也使得淡淡的云雾在此堆积，遮拦住你的视线。大石的一角
隐约刻着文字，极力辨去，写的是：
LONG
HIR
@LONG
　　　　　　　　　　　慎之慎之，前行临渊！
LONG
NOR
        );
	set("objects", ([


		__DIR__"npc/ttd2":1,
		__DIR__"npc/ttd1":1,

	]));
	set("item_desc", ([
		"west":"重重的大雾阻挡住你的视线。\n",
		"northdown":"重重的大雾阻挡住你的视线。\n"

	]) );
	set("exits",([
  		"west" : __DIR__"bridge",
  		"northdown" : __DIR__"forest4",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",80);
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


