
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name( HIG "玉环刀" NOR, ({ "yuhuan" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把通体深碧色的刀\n");
                set("value", 1200);
		set("rigidity", 200);
                set("material", "steel");
        set("wield_msg", "$N从刀鞘中抽出一把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回刀鞘中。\n");
        }
        ::init_blade(20);
}

