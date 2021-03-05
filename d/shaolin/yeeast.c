// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "掖门");
        set("long", @LONG
与山门外的掖门一样的硬山墙建筑，和八字墙搭配起来，虽然并不高大，却也
错落有致，下连马道，直通山门，马车可以直进此地，寺内所需要的物资用品多从
此处进入。    
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"beilou",
  		"southwest" : __DIR__"yonglu",
]));
        set("objects", ([
                __DIR__"obj/mache" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",-10);
	setup();
}


void reset()	{
	object ob1,ob2, con;
	object *inv;
	int i;
	
	::reset();
	ob1 = new(AREA_WANMEI"obj/vege");
	ob2 = new (AREA_WANMEI"obj/drywoods");
	
	con = present("mache",this_object());
	if (con)	{
		inv=all_inventory(con);
		if (sizeof(inv)) {
			for (i=0;i<sizeof(inv);i++)
			if (inv[i]->query("id")=="woods" || inv[i]->query("id")=="vegetable")
				destruct(inv[i]);
		}
		ob2->set_amount(random(5)+1);
		ob1->move(con);
		ob1 = new(AREA_WANMEI"obj/vege");
		ob1->move(con);
		ob1 = new(AREA_WANMEI"obj/vege");
		ob1->move(con); 
		ob2->move(con);
	}
}
