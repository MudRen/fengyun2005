// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄武门");
        set("long", @LONG
玄武门实际只是沉香镇南面临近东西门处的一个牌坊，镇上的富绅们好大喜功，
把原来的城墙推倒重建，东首通向[33m风云道[32m，西面出城后便是著名的[33m狼山[32m。玄武门飞
檐镂砖，可惜少有游客，只是偶尔有小巧的鸟儿在此驻足。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs2",
  "west" : __DIR__"mw",
  "east" : __DIR__"me",
  "south" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
