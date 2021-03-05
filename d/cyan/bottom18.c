// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", RED"封法台"NOR);
    set("long", @LONG
紫檀木造的塔顶，幻镜石修的岩柱。如今的封法台上，满满的贴着都是深
黄色的符纸，就连地面也横七竖八地糊着无数。封法台的中央赫然栽着一杆翠
竹，竹下香案一方，香案上供品齐备，看似有人正要打一场清醮。然而道士却
不在此处，只有一个瘦削的背影立在一根岩柱上，轻吹着凄婉动人的旋律。
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/du":1,
	]));
	set("no_fly",1);
	set("item_desc", ([


	]) );
	set("exits",([
		"down" : __DIR__"maze/exit",
	]) );

	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",1000);
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


