// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("乌铁块", ({ "tiekuai" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块沉重的黑铁块。\n");
				set("rigidity", 500);
                set("value", 10000);
                set("material", "iron");

			set("weapon_material",1);
			set("material_level",12);
			set("desc_ext","祭炼武器(12)");

        }

        ::init_hammer(10);
}
