#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("寒玉床", ({ "jasper bed"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "张");
	set("desc", "一块长条的青白玉石，床上只铺了张草席，一幅白布当作薄被（laydown）\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","o");
	set("size",1);
	set("tax",80);
	set("score_tax",10);
	set("value", 2000000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_laydown","laydown");
}


int do_laydown(string arg)
{
	   object me, obj, girl;
	   int gin, kee, sen;
		mapping buff;
		function f;
	
	   me = this_player();
	   obj = this_object();
	   if (!environment(me)->is_owner(me->query("id")))
			return notify_fail("屋子里的物件只有主人才能使用。\n");
	   if (me->is_fighting() || me->is_busy()) {
	   		tell_object(me,"你现在正忙着呢。\n");
	   		return 1;
	   }
	   if (query_temp("marks/taken")) {
	      tell_object(me, "床上有人耶．．．．\n");
	      return 1;
	   }
	  message_vision("$N缓缓躺在寒玉床上。\n", me);
	  tell_object(me, "你只觉彻骨冰凉，寒气逼人。\n");
	  set_temp("marks/taken", 1);
	  me->perform_busy(5);
	  call_out("curePlayer",10,me);
      return 1;
}

void curePlayer(object me)
{
	if (!me) return;
	set_temp("marks/taken", 0);
	if (environment(me) == environment())
	{
		tell_object(me,WHT"你慢慢觉得寒气渐去，感觉心头愈来愈暖，丹田之中气息流转不停。\n "NOR);
		if(me->query("eff_kee") != me->query("max_kee"))
		{
			tell_object(me,WHT"你身上的伤势竟神奇般地好了！\n"NOR);
			me->set("eff_kee",me->query("max_kee"));
		}
		message_vision("$N从床上缓缓坐了起来。\n",me);
	}
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
