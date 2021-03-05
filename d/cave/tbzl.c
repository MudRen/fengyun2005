// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "土牢");
        set("long", @LONG
过了天北中门，便是很宽敞的五行大牢中的最为恐怖的土牢，这里没有什么刑
具，就只有一个个挖地一人多深的沙坑，和堆在四周以备添埋用的黄沙，据说这沙
也不是寻常之物，乃是从西域专程千里运送来的重沙，比寻常铁砂都要沉重许多，
而犯人被这种重沙添埋至胸口，便大多吐血身亡。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//  "north" : __DIR__"qszl",
  "south" : __DIR__"tbzm",
]));
        set("objects", ([
        __DIR__"npc/guard5": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",0);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
        replace_program(ROOM);
}
