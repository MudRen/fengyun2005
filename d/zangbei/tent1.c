inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "帐篷");
        set("long", @LONG
路边偶尔会有几顶帐篷，还未走近，早有体形巨大如小熊的藏獒吠着迎上来了。
帐篷用牦牛毛织成，厚重结实，用牛毛绳扎紧拴牢在地上，顶得住这高原的寒风和
黄沙。帐篷里的牧人，对远道来的客人从来是不吝啬的，酥油茶、糌粑和牛羊肉，
放开肚子吃吧。
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"wild2",
	]));
        set("objects", ([
        	__DIR__"npc/dawa":	1,
        	__DIR__"npc/wolfdog":	1,
	]) );
        set("coor/x",-1510);
        set("coor/y",690);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

