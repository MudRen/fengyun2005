
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("单管望远镜" , ({ "wyj", "telescope" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条黄铜打磨的单管望远镜。\n");
		set("value", 6200);
		set("wield_msg", "$N拿出一根黄铜打磨的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(15);
}
