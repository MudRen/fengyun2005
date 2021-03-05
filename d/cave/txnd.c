// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "天西南道");
        set("long", @LONG
南边就是洞壁，石壁坑洼不平但相当的陡峭，根本不可以攀登。洞壁上有几只
火把和蜡烛，把这里照得通亮。这里周围似乎有个饭庄，但每天飘荡着却都是令人
作呕的血腥之气。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xnj",
  "east" : __DIR__"xnm",
]));
        set("objects", ([
        __DIR__"npc/devilwaiter": 1,
//        __DIR__"obj/slayedman": 2,
                        ]) );
        set("indoors", "cave");
	set("coor/x",2);
	set("coor/y",-14);
	set("coor/z",0);
	setup();

}


void reset() {
	string item= "slayedman";
	int num = 2;
	object obj, *inv;
	
	:: reset();
	
	inv = all_inventory();
	foreach (object ob in inv) 
	{
		if (userp(ob)) continue;
		if (ob->query("id") == "slayed corpse") destruct(ob);
	}
	while (num--) 
	{
		obj = new(__DIR__"obj/"+item);
		obj->move(this_object());
	}
}

