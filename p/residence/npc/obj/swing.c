#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("秋千", ({ "swing"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "座");
	set("desc", "秋千用古藤挽就，虽然简陋，却别有情趣。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","l");
	set("outdoors",1);
	set("size",1);
	set("value", 200000);
set("tax",20);
set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_swing","swing");
}

int do_swing(string arg)
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
	if(random(me->query("kar")) && me->query("kar")>11 && s>=55 )
	{
		if(s >= 60)
		{
			message_vision("\n$N爬到秋千上，慢慢地开始荡起秋千，越荡越高。\n", me);
			tell_object(me, "你的基本轻功好象没有什么长进。\n");
			return 1;
		} 
		message_vision("\n秋千越荡越高，$N不由得紧紧抓住古藤。\n", me);
        tell_object(me, "你只觉得风从脚底掠过，人似乎要乘风飞去。\n");
	  
		amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*5;
		if(amount < 1) amount = 1;
		me->improve_skill("move", amount);
		da = 30*20/(me->query_dur()+me->query_fle());
		me->set_temp("last_damage_from","荡秋千摔死了。");
		me->receive_damage("kee", da);
   	} else {
      		message_vision("\n秋千越荡越高，$N一不留神从秋千上掉了下来。\n", me);
		    tell_object(me, "“砰！”你重重地摔在树根上，屁屁好痛哦！\n");
			da = 30*20/(me->query_dur()+me->query_fle());
			me->set_temp("last_damage_from","荡秋千摔死了。");
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
