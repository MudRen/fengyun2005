// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(HIB"石精"NOR, ({"herb", "石精" }) );
	set("no_shown", 1);
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("lore",1);
		set("long", "一株在石缝中长大的石精。\n");
		set("unit", "株");
		set("value", 100);
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
	message_vision("$N意犹未尽地舔了舔嘴唇。\n",me);
}