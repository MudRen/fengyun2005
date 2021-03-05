inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "三光当铺");
        set("long", @LONG
三光当铺，顾名思义，自然是轩辕三光的铺子了。轩辕早年在江湖上人称“恶
赌神“，赌技神出鬼没，赌瘾见好不收，非到“天光，地光，人光”不肯罢休。后
来不知为了什么，发誓再不嗜赌，也许是为了方便同好吧，在此开了家当铺。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"vroad3",
	]));
        set("objects", ([
		__DIR__"npc/sanguang": 1,
	]) );
	set("coor/x",70);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
