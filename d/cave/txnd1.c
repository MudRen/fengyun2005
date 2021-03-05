// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "天西南道");
        set("long", @LONG
南边就是洞壁，石壁坑洼不平但相当的陡峭，根本不可以攀
登。洞壁上有几只火把和蜡烛，把这里照得通亮。这里周围似乎
有个饭庄，但每天飘荡着却都是令人作呕的血腥之气。。
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
        set("coor/x",-38);
        set("coor/y",-24);
        set("coor/z",-20); 
//        set("refresh_all_items", 1);
	setup();

}


int valid_leave(object obj, string dir){
	object another;
	seteuid(getuid());
	
	if(dir == "west" && !obj->query("vendetta/authority")){
		if (present("killer q", this_object()))
		{
			another = present("killer q", this_object());
			return notify_fail(another->name()+"闪身挡住了你的路。\n");
		} else if (random(10)>7) {
			another = new(__DIR__"npc/killer_q");
			another->move(environment(obj));
			message_vision(HIB"路边黑影一闪!\n"NOR, obj);	
			return notify_fail(another->name()+"喝道，什么人敢私闯青龙会，拿命来！\n");
		}
	}	
	return 1;
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

