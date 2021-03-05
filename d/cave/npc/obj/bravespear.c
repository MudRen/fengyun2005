
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
      	set_name(HIC"银枪"NOR, ({ "yin spear","spear" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "一杆锋利而沉重异常的银枪。\n");
		set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N不知从什么地方摸出一把$n,「唰」地一声握在手中。\n");
		set("unwield_msg", "$N将手中的$n收起。\n");
	}
    ::init_spear(20);
}
