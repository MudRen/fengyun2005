// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", YEL"玄魔刻印"NOR);
    set("long", @LONG
这一条道路的尽头什么都没有，只除了现在正在你面前的这块雪白的大
石。这块如玉一般的石头触手生温，朝天这面削得光滑无比，可以鉴人，上
面阴纹着一圈奇诡的符图，你似曾在那里见过。
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);
	set("no_light",1);
	set("item_desc", ([

	"符图":HIM"\n　　　　　ゞ\n　　　　ぴ　ん\n　　　で　　　Δ\n　　ペ　　Θ　　З\n　　　ζ　　　ф\n　　　　я　\n　　　　　ω\n\n"NOR,

	"大石":"一块雪白的大石，如玉一般触手生温。",

	"west":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"east":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"north":"山阴中处处有雾，你什么也分辨不清楚。\n",
	"south":"山阴中处处有雾，你什么也分辨不清楚。\n",

	]) );
	set("exits",([
  		"east" : __DIR__"bottom8",
	]) );

	set("coor/x",-60);
	set("coor/y",40);
	set("coor/z",-100);
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


