#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
    	set_name(CYN"温柔"NOR, ({ "paper dagger","dagger" }) );
    	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "有影无踪、有形无质、其快如电、柔如发丝，这柄其薄如纸的刀，就叫温柔。\n");
        set("value", 4);
        set("level_required", 30);	
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
    	init_dagger(60);
}
