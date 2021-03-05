#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(CYN"梅枝"NOR, ({ "plum branch","branch" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根极细的梅枝，枝上点着浅白色的花萼。\n");
                set("value", 0);
                set("material", "wood");
				set("nodrop_weapon",1);
        }
        ::init_staff(1);
}
