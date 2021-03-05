#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name("无影神针", ({ "needle", "magic needle" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"有强大杀伤力的巨毒无比的无影神针。\n");
		set("unit", "把");
		set("base_unit", "支");
		set("base_weight", 1);
		set("base_value", 1);
		set("volumn",150);
	}
	set_amount(150);
	init_throwing(55);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->apply_condition("no_shadow",random(10)+10);
	message_vision("$N中了无影神针上的毒！\n", victim);
}

