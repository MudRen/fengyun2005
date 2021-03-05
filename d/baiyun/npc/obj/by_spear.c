// spear.c

#include <weapon.h>
inherit SPEAR;

	void create() {
    	set_name("钩连枪", ({ "spear" }) );
    	set_weight(50000);
	if(clonep())
		set_default_object(__FILE__);
	else {
	        set("unit", "柄");
	        set("long", "这是一杆东海渔人便于捕猎而打造的铁枪。\n");
	        set("value", 1000);
		set("material", "steel");
        	set("wield_msg", "$N把$n牢牢地握在手中，耍了个枪花。\n");
        	set("unwield_msg", "$N放下手中的$n。\n");
	}
    	::init_spear(15);
}
