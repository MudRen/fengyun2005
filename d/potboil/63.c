#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"东南角"NOR);
	set("long", @LONG

		  o      ( \/ )     o
		  .---.   \  /   .-"-.
		 /   6_6   \/   / 4 4 \
		 \_  (__\       \_ v _/
		 //   \\        //   \\
		((     ))      ((     ))
	  =======""===""========""===""=======

LONG
        );
	set("exits",([
		"north" : __DIR__"64",
		"west" : __DIR__"53",
	]) );

	set("objects", ([
	__DIR__"npc/lian" : 1,
					]) );

  	set("coor/x",60);
	set("coor/y",30);
	set("coor/z",0);
	set("indoors", "potboil");
	setup();
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
