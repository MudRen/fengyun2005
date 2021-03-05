#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"天外集"NOR);
	set("long", @LONG
巴山悬谷中并无物产，魔教中人多无法自给自足，于是便有人定期自悬谷
外贩运商货而来，虽说本意只是生活所用，然教众的挑剔成性使得此地贩售的
多是天下罕见的珍品。
LONG
        );
	set("exits",([
		"west" : __DIR__"43",
		"east" : __DIR__"63",
		"northup" : __DIR__"54",
	]) );

	set("objects", ([
	__DIR__"npc/mu" : 1,
	__DIR__"npc/lu" : 1,
					]) );

  	set("coor/x",50);
	set("coor/y",30);
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
