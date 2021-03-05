#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(HIY"金背大砍刀"NOR, ({ "gold blade","blade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把沉甸甸的金背大砍刀。\n");
                set("value", 1000);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(10);
}
