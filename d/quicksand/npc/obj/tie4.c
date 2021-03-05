// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name("生铁块", ({ "shengkuai" }) );
    set_weight(50000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        	set("unit", "块");
        	set("long", "一块沉重发亮的生铁。\n");
    		set("rigidity", 200);
        	set("value", 80000);
        	set("material", "heavyiron");
			set("weapon_material",1);
			set("material_level",33);
			set("desc_ext","祭炼武器(33)");
    }
    
    ::init_hammer(15);
}
