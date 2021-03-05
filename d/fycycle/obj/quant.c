#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( "船桨", ({ "quant" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 100);
                set("material", "wood");
	        set("wield_msg", "$N拿出一把$n握在手中，当做武器。\n");
       		set("unwield_msg", "$N将手中的$n收了起来。\n");
        }
        ::init_staff(10);

}

