// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( BLK"乌鞘马鞭"NOR, ({ "horse whip","whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
        	set("long", "一根长长的马鞭，鞭子上挂满了倒刺。\n");
                set("value", 500);
                set("material", "skin");
        	set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        	set("unwield_msg", "$N将手中的$n束在腰间。\n");
        }
        ::init_whip(10);

        

}

