// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小河流上游");
        set("long", @LONG
这里的河床较宽，水流缓慢。河边的芦苇随风起伏荡漾，发出沙沙的声音，偶
尔还夹杂着野鸭的嘎嘎声。河边有几条依稀的小径蜿蜒地伸向远方，几块嶙峋的怪
石耸立在小径旁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle",
  "south" : __DIR__"playground",
]));
	set("outdoors","wanmei");
	set("coor/x",20);
	set("coor/y",100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
