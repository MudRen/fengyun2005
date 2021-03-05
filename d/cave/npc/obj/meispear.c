// spear.c
#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create() {
	set_name(HIY"落梅软藤矛"NOR, ({ "mei spear", "spear" }) );
	set_weight(10000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "矛身不知是用何材料做成的，坚硬中又有弹性。");
		set("value", 300000);
		set("rigidity", 2000);
		set("material", "steel");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_spear(10);
}
