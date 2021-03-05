inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "西山道");
        set("long", @LONG
转过弯，山道继续向上，远山是枯黄色的，松林也是枯黄色，在青灰色的苍穹
下，看来有种神秘而凄艳的美。风过，松叶呜咽，似情人离别时的哭泣，又似不知
名猛兽的哀鸣。几片落叶旋飞而下，远处隐隐约约传来鸣钟之声。
LONG
        );
        set("exits", ([ 
		"eastdown" : __DIR__"valleyentry",
		"northup": __DIR__"road2b",
	]));
        set("objects", ([   	
	]) );
	set("outdoors", "eren");
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",60);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
