#include <weapon.h>
inherit STAFF;

void create() {
	set_name("没有鱼线的钓鱼竿", ({ "fishpole" }) );
	set_weight(2000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根细细的钓鱼竿，奇怪的是没有缠鱼线。\n");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
    ::init_staff(10);
}
