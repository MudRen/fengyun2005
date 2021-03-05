#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name("大树根", ({ "stump"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "又粗又大又重的老树根。\n");
                set("unit", "个");
                set("value", 1);
                set("weight",40000);
                set("material", "plant");
                set("wield_msg", "$N费力地举起一个$n抗在肩上。\n");
                set("unwield_msg", "$N把$n放了下来。\n");
		
        }
        	::init_hammer();

}


