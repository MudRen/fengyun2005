#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", CYN"明霞听雪"NOR);
  set ("long", @LONG
阳光自明瓦窗隙间斜照进来，映出流萤般飞舞着的点点浮尘，窗边坐着个明眸
女子，信手拈着盏官窖酒杯，细腻腻的永乐甜白瓷，盈盈一握于指间，轻轻旋转。
空气里缭绕着若有似无的艾蒲香，是如斯的雅媚，小巧玲珑的烟水小楼，坐落在枕
霞之城一侧的雪原东边。
LONG);
        set("exits", ([ 
  "down" : __DIR__"enterance",
]));
		set("objects", ([
			__DIR__"npc/gorcer" :1,
//			__DIR__"npc/hex" :1,
//	"/d/bashan/npc/so":1,
	]) );

  	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",100);
	setup();
  replace_program(ROOM);

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
