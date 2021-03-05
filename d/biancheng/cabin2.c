inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "木屋");
        set("long", @LONG
屋子盖得很低，几乎一伸手就可以摸到屋梁，墙上的粉亦已剥落，上面贴着一
张关夫子观春秋的木刻图，一张朱大子的治家格言，和一张手写的劝世文，字写得
居然很工整。屋里只有一扇窗子，一道门，门上挂着已经快洗得发白的蓝布门帘。
LONG
        );
        set("exits", ([ 
	"east": __DIR__"smallroad2",
	]));
        set("objects", ([
        	__DIR__"npc/singer": 1,
	]) );
	set("coor/x",-60);
        set("coor/y",-20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
