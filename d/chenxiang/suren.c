// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "俗人居");
        set("long", @LONG
这是沉香城里最大，最象样的一个饭馆。饭馆的四墙上是一整幅山水画，画中
的景色忽近忽远，忽浅忽深，一看就是出自大师之手。饭店虽然大，但只有一层，
而且出奇地干净。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs5",
]));
        set("objects", ([
        __DIR__"npc/xb": 1,
                        ]) );
	set("coor/x",10);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
