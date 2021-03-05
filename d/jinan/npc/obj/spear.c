// spear.c
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create() {
	set_name(HIW"银枪"NOR, ({ "silver spear" }) );
	set_weight(20000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "红缨衬托着银色的长枪是那样的夺目。");
		set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_spear(20);
}
