// TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("铸铁块", ({ "zhukuai" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块沉重发亮的铸铁。\n");
				set("rigidity", 300);
                set("value", 40000);

				set("weapon_material",1);
				set("material_level",26);
				set("desc_ext","祭炼武器(26)");

                set("material", "heavyiron");
        }

        ::init_hammer(10);
}
