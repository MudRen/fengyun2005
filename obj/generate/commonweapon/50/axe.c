#include <weapon.h>
inherit AXE;

void create() {
	set_name("菩提斧", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 200000);
		set("weapon_prop/attack",25);
		set("level_required",40);
		set("material", "iron");
		set("wield_msg", "$N从背后抽出$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_axe(50);
}
