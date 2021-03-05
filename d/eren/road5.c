inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山道");
        set("long", @LONG
只见迎面飞来一道白练，如万丈银河，泻入深谷，又似静止一般，不闻其声。
这刻情景，如图画里万壑千谷，壁上一道飞瀑，云烟处茅舍几间、小桥一抹，画意
诗情。路旁有块石碑，上面龙飞凤舞地写着几个字。
LONG
        );
        set("exits", ([ 
	"southup" : __DIR__"road3",
	"east" : __DIR__"valley1",
	]));
        set("objects", ([
        __DIR__"obj/bei": 1,
        
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
