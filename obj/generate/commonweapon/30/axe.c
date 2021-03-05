#include <weapon.h>
inherit AXE;

void create() {
	set_name("断云斧", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 20000);
		set("weapon_prop/attack",15);
		set("level_required",20);
		set("material", "iron");
		set("wield_msg", "$N从背后抽出$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_axe(30);
}
