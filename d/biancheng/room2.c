inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "客房");
        set("long", @LONG
客房并不华丽，却布置的很舒适，所有的东西都放在伸手可及的地方。走到窗
口可以望见外边一望无际的马场。酸枣木的大床，床边有个黄铜小铃，无论是白天
还是深夜，只要客人一拉铃，马家的仆人立刻就会进屋听从吩咐。
LONG
        );
        set("exits", ([ 
	"south": __DIR__"corridor2",
	]));
        set("objects", ([
        	__DIR__"npc/murong":	1,
	]) );
        set("coor/x",5);
        set("coor/y",105);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
