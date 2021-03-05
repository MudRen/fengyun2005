#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"乾坤殿"NOR);
	set("long", @LONG
在群山的深处，竟还坐落着这样一座无人知晓的华丽宫殿。宫殿巍峨开盛
、楼阁相望辉煌，大殿更有千人之量，上絷黄盖，下铺红毯，与禁城中深宫金
銮相比竟是毫不逊色。
LONG
        );
	set("exits",([
		"northup" : __DIR__"43",
		"eastup" : __DIR__"52",
		"southdown" : __DIR__"41",
	]) );

	set("objects", ([
	__DIR__"npc/wei" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",-10);
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
