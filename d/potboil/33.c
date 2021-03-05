#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"西南角"NOR);
	set("long", @LONG
是月白风轻，夜凉如水，一点一点的寒意渐渐地浸过门窗的缝隙，悄悄落
到西南角的小阁楼中，爬到你的身上，穿过重衣，轻轻抚触着你的肌肤，而楼
外浅浅的虫鸣，无端惊动着离人的归心。
LONG
        );
	set("exits",([
		"north" : __DIR__"34",
		"east" : __DIR__"43",
	]) );

	set("objects", ([
	__DIR__"npc/lan" : 1,
					]) );

  	set("coor/x",30);
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
