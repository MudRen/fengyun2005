#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name("腰鼓", ({ "drum", "gu", "腰鼓" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 5);
		set("material", "wood");
		set("long", "一个缠着红丝带的腰鼓，可以用来击鼓（play drum）。\n");
	}
	::init_hammer(5);
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

   	if (!arg || (arg != "gu" && arg !="drum" && arg != "腰鼓")) {
      		return 0;
   	}
   	
	guard = present("guard",environment(me));
	if (guard && guard->query("group")=="baiyunzhuang") {
		message_vision(HIM"$N拿起鼓槌，咚咚地敲响了腰鼓，正是一曲“喜临门”。\n"NOR,me);
		if (!me->query_temp("baiyunzhuang")) {
			me->set_temp("baiyunzhuang",1);
		}
		message_vision(CYN"庄丁对$N说：“怎么这么晚才来，快进去吧，马上就要拜天地了！”\n"NOR,me);
	} else
		message_vision("$N拿起鼓槌，咚咚地敲响了腰鼓。\n",me);
   	return 1;
}
