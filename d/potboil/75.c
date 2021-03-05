#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"黄泉海"NOR);
	set("long", @LONG

   ★           ☆
            ☆

                             ◢◣
      ☆      ～     ～     ◢◢◣  
   ～     ～     ～    ～  ◢◢◣◣ ～
      ～    〃○〃●     ◢◢◢◣◣◣
  ～         /■\/■\   ～    ■  ～
        ╪═√√√√═╪═╪═╪═╪═╪

LONG
        );
	set("exits",([
		"southup" : __DIR__"74",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",70);
	set("coor/y",50);
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
