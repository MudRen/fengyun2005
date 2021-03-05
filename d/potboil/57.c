#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"别离丘"NOR);
	set("long", @LONG
小小的土丘静静地在悬谷深处伫立，隔开了望星崖与巴山禁地。据说魔教
中的每一对情侣在分开时都会来到这里，一起躺下来仰望天空；天上白云流动
，有时相聚，却总是免不了再度相离。
LONG
        );
	set("exits",([
  		"northup" : __DIR__"58",
  		"southdown" : __DIR__"56",
  		"westup" : __DIR__"47",
//  		"east" : __DIR__"57",
	]) );

	set("objects", ([
	__DIR__"npc/gu" : 1,
	__DIR__"npc/tang" : 1,
					]) );

	set("coor/x",50);
	set("coor/y",70);
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
