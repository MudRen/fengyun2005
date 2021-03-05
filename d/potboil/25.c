#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"青云栈"NOR);
	set("long", @LONG
魔教各个时期的典制虽多有不一，然始终依古律下分六司、外设长老会以
相互制衡；青云栈庭院左右四间雅室便是六司之中大司略、大司寇、大司吏与
大司库内定的住处。
LONG
        );
	set("exits",([
  		"westup" : __DIR__"15",
		"eastdown" : __DIR__"35",
		"southup" : __DIR__"24",
	]) );

	set("objects", ([
	__DIR__"npc/jiang" : 1,
					]) );

  	set("coor/x",20);
	set("coor/y",50);
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
