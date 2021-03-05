// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城南街");
        set("long", @LONG
沉香依山而建，向西便是风景秀丽的[33m黄山[32m。镇中大部分居民是以耕种水稻为生，
每到傍晚，农夫们拖着沉重的步伐，带着满身的汗水从田中回来，回到这里一座座
冒着浓浓的炊烟，散发着诱人的稻米香气的家。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter",
  "south" : __DIR__"cxcenter1",
  "west" : AREA_HUANGSHAN"shanmen",
]));
        set("objects", ([
	__DIR__"npc/farmer": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
