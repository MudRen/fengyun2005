#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "飞星传恨");
	set("long", HIC"

          星     光 。  。  。 "NOR"

这是一个穹顶圆屋。环壁嵌以青金石，在烛光的映衬下，如点点流星的闪光。
屋中有一幅屏风，上面似乎题了一首词。\n"

        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/throwingbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

