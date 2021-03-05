#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"忘川河"NOR);
	set("long", @LONG
离开又称三界之门的往生道，你仿佛步进了幽刹黄泉：挂在西面永远不落
的残阳将激啸的忘川浊水映得一片血红，凝滞的空气中没有一毫风意。魔教中
人极少逗留此地，北面的黄泉海畔却是悬谷中情人相依的一大胜境。
LONG
        );
	set("exits",([
		"northdown" : __DIR__"75",
		"westup" : __DIR__"64",
		"eastdown" : __DIR__"84",
	]) );

	set("objects", ([
	__DIR__"npc/du" : 1,
	__DIR__"npc/yin" : 1,
					]) );

  	set("coor/x",70);
	set("coor/y",40);
	set("coor/z",-10);
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
