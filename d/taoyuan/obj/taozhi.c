#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("桃花枝", ({ "taozhi", "tao" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根上面开满粉红色花朵的枝条。\n");
		set("value", 5);
		set("rigidity", 5);
        set("material", "wood");
        set("wield_msg", "$N拿出一根上面开满粉红色花朵的$n握在手中。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
    }
    ::init_staff(5);
}



