inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "漆黑暗道");
        set("long", @LONG
至此已是伸手不见五指，你什么也看不出来，只是隐隐约约觉得前面有粗重的
呼吸声，一个铁塔般的大汉站在一只小船上。
LONG
        );
        set("exits", ([ 
		"south":	__DIR__"tunnel3",
	]));
        set("no_fly",1);
        set("item_desc", ([
      		
    	]));
        set("objects", ([
        	__DIR__"npc/sunju":	1,
        	__DIR__"obj/boat":	1,
	]) );

        set("coor/x",-1260);
        set("coor/y",990);
        set("coor/z",-60);
	set("map","zbeast");
	setup();
}
