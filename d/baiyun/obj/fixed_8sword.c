#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	int i;
    set_name(HIC"天剑"NOR, ({ "sky sword","sword" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "柄");
                set("long", "由远古时的天外陨石打造的精铁之剑，为至尊至信至刚之剑，\n乃历代君王所持的王道之剑！\n");
                set("value", 0);
                set("rigidity",5000);   
                set("material", "steel");

			set("weapon_material",1);

        	set("material", "steel");
	}
    ::init_sword(10);
}
