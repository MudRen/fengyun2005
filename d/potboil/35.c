#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"紫蓿苑"NOR);
	set("long", @LONG
紫蓿苑溪池环绕，水阁荇风，自古住的便是神教中职位极高的一众女子，
苑中有青凛石台一座、石镜若干，摆设得颇为别致；神教的每一次大会庆典均
在此处进行。
LONG
        );
	set("exits",([
  		"north" : __DIR__"36",
		"westup" : __DIR__"25",
		"south" : __DIR__"34",
	]) );

	set("objects", ([
	__DIR__"npc/ji" : 1,
	__DIR__"npc/fu" : 1,
					]) );

  	set("coor/x",30);
	set("coor/y",50);
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
