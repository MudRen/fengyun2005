#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"望星崖"NOR);
	set("long", @LONG
望星崖处在巴山悬谷的尽头，满山的萧凉荒瑟在这里可以一览无遗。每年
一到这个季节，望星崖的风总是变得很冷很冷，整日整夜地呼啸着，似乎要吹
去这个世界上残存的一丝暖意。
LONG
        );
	set("exits",([
//  		"north" : __DIR__"57",
  		"southdown" : __DIR__"57",
//  		"west" : __DIR__"57",
//  		"east" : __DIR__"57",
	]) );

	set("objects", ([
	__DIR__"npc/ye" : 1,
					]) );

	set("coor/x",50);
	set("coor/y",80);
	set("coor/z",20);
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
