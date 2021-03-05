#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "三清宫厢房");
	set("long", @LONG
不大的房间，却很干净明亮。左面墙上挂着几副山水画，画下是几张床榻，右
面的墙上挂着几把长剑。正中一个小小的铜炉，香烟袅袅升起，几个年纪相差颇大
的道士正在闭目打坐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"da_yuan",
	]));
        set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/reg_taoist" : 2,
                __DIR__"npc/up_taoist" : 1,
                __DIR__"npc/m_taoist" : 1,
                __DIR__"npc/m_taoist" : 1,
                __DIR__"npc/huo" : 1,
	]));
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
