#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"三生石"NOR);
	set("long", @LONG

	
[1;37m　　　　　　╔╕
　　　　　　║╰╮
[1;36m　　　　　　║│╰╮
　　　　　　║││╰╮
[1;34m　　　　　　║││││
　　　　　　╚╧╧╧╛
[2;37;0m

　今生已知前生事， 三生石上留姓氏， 
　不知来生他是谁， 饮汤便忘三生事。

LONG
        );
	set("exits",([
		"westup" : __DIR__"74",
	]) );

	set("objects", ([
	__DIR__"npc/ding" : 1,
					]) );

  	set("coor/x",80);
	set("coor/y",40);
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
