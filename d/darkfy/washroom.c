
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;

void create()
{
        set("short", "洗衣店");
        set("long", @LONG
这是一间洗衣店，这里是有钱人将衣服拿来浆洗的地方。这里的老板是一
个上了年纪的老太婆，孤身一人，无儿无女，仅靠这洗衣店微薄的收入维持生
活。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ecloud3",
]));

        set("objects", ([
        __DIR__"npc/" : 1,
                        ]) );
        set("coor/x",30);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}

