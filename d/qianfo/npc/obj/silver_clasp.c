#include <armor.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name( "银簪" , ({ "clasp" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 100);
                set("material", "silver");

                set("armor_prop/armor", 1);
                set("female_only", 1);
                set("wear_msg", "$N细心地将一支$n插在发髻上。\n");
                set("wield_msg", "$N将$n握在手中，当成一把匕首。\n");
        }
        ::init_dagger(10);
}
