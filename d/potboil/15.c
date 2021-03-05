#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"春雨楼"NOR);
	set("long", @LONG
历任魔教的教主所居之地，也是武林典故中最为神秘的地方。与它相连的
永远是一把杀气逼人的弯刀，一个凄艳动听的名字，一种至凶烈煞的刀法：小
楼一夜听春雨，明朝何处见杏花？
LONG
        );
	set("exits",([
		"eastdown" : __DIR__"25",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",20);
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
