#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"琅玕台"NOR);
	set("long", @LONG
在山为琅玕，在水为珊瑚：琅玕台与巴山悬谷中一切建筑风格俱大不同，
自选材到手工都极尽奢华，琳宫宝塔、重楼飞檐，甚至连阶梯都是真真正正的
凉州上好青玉所刻。
LONG
        );
	set("exits",([
		"southdown" : __DIR__"53",
	]) );

	set("objects", ([
	__DIR__"npc/qian" : 1,
					]) );

  	set("coor/x",50);
	set("coor/y",40);
	set("coor/z",10);
	set("outdoors", "potboil");
	setup();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
