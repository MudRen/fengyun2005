// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "天北中门");
        set("long", @LONG
路边的石头上刻着一排排蝇头小字，经过多年的侵蚀已经看不出到底写的是什
么了。字体很古怪,似乎不是中土的文字,隐隐约约又似乎有几个字可以辨认出来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tbzl",
  "south" : __DIR__"tt",
]));
        set("objects", ([
        __DIR__"obj/fanstone": 1,
                        ]) );

        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-2);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
        replace_program(ROOM);
}
