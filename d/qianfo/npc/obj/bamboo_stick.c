// bamboo_stick.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("竹杖", ({"stick", "bamboo stick"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根泛着淡淡青光的竹杖。\n");
		set("value", 100);
		set("material", "bamboo");
		set("wield_msg", "$N抽出一根青光闪闪的竹杖握在手中。\n");
		set("unwield_msg", "$N把手中的竹杖插回腰中。\n");
	}
	::init_staff(15);
}	
