// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("塔公铁", ({ "takon iron" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块沉重发亮的大铁块。\n");
				set("rigidity", 300);
                set("value", 0);

				set("weapon_material",1);
				set("material_level",47);
				set("desc_ext","祭炼武器(47)");
                set("material", "heavyiron");
        }

        ::init_hammer(10);
}
