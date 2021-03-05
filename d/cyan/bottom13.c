// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", RED"死地深崖"NOR);
    set("long", @LONG
方踏进这里，便令人悚然一惊。你从来不曾见过这样的地方，这地方没
有声音，没有生命，没有花草，甚至连岩石在这里都不见踪影，有的只是死
一般的寂静，死一般的气息，死一般的景色，死一般的光影。这里带给你的
感觉只有一个字，死，死地！
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
  		"west" : __DIR__"bottom12",
  		"east" : __DIR__"bottom14",
	]) );

	set("coor/x",-10);
	set("coor/y",20);
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


