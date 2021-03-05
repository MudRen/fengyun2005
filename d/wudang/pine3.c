
inherit ROOM;

void create()
{
	set("short", "松林");
	set("long", @LONG
茂密的松林，不时能见到几只松鼠在树上跳来跳去。虽然只有几丝阳光能透林
而入，却不显得阴森可怖。习习凉风不时迎面吹来，使人浑身舒畅。使你想躺在这
里，睡上一觉。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"road2",
	]));

	 set("objects", ([
//			__DIR__"npc/oldtaoist1" : 1,
			__DIR__"npc/oldtaoist2" : 1,
			__DIR__"npc/oldtaoist3" : 1,
			__DIR__"npc/oldtaoist4" : 1,
			__DIR__"npc/oldtaoist5" : 1,
			__DIR__"npc/oldtaoist6" : 1,
			__DIR__"npc/oldtaoist7" : 1,
   ]) );

	set("no_lu_letter",1);
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",-40);
	setup();
}


void reset()
{
	object *inv, ob;
	int i;
	::reset();
	ob=present("taoist elder", this_object());
	
	inv = all_inventory();
	if(ob)
	{
			ob->dismiss_team();
			for(i=0;i<sizeof(inv);i++)
	        if(inv[i]->query("id") == "taoist elder" && inv[i] != ob)
				ob->add_team_member(inv[i]);
	}
}

