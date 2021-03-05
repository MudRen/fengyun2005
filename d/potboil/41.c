#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"入魔关"NOR);
	set("long", @LONG

远山在夕阳中由翠绿变为青灰，泉水流到这里，也渐渐慢了。风的气息却
更芬芳，因为鲜花就开在山坡上，五色缤纷的鲜花静悄悄地拥抱着一道隘口，
安宁，祥和。你抬起头来，左边的山壁上却赫然是三个血红的大字：

[1;31m　　　　　　　　　关　　　　魔　　　　入[2;37;0m


LONG
        );
	set("exits",([
		"northup" : __DIR__"42",
		"southdown" : "/d/bashan/jadegate",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",40);
	set("coor/y",10);
	set("coor/z",-20);
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
