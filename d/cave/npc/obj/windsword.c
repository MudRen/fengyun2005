#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( CYN "清风剑" NOR, ({ "wind sword","sword" }) );
    set_weight(7000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long","一把明如秋水的宝剑。\n");
        set("for_bandit",1);
        set("material", "steel");
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unequip_msg", "$N将手中的$n插入腰间剑鞘。\n");
	set("value", 200);

    }
    
    ::init_sword(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam;
    dam = (int) me->query("force");
    if((int)victim->query("sen") > (int)victim->query("max_sen")*3/4)
    victim->receive_damage("sen",dam/20);
    return CYN "清风剑仿佛如清风吹过，$n的心神不禁一荡。\n" NOR;
}
 
