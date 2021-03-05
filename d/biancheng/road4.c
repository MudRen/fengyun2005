inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "西街");
        set("long", @LONG
太阳照在街上，路面闪着金光。西街通向小镇的中心，两旁是店铺，酒家。小
镇的居民并不好客，到处都有好奇和戒备的眼光在偷偷地审视路过的陌生人，这种
眼光甚至比秋日的骄阳更灼人，更无法忍受。街的两旁有一家小饭馆和一扇肉铺。        
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road3",
		"west" : __DIR__"road5",
		"north": __DIR__"riceshop",
		"south": __DIR__"meatshop",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-30);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
