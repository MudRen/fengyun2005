// tblade.c
#include <ansi.h> 
#include <weapon.h> 
inherit SWORD;
void create()
{
        set_name(MAG"离别钩"NOR, ({ "leave hook" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把奇形怪状的兵刃。\n");
                set("wield_msg", "寒光一闪，$N手中就多了一把形状怪异的兵刃，你不禁打了个寒战。\n");
                set("unequip_msg", "$N将手中$n用布包好，收了起来。\n");
                set("fake_leavehook",1);
                set("lore",1);
                set("material", "steel");
                set("rigidity", 100000); 
        }
        ::init_sword(20);
}

