// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "地狱门");
        set("long", @LONG
翻过背阴山，群鬼乱舞，孤魂四散，阴嚎之声，不绝于耳，你不由得发足狂奔，
转眼已经来到地狱门，一入此门，便是十八层地狱，无数世间作恶之人在此关押受
刑。
LONG
        );
        set("exits", ([
		"north" : __DIR__"shandao",
		"down" : __DIR__"diaojin",
        ]) );
        set("objects", ([
                __DIR__"npc/ghost" : 5,
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
