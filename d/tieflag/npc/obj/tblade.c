// tblade.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIG"温柔一刀"NOR, ({ "tblade" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把明如秋水，薄似柳叶的弯刀\n"
);
                set("value", 0);
                set("material", "steel");
                set("rigidity", 1000000);
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/agility", 10); 
                set("weapon_prop/personality", 10);
                set("female_only", 1);
                set("no_get",1);
                set("no_drop",1);
        }

        ::init_blade(10);

}


void owner_is_killed(object killer)
{
        message_vision(HIG"\n \n 温柔 "NOR +"落在地上，转了几个圈子，忽然消失了。
\n\n");
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    return HIR "弯刀似月，映着$N人美如花，$n不由得痴了\n"NOR;
   
}
 
