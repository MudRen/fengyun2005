#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(BLU"魔眼剑"NOR, ({ "mageye sword","sword" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "把");
                set("long", "明亮如秋水般的剑锋上，只有一点暇疵，看来就像是一只魔眼。\n");
                set("value", 0);
                set("material", "steel");

        set("wield_msg", "$N从腰间抽出一把明如秋水的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_sword(10);
}
