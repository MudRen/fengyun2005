inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "白杨树林");
        set("long", @LONG
路旁的白杨树蔓延数十里，这是西北最常见的树种，一排排傲然的挺立，如同
放哨的士兵。树干通常是丈把高，象是加以人工似的，笔直向上，绝无旁枝；树枝
也是笔直向上，而且紧紧靠拢，也象是经过人工似的，成为一束，绝无横斜逸出。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"wild3",
		"south" : __DIR__"forest1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1600);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}
