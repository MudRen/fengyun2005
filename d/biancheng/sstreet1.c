inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南街");
        set("long", @LONG
一条南北向的小街横贯在小镇的东侧，不长，仅数百尺。小街的一端，是无边
无际的草原，小街的另一端，也是无边无际的草原。走在街上，四周满是戒备的眼
光，边远的小镇，没有官府，没有豪门，人与人的一切恩怨，唯一解决途径便是出
鞘的刀和身上的血。  
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"mianguan",
		"north": __DIR__"road2",
		"south": __DIR__"sstreet2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",-10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
