#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
	set_name( WHT"雪龙鞭"NOR, ({ "whip" }) );
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 1000);
		set("long","一条散发着奇异光芒的鞭子。\n");
		set("material", "skin");        
		set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n束在腰间。\n");
	}
	::init_whip(20);
}

