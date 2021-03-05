inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "高山湖泊");
        set("long", @LONG
数百个高山湖泊如天空不经意滴下的眼泪，散落于嶙嶙乱石间，碧蓝如玉，晶
莹剔透。湖水寒冷刺骨，湖里却游鱼欢畅穿梭，湖面百鸟栖息。湖边石丛不时露出
茸茸小草、小花，在高原的土地上摇曳出生命惊心动魄的美丽。
LONG
        );
        set("exits", ([ 
		"northwest":  __DIR__"haizi",
	]));
        set("objects", ([
        	__DIR__"npc/horse1":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2050);
        set("coor/y",550);
        set("coor/z",40);
	set("map","zbwest");
	setup();

}
