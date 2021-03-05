// ; annie 07.2003
// dancing_faery@hotmail.com
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "黑雾之中");
        set("long", @LONG
你沉进了这一片黑暗迷茫的雾气里，雾中隐约带着几许腥气，似乎是
血的味道。四周影影绰绰的似乎有什么在活动，只是这里伸手不见五指，
对于周遭的环境，你根本看不清楚。
LONG
        );
	set("item_desc", ([
		"out" : "雾影重重，你什么也看不清楚。\n",
	]) );

	set("no_fly",1);
	setup();
}

// 这个档案需要处理多人进入问题、在call之前离开问题

int	valid_leave(object who, string dir)
{
	int i;
	object me,here=environment(who),*inv=all_inventory(here),room=load_object(__DIR__"dimroom");
	me = who;

	if (dir == "out")
	{
		if (present("lesser demon",here))
		{
			return notify_fail("凶骸拦住了唯一的出路．．．\n");
		}

		// now out.
		// 
		message_vision(CYN"\n你听到一阵笑声，有人在慢慢的鼓掌。\n"NOR,me);
		message_vision(CYN"一个声音道：不错，不错，果然精彩。\n"NOR,me);
		message_vision(CYN"你眼前的黑雾忽然散开，原来你还在小室之中，而辛望就站在你面前四尺之外。\n\n"NOR,me);
		for (i=0;i<sizeof(inv) ; i++)
			inv[i]->move(room);
		return notify_fail(" ");
	}
	return ::valid_leave(who,dir);
}


void init()
{
	object room,me;
	object *olist;
	int i;
	me = this_player();
	delete("exits");
	if (userp(me))
	{
		room = this_object();
		olist = all_inventory(room);
/*		for(i=0; i<sizeof(olist); i++)
			if (!userp(olist[i]))
				destruct(olist[i]);*/
		if (me->query_temp("annie/demon_xin_1",1))
			call_out("do_pil",2,me,room);
	}
	return;
}

void do_pil(object me,object room)
{
	if (!me || room != environment(me))
		return;
	message_vision(MAG"\n黑暗之中传来一阵令人毛骨悚然的低笑：嗯……正好\n还有几张幽冥招鬼符，就先让它们陪你活动活动筋骨吧！\n"NOR,me);
	message_vision(YEL"\n几张燃烧着的黄纸从半空中飘飘悠悠的落下。\n"NOR,me);
	call_out("do_next",2,me,room);
	return;
}

void do_next(object me,object room)
{
	object zombie;
	int i,j;
	if (!me || room != environment(me))
		return;
	message_vision(YEL"\n咒符余烬所落之处，阵阵白烟升腾而起。\n白烟散去，一群残肢断臂的死尸自迷雾中出现！！\n"NOR,me);
	j = 3+random(3);	// 3 - 5 zombies
	for(i=0; i<j; i++)
	{
		zombie = new(__DIR__"npc/lessdemon");
		zombie->move(room);
		zombie->kill_ob(me);
		me->kill_ob(zombie);
	}
	set("exits/out",__DIR__"dimroom");
	return;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

