// buddha_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIY"金光禅杖"NOR, ({ "buddha staff", "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长，非常沈重的黄铜禅杖，上面镶著六个铜环。\n");
		set("value", 620);
		set("material", "brass");
		set("wield_msg", "$N拿出一根金光灿然的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(25);
}
