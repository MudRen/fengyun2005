
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
	set_name("佛光木枪" , ({ "lightspear", "spear" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条很不起眼的木枪，上书“佛光”\n");
		set("value", 600);
		set("material", "wood");
		set("wield_msg", "$N拿出一条乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_spear(33);
}
