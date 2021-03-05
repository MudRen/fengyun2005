// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", WHT"冰结小道"NOR);
	set("long", @LONG
小心翼翼的行进在这七尺高下的冰道上，还要不时提防磕到洞顶垂下的冰棱，
或是被地上凹凸不平的冰坑冰渣绊倒，有时隔着薄薄的冰层已可看见出口，前方却
又是偌大的冰石阻住去路。你越向前行，心里的惊慌弥漫得越紧，而所有的期望，
都寄托在手中明灭不定的微弱光芒之上。
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);

	set("valid_startroom",1);

	set("exits",([
		"north" : __DIR__"icecave-maze/exit",
		"south":  __DIR__"icecave2-maze/entry",
	]));
	set("objects",([				
			__DIR__"mazenpc/trader":		1,	// ghost trader
		]));
	set("NONPC", 1);
	set("coor/x",-20);
	set("coor/y",-110);
	set("coor/z",30);
	setup();

}

void init()
{
	object room;
	if (!(room = find_object(__DIR__"icecave")))
		room = load_object(__DIR__"icecave");
	room->generate_maze();
	room->generate_maze2();
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
