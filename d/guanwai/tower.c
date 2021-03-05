#include <obj.h>

inherit ROOM;

void create()
{
	set("short", "宝塔");
	set("long", @LONG
这是一个中空约十丈高的尖塔。塔的内部终日不见阳光，长满了又滑又腻的绿
苔。塔虽然破旧，却有很多虔诚的信徒到这里膜拜。
LONG
	);
	
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"templeyard2",
		"east" : __DIR__"templeyard",
		"west" : __DIR__"chanhouse",
		"north" : __DIR__"templeyard3",
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("NONPC",1);
	set("objects", ([
		__DIR__"npc/keeper" : 1,
	]));

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
