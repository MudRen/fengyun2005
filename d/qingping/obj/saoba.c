
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("扫把" , ({ "saoba", "扫把" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "破旧的扫把。\n");
		set("value", 10);
		set("rigidity", 5);
		set("material", "wood");
		set("wield_msg", "$N拿出一把破旧的木$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(5);
}
