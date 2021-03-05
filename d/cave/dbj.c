// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "东北角");
        set("long", @LONG
一根钟乳石从天而降，足足有一人多粗，就好象是一个大厅的柱子。如果仔细
看的话，还可以发现一条条细细的流水从柱子上涓涓流下，没入地面就不见了。
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"dbm",
  		"south" : __DIR__"btdm",
	]));
    set("objects", ([
        __DIR__"npc/tangye": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();

}