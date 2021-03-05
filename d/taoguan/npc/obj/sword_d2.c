// sword.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("璺剑王夫", ({ "sword" }) );			// 丁白云.
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",                      
"这是一把桃木雕成的古剑，闻起来有一股香味，剑身刻著许多你从未见过的咒
文，只有剑柄部份有两个依稀可以辨认的篆字：「 王 夫 」
（斩鬼符效用x1.2）\n");
                set("value", 18000);
                set("material", "wood");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	        set("weapon_prop/spirituality", 10);
	        set("for_taoist",1);
	        set("ex_eff",120);
	        set("combat_exp",6400000);
        }
        ::init_sword(25);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
	
	if(query("exorcising"))
        	return ;

        if( victim->is_ghost() ) {
                if( random(me->query("max_atman")) > (int)victim->query("atman")/2 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage);
                        me->receive_heal("gin", damage);
                        me->receive_heal("kee", damage);
                        me->receive_heal("sen", damage);
                        return HIY "王夫剑发出一股金色的罡气，流遍$N的全身。\n"NOR;
                }
                return random(me->query_spi());
        }
}
