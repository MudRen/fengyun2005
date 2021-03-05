// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "金牢");
        set("long", @LONG
这是间百丈余的金牢，尽是些各种各样令人心胆俱裂的刑具，铡刀，铁签，老
虎椅，刀剑斧钺。。各种杀人的利器无所不全。大牢顶上高高悬着个腕臂粗细的牛
油红烛，火光摇曳闪烁，映在不住呻吟的犯人扭曲痛苦的脸上。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"zd",
  "east" : __DIR__"ztdd",
]));
        set("objects", ([
        __DIR__"npc/guard3": 1,
                        ]) );

        set("indoors", "cave");
	set("coor/x",5);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
