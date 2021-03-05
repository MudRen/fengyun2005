#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIG"青竹杖"NOR , ({ "bamboo staff", "staff" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根绿油油的青竹杖。\n");
		set("value", 2000);
		set("rigidity", 200);
		set("material", "iron");
		set("wield_msg", "$N拿出一根绿油油的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(10);
}
