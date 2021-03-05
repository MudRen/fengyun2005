// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "紫电青霜阁");
        set("long", @LONG
青石条搭起的房子格外的高大，室内灯火通明，地上铺的是厚厚的波斯地毯，
四周的摆设十分的精致，墙上挂着些精致小巧的刀剑，看起来就像孩童的玩具。总
之这里的一切跟外面的气氛格格不入。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"zx",
	]));
    set("objects", ([
        __DIR__"npc/weaponer": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

