#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"秋叶廊"NOR);
	set("long", @LONG
秋花惨淡秋草黄，耿耿秋灯秋夜长。百余年前魔教有女纪洺，专长草木，
以数载时间将明霞异种移植至此，从此无论春夏，这一条长长的行廊两边永远
是秋天的萧瑟景象。
LONG
        );
	set("exits",([
  		"east" : __DIR__"56",
		"southup" : __DIR__"45",
  		"west" : __DIR__"36",


	]) );

	set("objects", ([
	__DIR__"npc/tong" : 1,
					]) );

  	set("coor/x",40);
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
