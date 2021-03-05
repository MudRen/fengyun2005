#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
        set_name(HIG"黯香魂"NOR, ({ "soul" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("nodrop_weapon",1);
				set("no_get",1);
                set("unit", "把");
                set("material", "iron");
        }
        ::init_sword(20);
}

