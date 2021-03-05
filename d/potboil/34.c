#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"丹粟阶"NOR);
	set("long", @LONG
丹粟即是朱砂。此阶东去巴山悬谷中的＂酒馆＂杨柳舍，日常行人往返、
十分热闹，竟至磨平了寿岩阶板、露出了阶下赤土，状似朱砂，于是便得名为
丹粟阶。
LONG
        );
	set("exits",([
  		"north" : __DIR__"35",
		"eastup" : __DIR__"44",
		"south" : __DIR__"33",
	]) );

	set("objects", ([
	__DIR__"npc/san1" : 1,
	__DIR__"npc/san2" : 1,
					]) );

  	set("coor/x",30);
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
