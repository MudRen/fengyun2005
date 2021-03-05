
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("烟斗", ({ "yandou" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "一支长长的旱烟斗。\n");
		set("value", 200);
		set("material", "iron");
		set("rigidity", 10);
		set("wield_msg", "$N拿出一支$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	::init_hammer(3);
}
