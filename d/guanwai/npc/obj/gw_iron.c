#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
	set_name(BLU "天山精铁块"NOR, ({ "rare iron" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块漆黑冰冷的天山精铁，隐隐的泛着蓝光。\n");
		set("value", 2000000);
		set("rigidity",2000);	
		set("material", "steel");
		set("max_enchant",6);
		set("for_create_weapon",1);
		set("base_damage",25);
	set("wield_msg", "$N从怀中摸出一块$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	}
	::init_dagger(25);
}
