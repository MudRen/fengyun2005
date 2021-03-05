// seaside2.c

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "碧蓝海边");
        set("long", @LONG
转过一个弯，你眼前骤然一宽，无边无际的大海就在眼前了。海风拂面，一洗
过往旅客的一路劳顿。海风清凉，略有点咸味，海面微微泛着波浪。碧蓝的海水上
面涌动洁白的浪花，海面飘着轻轻的薄雾。路边是一片的灌木丛，树木不高却很密，
黑漆漆地看不清背后有没有路。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"seaside",
  		"south" : __DIR__"lin1",

	]));
        set("outdoors", "tieflag");
	set("coor/x",1000);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}

int valid_enter(object me)
{
	if(me->query("lovestory1/epilogue")) return 1;
	if(this_object()->query("lovestory1_epilogue")) return 1;
	
//	if(random(10)) 
	this_object()->set("lovestory1_epilogue",1);
	me->set("lovestory1/epilogue",2);
	me->set_temp("lovestory1_epilogue",1);
	remove_call_out("lovestory1_epilogue");
	call_out("lovestory1_epilogue",5+random(5),me,1);
	return 1;
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
	boat->set("exits/up",__DIR__"seaside2");
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

int lovestory1_epilogue(object me,int count)
{
	object girl;
	
	if((!me)||(!living(me))||(!present(me,this_object())))
		return 0;
	
	switch(count){
	case 1:
		message_vision(WHT"黎明的海滩，蒸发的水气凝成了一片迷雾，弥漫在你的眼前。\n"NOR,me);
		break;
	case 2:
		tell_object(me,"在隐隐约约的迷雾之中，你仿佛看见了一位"HIW"白衣"NOR"女子。\n");
		girl=new("/questnpc/lovestory1/whitegirl");
		girl->move(this_object());
		set("lovestory1_char",girl);
		break;
	case 3:
		girl=query("lovestory1_char");
		girl->ccommand("emote 轻轻的叹了一声，似乎有着无尽的忧伤。");
		girl->leave_room(me);
		break;
	case 4:
		this_object()->delete("lovestory1_epilogue");
		me->delete_temp("lovestory1_epilogue");
		me->set("lovestory1/epilogue",1);
		return 1;
	}
	call_out("lovestory1_epilogue",5+random(5),me,count+1);
	return 1;
}
		
		
