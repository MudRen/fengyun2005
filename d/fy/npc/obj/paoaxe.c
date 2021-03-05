#include <weapon.h>
inherit AXE;

void create() {
	set_name("刨斧", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 1000);
		set("long", "木工用的一把小斧子。\n");
		set("material", "iron");
		set("wield_msg", "$N从背后抽出$n，握在手中摆了个架势。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_axe(20);
}
