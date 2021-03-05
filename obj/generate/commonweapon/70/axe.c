#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create() {
	set_name(HIR"烈皇无究"NOR, ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 800000);
		set("weapon_prop/attack",35);
		set("level_required",70);
		set("material", "iron");
		set("wield_msg", "$N从背后抽出$n，试了试重量，然後握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	::init_axe(70);
}
