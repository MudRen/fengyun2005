
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("七环禅杖" , ({ "7-ring staff", "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long","一条又粗又长的精铁禅杖，上面镶著七个铜环。\n");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(27);
}
