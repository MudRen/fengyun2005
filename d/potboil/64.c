#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"往生道"NOR);
	set("long", @LONG
往生道地在巴山悬谷以东，四面阴风飒飒，寒气袭人，两侧山壁上的冰流
镜面般倒悬而下，陡若绝壑，拢着冷雾弥漫的窄道岔口，时时可闻远山枭啸，
催行人极乐往生。
LONG
        );
	set("exits",([
		"north" : __DIR__"65",
		"south" : __DIR__"63",
		"eastdown" : __DIR__"74",
	]) );

	set("objects", ([
	__DIR__"npc/shi" : 1,
					]) );

  	set("coor/x",60);
	set("coor/y",40);
	set("coor/z",0);
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
