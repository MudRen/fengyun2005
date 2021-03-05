#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("长刀", ({ "long blade","blade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把长长的刀，刀长四尺，宽三分。\n");
                set("value", 200);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(15);
}
