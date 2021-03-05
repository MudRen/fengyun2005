
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("乌木簪", ({ "black clip", "clip" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 2);
		set("material", "wood");
                set("wield_msg", "$N从头上拔下一根$n捏在手中。\n");
                set("unwield_msg", "$N把手中的$n插在头上。\n");
	}
        ::init_dagger(10);
}
