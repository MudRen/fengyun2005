#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIY"九龙戏珠鞭"NOR, ({ "dragon whip","whip" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 150);
                set("long", "一条镶满宝石，用鳄鱼皮制成的鞭子。\n");
                set("material", "skin");
		set("rigidity", 10000);
        	set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        	set("unwield_msg", "$N将手中的$n束在腰间。\n");
        }

        ::init_whip(20);
}


