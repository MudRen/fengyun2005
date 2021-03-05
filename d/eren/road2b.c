inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "西山道");
        set("long", @LONG
山道继续向上，远山是枯黄色的，松林也是枯黄色，在青灰色的苍穹下，看来
有种神秘而凄艳的美。风过，松叶呜咽，象是情人离别时的哭泣。远处似乎有人低
颂佛号，在这本不该有人烟的地方竟然有一座庵寺，这所庵寺竟然还是武林中人人
提起时都要叹一口气的梅花庵。
LONG
        );
        set("exits", ([ 
		"southdown" : __DIR__"road2a",
		"westup": __DIR__"meihuaan",
	]));
        set("objects", ([   	
	]) );
	set("outdoors", "eren");
        set("coor/x",10);
        set("coor/y",20);
        set("coor/z",70);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
