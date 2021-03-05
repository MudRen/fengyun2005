// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "黑暗之中");
    set("long", @LONG
一片永无止境的漆黑．．．．．．．．．．．．．．．．．．．．．．．
LONG
NOR
        );
	set("objects", ([

	]));
	set("no_fly",1);

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",-400);
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


