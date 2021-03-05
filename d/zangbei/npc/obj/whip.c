#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "牧牛鞭", ({ "whip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long","藏族牧民赶牛马用的长鞭，非常结实。\n");
                set("value", 500);
                set("material", "skin");

        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
        }
        ::init_whip(10);
}


