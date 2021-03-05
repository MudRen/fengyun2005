#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void do_eatflower();

void create()
{
	set_name(HIY"越橘"NOR, ({ "bilberry" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一堆小星也似的越橘。\n");
		set("unit", "堆");
		set("base_unit","个");
		set("base_value", 10);
		set("food_remaining", 3);
		set("food_supply", 10);
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("material", "bone");
		set("eat_func", (: do_eatflower :) );
	}
	set_amount(1);
	::init_throwing(1);
}


void do_eatflower()
{
	object me;
	me = this_player();
	tell_object(me,HIB"微酸的越橘咬在嘴里，你只觉得越吃越饿。\n"NOR);
	me->add("food",-100);

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
