// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "天庭");
        set("long", @LONG
天外天的中央，是一个有十几丈方圆的广场。广场的中间有一丈方圆的天池，
池中是波涛汹涌的地下河。仔细望去，河水就象煮沸了一样，丝毫无法判断它的流
向。偶尔有水波漾出地面，将天池周围染出一片绿苔。洞顶有个大洞，每天都有一
柱阳光射入，照耀在暗河上。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tbzm",
  "south" : __DIR__"tnzm",
  "east" : __DIR__ "zd",
//  "west" : __DIR__"zx",
]));
        set("objects", ([
        __DIR__"npc/ximenyu": 1,
        __DIR__"npc/gaoli": 1,
        __DIR__"npc/shuang": 1,
                        ]) ); 
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-4);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
