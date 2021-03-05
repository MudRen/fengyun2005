inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "玉龙哈什河");
        set("long", @LONG
和阗河滚滚的河水，在六月的残阳下发着光。到了上游，河水双分，西面的一
支便是玉龙哈什河，水流处地势更见崎岖险峻，激起了奔腾的浪花。沿着玉龙哈什
河向上游走，便入了天下闻名、名侠辈出、充满了神秘传说的昆仑山区。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"kunlun3",
		"east" : __DIR__"kunlun1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-700);
        set("coor/y",500);
        set("coor/z",0);
	set("map","zbeast");
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
