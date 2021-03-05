// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "甬路");
        set("long", @LONG
一条窄而高的通道，似乎完全用坚硬的花岗岩打造的。
LONG
        );
        set("exits", ([ 
 			"northup" : __DIR__"changjing",
  			"southup" : __DIR__"daxiong",
		]));
        set("objects", ([
            __DIR__"npc/monka" : 1,
  			__DIR__"npc/monkb" : 1,
			__DIR__"npc/monkc" : 1,
			__DIR__"npc/monkf" : 1,
			__DIR__"npc/monke" : 1,
			__DIR__"npc/monkf" : 1,
			__DIR__"npc/monkg" : 1,
			__DIR__"npc/monkh" : 1,
			__DIR__"npc/monki" : 1,
			__DIR__"npc/monkj" : 1,
			__DIR__"npc/monkk" : 1,
       ]) );
		set("coor/x",0);
		set("coor/y",-40);
		set("coor/z",-10);
		setup();
}


int valid_leave(object me, string dir)
{
	object ob;

	if (F_LEVEL->get_level(me->query("combat_exp"))>=45){
		if (objectp(ob=present("shaolin monk")) && me->query("vendetta/shaolin")>=1)
			ob->ccommand("say 师弟们暂且退下，将这贼子放进去关门打狗。");
		return ::valid_leave(me,dir);
	}
		
	if( userp(me) && dir=="northup" && ob=present("shaolin monk", this_object())
			&& me->query("vendetta/shaolin")>=1)
		return notify_fail("和尚喝道:贼子止步!\n");	
	
	if( userp(me) &&
		dir=="northup" && ob=present("shaolin monk", this_object())
		&& me->query("family/family_name") != "少林寺")
		return notify_fail( "和尚说道：这位施主，非少林弟子不可再往前走了！\n");
		return 1;
}


/*
void reset()
{
	object *inv, ob;
	int i ;
	::reset();
	ob = present("meng yi", this_object());
	if (!ob)	return;
		
	
	ob->set("chat_chance_combat",50);
	ob->dismiss_team();
	inv = all_inventory();

	for(i=0 ;i < sizeof(inv);i++)
	if(inv[i]->query("id") == "shaolin monk" && inv[i]!= ob)
		{
			if (i<7 ) ob->add_team_member(inv[i]);
		}
	}
}
*/