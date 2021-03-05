#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"板桐圃"NOR);
	set("long", @LONG
在悬谷初辟之时，板桐圃即被公认为巴山胜景之一，而当年神教天魔坛凤
三公子更是独好此处，在每一个天气晴朗的下午都要来这里小憩，看金色的阳
光洒下，微风轻动，摇晃一地斑斓的光影。
LONG
        );
	set("exits",([
  		"east" : __DIR__"66",
		"northup" : __DIR__"57",
  		"west" : __DIR__"46",


	]) );

	set("objects", ([
	__DIR__"npc/ku" : 1,
					]) );

  	set("coor/x",50);
	set("coor/y",60);
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
