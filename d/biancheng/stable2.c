inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "马厩");
        set("long", @LONG
万马堂的马厩竟然比一般人住的屋子还要华丽。马厩有两人高，中央是一条铺
着红地毯的走道，两旁隔成一个个小间，养着的是千中选一、万金难求的种马。个
个膘肥体壮，有的乌黑的皮毛象丝绸一般闪光，有的浑身上下，火炭般赤，无半根
杂毛。偶尔从外面牵进来一匹，两肋汗淋淋的，象水洗过一样。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"stable1",
	]));
        set("objects", ([
	]) );
	set("coor/x",-15);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
