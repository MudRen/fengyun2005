// Room: /d/chuenyu/gate_castle.c

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "黑松淳于");
	set("long", @LONG
你站立在一座宏伟的城堡之前，城门之上挂着一块金匾。金匾上龙飞凤舞的写
着四个大字“黑松淳于”，金匾左下角刚劲草书落款：
		“淳于怀太”，“壬子年一月十八日”。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		  "east" : __DIR__"east_castle",
		  "west" : __DIR__"west_castle",
		  "north" : __DIR__"trap_castle",
		  "down" : __DIR__"high_b_mtn2",
	]));
	set("outdoors", "chuenyu");

	create_door("north","door", "城门", "south", DOOR_CLOSED);

	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}