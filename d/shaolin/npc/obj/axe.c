
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
	set_name("佛光斧头" , ({ "lightaxe", "axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把很不起眼的斧头，上书“佛光”\n");
		set("value", 600);
		set("material", "iron");
		set("wield_msg", "$N拿出一把雪亮的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_axe(43);
}
