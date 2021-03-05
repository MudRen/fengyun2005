inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山坡");
        set("long", @LONG
山坡一片青绿，看来并不高，也不太远。坡顶上一座大坟，坟头矗立着一块九
尺高的青石碑，坟上草色已苍，几棵白杨，伶仃地站在西风里。山坡前一片大草原，
接连着碧天。风吹长草，正如海洋中的波浪。
LONG
        );
        set("exits", ([ 
		"southdown" : __DIR__"grassland6",
	]));
        set("objects", ([
        	__DIR__"obj/tomb" : 1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",110);
        set("coor/y",110);
        set("coor/z",10);
	set("map","zbwest");
	set("discussion_shen",1);
	setup();
	replace_program(ROOM);
}
