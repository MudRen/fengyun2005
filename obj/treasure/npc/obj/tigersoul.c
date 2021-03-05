#include <weapon.h>
#include <ansi.h>
inherit HAMMER;	
void create()
{
        set_name(HIB"战虎之魄"NOR, ({ "tiger soul","soul" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是从昔年蚩尤的战虎身上提炼出的百炼之魄，不灭之精。\n");
        	set("rigidity", 5000);

                set("value", 1);

                set("material", "iron");
				set("desc_ext","祭炼武器(120)");
				set("weapon_material",1);
				set("material_level",120);

        }

        ::init_hammer(20);
}
