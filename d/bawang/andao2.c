#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "暗道");

	set("long", @LONG
这是一条暗道，本是饿虎山上的强盗们把财宝从断塔运至聚义厅的捷径，不过
显然很久已经没人来过了，阴暗潮湿的空气里，带著种腐朽的臭气，刺激得你几乎
连眼睛都睁不开。暗道尽头是一堵似乎可以推动的木墙。
LONG);

	set("type","street");
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("exits",([
		"northdown":__DIR__"andao1",
		"eastup":__DIR__"juyiting",
	]) );

	setup();
	create_door("eastup", "wall","木墙", "westdown", DOOR_CLOSED);
}
