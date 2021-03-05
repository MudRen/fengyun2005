// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "大松树");
        set("long", @LONG
一棵大松树。
LONG
        );
 	set("objects", ([
		__DIR__"obj/musicbird": 1,
	]) );
	set("exits", ([
		"down" : __DIR__"yard",
	]));
    	set("no_magic",1);
    	set("no_fly",1);
    	set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-35);
	set("coor/z",40);
	setup();
}

void reset()
{
	object bird;

	::reset();
	if(bird=present("music bird",this_object()))
		bird->delete("idling");
}

void init()
{
	object me,bird;


	if(userp(me=this_player())&&bird=present("music bird",this_object()))
	{
		remove_call_out("idling");
		call_out("idling",30,bird);
	}
	add_action("do_catch","catch");
}

void idling(object bird)
{
	if(!objectp(bird) || bird->query("idling")) {
		return ;
	}
	bird->set("idling",1);
	message_vision(HIG"棕嗓鹛轻轻叫了几声，好像叮叮的泉水转过山岩。
棕嗓鹛发出一串悠扬顿挫的叫声，好像是一首你熟悉的曲子。
忽然，你身边传来几声少女的娇笑。你大吃一惊，仔细看时，周围又没有人。 \n"NOR,bird);
	return ;
}



int catch_bird(object me,object bird)
{
	int gin,kee,sen;
	if(me->query_temp("mbescape"))
	{
		message_vision("$N咬了咬牙，蹬着树枝开始往上爬，要把棕嗓鹛再捉回来。
忽然，“咔嚓”一声，$N脚下的松枝断了！
$N急忙飞身，伸脚点向树干，偏偏踩在青苔上！\n",me);
		message_vision("\n“轰”的一声，$N摔了下来。
$N摔得很重，动都动不了了。 \n",me);
		me->start_busy(10);
		gin=me->query("max_gin")*5/100;
		kee=me->query("max_kee")*5/100;
		sen=me->query("max_sen")*5/100;
		me->set("eff_gin",gin);
		me->set("eff_kee",kee);
		me->set("eff_sen",sen);
		me->set("gin",gin);
		me->set("kee",kee);
		me->set("sen",sen);
		me->set("marks/无悔",2);
		if(bird)
	me->start_call_out( (: call_other, bird, "event3", me, 0 :), 1);
		me->delete_temp("mbescape");
		me->move("/d/huangshan/yard");
		bird->move("/d/huangshan/yard");
		return 1;
	}


/*	if(random(5))
	{
		message_vision("$N机灵地跳在一边，一展翅膀，忽的飞走了。 \n",this_object());
		destruct(this_object());
		return 1;
	}
*/
	message_vision(HIY"$N轻手轻脚地摸过去，想捉$n。
$n正在低头梳理羽毛，没有注意$N。$N一冲上前，把$n抓到手里。 \n"NOR,me,bird);
	bird->move(me);
	me->start_call_out( (: call_other, bird, "event1", me, 0 :), 1);
}

int do_catch(string arg)
{
	object ob,me,bird;

	me=this_player();
	bird=present("music bird",this_object());

	if(!arg)
		return 0;
	ob=present(arg,this_object());
	if(!ob)
		return 0;
	if(ob!=bird)
		return 0;
	if(!bird->query("idling"))
	{
		message_vision("$N轻手轻脚地摸过去，想捉$n。 \n",me,bird);
		message_vision("$N机灵地跳在一边，一展翅膀，忽的飞走了。 \n",bird);
		destruct(bird);
	}
	else
		catch_bird(me,bird);
	return 1;
}

int invalid_leave(object me)
{
	object bird;

	if(bird=present("music bird",me))
	{
		message_vision(HIR"$N忽然在$n的手上一啄，$n只觉疼痛钻心，不由得放开了$N。\n"NOR,bird,me);
		message_vision(HIG"$N振了振翅膀，一下子就飞得无影无踪了。\n"NOR,bird);
		destruct(bird);
	}

}

int valid_leave(object me,string dir)
{
	object bird;

	if(dir!="down")
		return 0;
	if(bird=present("music bird",this_object()))
	if(me->query_temp("mbescape"))
	{
		message_vision("$N虽然听棕嗓鹛的话，可是并没有后悔，转身爬下树去。 \n",me);
		me->start_call_out( (: call_other, bird, "event4", me :), 1);
		me->set("marks/无悔",1);
		me->delete_temp("mbescape");
	}
	return 1;
}
				