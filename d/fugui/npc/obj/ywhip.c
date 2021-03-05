#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIR"游魂索"NOR, ({ "youhun whip","whip" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 100);
                set("material", "iron");
		set("rigidity", 60);
        set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
        }
        ::init_whip(20);

}


