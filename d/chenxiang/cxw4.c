// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小西湖");
        set("long", @LONG
这可不是中原的西施湖，湖水发暗黑色，上面漂浮着各种各样的垃圾，偶尔还
有一串串的气泡浮出湖面，发出“咕嘟咕嘟”的声音。如果不是极力摒住呼吸，真
的会被这里的臭气熏倒。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxw3",
]));
        set("objects", ([
        __DIR__"npc/qingbo": 1,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",-40);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
