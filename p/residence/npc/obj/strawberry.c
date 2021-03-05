#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void create()
{
	set_name(HIR"草莓"NOR, ({ "strawberry" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一堆又软又甜的草莓。\n");
		set("unit", "堆");
		set("base_unit","个");
		set("base_value", 30);
		set("food_remaining", 4);
		set("food_supply", 80);
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("material", "bone");
	}
	set_amount(1);
	::init_throwing(4);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	victim->add_temp("annie/strawberry", 1);
	if (victim->query_temp("annie/strawberry") < 4)
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"脸上糊着几点粘乎乎的草莓汁。");
	else
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"脸上糊满了粘乎乎的草莓汁。");
	return "只听啪嗒一声，草莓软软的粘到$n额上，汁液四溅。\n";
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
