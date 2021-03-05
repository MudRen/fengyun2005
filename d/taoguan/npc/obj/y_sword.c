#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    	set_name("黄木剑", ({ "sword" }) );
    	set_weight(1000);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
	        set("unit", "把");
	        set("long","这是一把黄杨木雕成的剑，闻起来有一股香味，剑身刻著许多你从未见过的咒文。\n");
	        set("value", 800);
	        set("material", "wood");
	        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	        set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	        set("weapon_prop/spirituality", 1);
	        set("for_taoist",1);
    }
    ::init_sword(15);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        if(query("exorcising"))
        	return ;

        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > (int)victim->query("atman")/2 ) {
                        damage = me->query_spi()/2;
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY "黄木剑发出一股青色的罡气，流遍$N的全身。\n"NOR;
                }
                return random(me->query_spi());
        }
}
 
