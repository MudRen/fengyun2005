// seaside.c
inherit ROOM;
void create()
{
        set("short", "常春岛渡口");
        set("long", @LONG
但见岛上椰林高耸，四下佳木葱茏，果然不愧为常春之岛。海滩上满是洁白的
细沙。一脚踩上，柔柔的细沙从脚趾间渗出来，漫到脚面上，就好象踩在棉花上一
样。海面上上下天光，一碧万顷，令你忘却了人间的凶杀阴险之事。一条小路曲曲
折折，返向山峰。北面是常春岛的客驿留云馆，南面礁石密布，地势颇为险峻。
LONG
        );
        set("exits", ([ 
		  "north" : __DIR__"cloudinn",
          "south" : __DIR__"rock0",
          "east"  : __DIR__"uproad0",
		]));
        set("outdoors", "tieflag");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);	
/*	set("coor/x",1920);
	set("coor/y",-210);
	set("coor/z",40);*/
	setup();
}
void pipe_notify()
{
//      object ob;

        message("vision","一阵尖锐哨声响自岸边，划破了天地间的静寂，传达到远方。\n" , this_object() );
		call_out("boat_come",5);
}
void boat_come()
{
	object boat;
//	object woman;
	object *inv;
	object /*who,*/ oob;
	int i;
	
	if (query("exits/down")) return;
	if (!objectp(boat=find_object(__DIR__"boat")))
		boat=load_object(__DIR__"boat");
	inv=all_inventory(boat);
	if (!(oob=present("old boater",boat)) || boat->query("exits/up")|| !living(oob))
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
	boat->set("exits/up",__DIR__"island");
	set("exits/down",__DIR__"boat");
	call_out("boat_leave",10,boat);
}
void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","老婆子长篙一点，渔舟就离开了海岸。\n",this_object()); 
	boat->set_temp("mark/dest","mainland");
	message("vision","老婆子长篙一点，渔舟就离开了海岸。\n",boat);
	boat->boat_run(0);
}