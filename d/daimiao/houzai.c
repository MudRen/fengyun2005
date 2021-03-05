//mac's houzai.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <room.h>
inherit ROOM;
void create()
{
  set("short","厚载门");
  set("long",@LONG
岱庙的北门叫“厚载”，意思是大地能载九皇之德，又称“鲁瞻”，取意于《
诗经·鲁颂》的“泰山岩岩，鲁邦所瞻”。门上有望岳楼三间，檐下悬“厚载门”
匾额。两边是高两丈的青砖围墙，向北便是泰山了。
LONG
  );
  	set("exits",([
         	"north":AREA_TAISHAN"daizong.c",
         	"south":__DIR__"tongting.c",
         	"up"	: __DIR__"wangyue",
         	"east": __DIR__"e_wall_4",
         	"west": __DIR__"w_wall_4",
        ]));
        set("objects", ([
		__DIR__"npc/guard2":	2,
       ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
