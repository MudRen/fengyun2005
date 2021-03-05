#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_FOOD;

void create()
{
	set_name(YEL"无花果"NOR, ({ "fig" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一堆软得一捏就出水的无花果。\n");
		set("unit", "堆");
		set("base_unit","个");
		set("base_value", 30);
		set("food_remaining", 2);
		set("food_supply", 20);
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("material", "bone");
		set("volumn",10);
	}
	set_amount(10);
	::init_throwing(1);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	string tmp1;
	victim->add_temp("annie/fig", 1);
	if (victim->query_temp("annie/fig") < 4)
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"脸上糊着几点粘乎乎的无花果汁。");
	else
		victim->set_temp("body_print", gender_pronoun(victim->query("gender"))+"脸上糊满了粘乎乎的无花果汁。");
	return "只听啪嗒一声，无花果软软的粘到$n额上，汁液四溅。\n";
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
