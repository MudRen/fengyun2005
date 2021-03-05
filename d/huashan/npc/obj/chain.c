// tea_leaf.c

#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( "铁链", ({ "chain" }) );
		set("long","一条系（tie）鹰用的细细的黑色铁链，
似乎竟是玄铁做的。 \n");
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 0);
                set("material", "steel");
        }
        ::init_whip(10);
}
