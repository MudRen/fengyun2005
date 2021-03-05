
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "漫长甬道");
        set("long", @LONG
绿松石制的大门后，是一条修长而宽阔的甬道。微潮的穿堂风掠过甬道，空气
出人意料的清新，并无一丝一毫的压抑。甬道两侧的墙上每隔几步就插着一支牛油
巨烛，映得黑石地面分外明亮。
LONG
        );
	set("exits",([
  		"east" : __DIR__"jadegate",
  		"enter" : __DIR__"couplemaze_24",
	]) );
	set("no_fly",1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
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

