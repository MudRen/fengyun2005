
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "钢索桥上");
	set("long", @LONG
钢索很滑，山风很大，人走在上面，就象是风中的残烛。放眼望过去，四面都
是白云，飘飘渺渺，浮浮动动，整个天地都好像在浮动中。要想平平稳稳的走在上
面，实在很不容易。
LONG
	);
	set("exits", ([
                "west" : __DIR__"forest9",
                "east" : __DIR__"ghost",
	]));
	set("objects", ([
                __DIR__"npc/ghost1" : 1,
	]));
        set("NONPC",1);
	set("coor/x",-80);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "east"  || !objectp(ob=present("ghost", this_object()))) return 1;

		if(!me->query_temp("marks/合约"))
        	return notify_fail(HIY "勾魂使者喝道：没有合约，不可以进幽灵山庄。除非你能接我一招！(accept test)\n"NOR);
		else {
			me->set_temp("marks/合约", 0);
			return 1;
		}
}
