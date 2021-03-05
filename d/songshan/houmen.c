// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "少林后山门");
        set("long", @LONG
少林的后门，几个壮年僧人把守此处，此门平时不开，只有当有弟子闯过木人
巷，闯出少林时才会大开后门，表示庆祝，从这里出去，你便是江湖上一等一的高
手了：

		放眼天下英雄，舍我其谁！

LONG
        );
        set("exits", ([ 
		
  		"west" : AREA_SONGSHAN"talin",
  		"in":	AREA_MAZE"sl-entry",
	]));
        set("objects", ([
                __DIR__"npc/monk21" : 1,
                __DIR__"npc/monk22" : 1,
                __DIR__"npc/monk23" : 1,
                __DIR__"npc/monk24" : 1,
                __DIR__"npc/monk25" : 1,
                __DIR__"npc/monk26" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",67);
	set("coor/y",25);
	set("coor/z",0);
	setup();
}

/*
void reset()
{
	object *inv, ob;
	string *sname=({"一幻","一第","一茵","一寐",
	"一空","一园","一少","一林","一寺","一第","一十"});
	int i,j;
	::reset();
	j=1;
	ob=present("shaolin monk", this_object());
	if(ob) ob->set("name","一幻");
//	if(ob) ob->set("chat_chance_combat",10);
	
	inv = all_inventory();
	if(ob)
	{
	ob->dismiss_team();
	for(i=0;i<sizeof(inv);i++)
	        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
	        {
			if(j<=3) ob->add_team_member(inv[i]);
		        inv[i]->set("name",sname[j]);
		        j++;
	        }
	}
}

*/