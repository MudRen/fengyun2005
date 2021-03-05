// seaside.c
inherit ROOM;
void create()
{
        set("short", "碧蓝海边");
        set("long", @LONG
转过一个弯，你眼前骤然一宽，无边无际的大海就在眼前了。海风拂面，一洗
过往旅客的一路劳顿。海风清凉，略有点咸味，海面微微泛着波浪。碧蓝的海水上
面涌动洁白的浪花，海面飘着轻轻的薄雾。茫茫的大海上没有一点帆影，极目远眺，
海天交界处蒙蒙一片，分不出哪里是海，哪里是天。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"searoad1",
		"south" : __DIR__"seaside2",

]));
        set("outdoors", "tieflag");
	set("coor/x",1000);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

void pipe_notify()
{
        object ob;

        message("vision","一阵尖锐哨声响自岸边，划破了天地间的静寂，传达到远方。\n" , this_object() );
		call_out("boat_come",5);
}

void boat_come()
{
	object boat;
	object woman;
	object *inv;
	object who, oob;
	int i;
	
	if (query("exits/down")) return;
	if (!objectp(boat=find_object(AREA_CHANGCHUN"boat")))
		boat=load_object(AREA_CHANGCHUN"boat");
	inv=all_inventory(boat);
	if (!(oob=present("old boater",boat)) || boat->query("exits/up") || !living(oob))
	{              
			message("vision","许久许久，海面上什么也没有出现。\n",this_object());
			return;
	}
	for (i=0;i<sizeof(inv);i++)
	    if (userp(inv[i]))
		{
			message("vision","许久许久，海面上什么也没有出现。\n",this_object());
			return;
		}
	message("vision","过了半晌，一艘渔船自雾中荡出，船上卓立着一个白发苍苍的老妇人，款款摇橹。\n",this_object());
	message("vision","老婆子说道：“上船吧！”\n",this_object());
	boat->set("exits/up",__DIR__"seaside");
	set("exits/down",AREA_CHANGCHUN"boat");
	call_out("boat_leave",10,boat);
}


void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","老婆子长篙一点，渔舟就离开了海岸。\n",this_object()); 
	boat->set_temp("mark/dest","island");
	message("vision","老婆子长篙一点，渔舟就离开了海岸。\n",boat);
	boat->boat_run(0);
}
