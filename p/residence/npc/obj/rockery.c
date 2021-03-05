#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("假山", ({ "tiny rockery"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "座");
	set("desc", "一座小小的假山，倒也精致玲珑。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","l");
	set("outdoors",1);
	set("size",2);
	set("value", 400000);
set("tax",40);
set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_climb","climb");
}



int do_climb(string arg)
{
   	int	s, amount, da;
 	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (!arg)
		return 0;
	if (present(arg,env) != ob)
		return 0;
	if (me->is_fighting() || me->is_busy()) return 1;
   	me->perform_busy(1);
   	s = me->query_skill("move", 1);
	if(random(me->query("kar")) && me->query("kar")>11) 
	{
		if(s >= 80)
		{
			message_vision("\n$N向假山上爬去，轻轻松松攀到了山顶。\n", me);
			tell_object(me, "你的基本轻功好象没有什么长进。\n");
			return 1;
		} 
		if(random(s) >= 75) 
			message_vision("\n$N向假山上爬去，轻轻松松攀到了山顶。\n", me);
		else 
		{
			message_vision("\n$N向假山上爬去，磕磕碰碰了许久方爬到山顶。\n", me);
			tell_object(me, "你的基本轻功好象没有什么长进。\n");
			return 1;
		}
	  
		tell_object(me, "你的基本轻功好象长进了一些。\n");
		      		amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*5;
		if(amount < 1) amount = 1;
		me->improve_skill("move", amount);
		da = 30*20/(me->query_dur()+me->query_fle());
		da /= 2;
		me->set_temp("last_damage_from","爬山脱力而死。");
		me->receive_damage("kee", da);
   	} else {
      		message_vision("\n$N向假山上爬去，轻轻松松攀到了山腰。\n", me);
      		message_vision("\n$N一不留神从假山上滚了下来，跌得头破血流。\n", me);
			da = 30*20/(me->query_dur()+me->query_fle());
			me->set_temp("last_damage_from","爬山脱力而死。");
			me->receive_damage("kee", da);
        }
   	return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
