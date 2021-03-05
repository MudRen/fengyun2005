// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(HIB"两生花"NOR, ({"rebirth flower", "flower" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一朵生长在高山绝壁之上，聚天地精魂而开的"HIB"两生花"NOR"。\n");
		set("unit", "朵");
		set("real_flower",1);
		set("no_drop",1);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("eat_func", (: do_eatflower :) );
	}
    ::init_item();
}

void do_eatflower()
{
	object me;
	me = this_player();
	if (!random(10))
	{
		// 落花流水春去也：Rebirth
		tell_object(me,HIB"
你轻轻的把两生花放到口中，不待咀嚼，它已经化作一股冰凉
流下了你的喉咙。那刺骨的寒凛，让你不由自主的打了一个寒
战，似是身处北国的严冬。忽而冰天雪地之中又有一点一点的
暖意慢慢升起，聚集，到了后来，竟汇成一道暖流，沁进了你
的心中。\n"NOR);
		me->set("timer/lifesave",time());
	}
}