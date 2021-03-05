#include <weapon.h>
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("小号", ({ "trumpet","小号" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 5);
		set("material", "wood");
		set("long", "一个缠着红丝带的小号，可以用来吹号（play trumpet）\n");
	}
	::init_item();
}

void init()
{
   	if( this_player()==environment())
   		add_action("do_play","play");
}


int do_play(string arg)
{
   	object me, guard;
   	me = this_player();

   	if (!arg || (arg != "trumpet" && arg != "小号")) {
      		return 0;
   	}
   	
	guard = present("guard",environment(me));
	if (guard && guard->query("group")=="baiyunzhuang") {
		message_vision(HIG"$N拿起小号，鼓起腮帮子嘟嘟地吹了起来，正是一曲“春上柳梢”。\n"NOR,me);
		if (!me->query_temp("baiyunzhuang")) {
			me->set_temp("baiyunzhuang",1);
		}
		message_vision(CYN"庄丁对$N说：“怎么这么晚才来，快进去吧，马上就要拜天地了！”\n"NOR,me);
	} else
		message_vision("$N拿起小号，鼓起腮帮子嘟嘟地吹了起来。\n",me);
   	return 1;
}