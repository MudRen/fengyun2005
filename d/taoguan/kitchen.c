#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清宫厨房");
	set("long", @LONG
一间不大的厨房，却是干干净净。左面靠墙是一个很大的炉灶，右面墙角摆着
几坛好酒。中间的一张大桌上摆着的饭菜，散发着阵阵香气。两个道士正在忙着做
饭。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"da_yuan",
]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/o_taoist" : 2,
                __DIR__"npc/lin" : 1,
]));
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
