#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"杨柳舍"NOR);
	set("long", @LONG
杨柳舍是间红瓦白墙的别致小屋，四面杨柳青青，屋前桌觞散乱，俨然是
一派露天小酒馆景色。许多年来，魔教中一直有着一条不成文的惯例：无论身
份高低，教中最大的酒鬼就是这间小屋的主人，在本务外还要负责掌管神教的
玉酿琼浆。
LONG
        );
	set("exits",([
		"westdown" : __DIR__"34",
	]) );

	set("objects", ([
	__DIR__"npc/long" : 1,
	__DIR__"npc/meng" : 1,
					]) );

  	set("coor/x",40);
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
