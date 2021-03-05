// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("符纸剑" , ({ "papersword","paper sword","sword","seal sword" }) );	
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",                      
"一把符纸糊成的剑，看起来毫无威力。\n");
                set("value", 10000);
                set("material", "paper");
	        set("for_taoist",1);
	        set("ex_eff",110);
	        set("combat_exp",6400000);
        }
        ::init_sword(25);
}


mixed hit_ob(object me, object victim)
{
	object weapon;
	string result;
	int extra;
	
	weapon=me->query_temp("weapon");
	
	if (!userp(me) && me->query("id")=="xin wang")
		extra = 200;
	
	if(!extra )	return ;
		
	result=HIR"符纸剑上的血色似乎又加深了一分．．．\n";
	if(victim->is_ghost())
	{
		victim->set("eff_sen",-100);
		victim->receive_wound("sen",100,me);
		result+=HIR+victim->name()+"凄厉的惨叫了一声，化为了灰烬。\n"NOR;
	}
	else if(victim->is_zombie())
	{
		victim->set("eff_sen",-100);
		victim->receive_wound("sen",100,me);
		result+=HIR+victim->name()+"凄厉的惨叫了一声，化为了一滩血水。\n"NOR;
	}
	else
	{
		victim->receive_wound("sen",extra,me);
		victim->receive_damage("sen",extra/2,me);
		result+=HIY"$n浑身如遭雷磔，神为之夺。\n"NOR;
		// 300 damage,geese@main hv 6k sen,顶住应该不难...*snicker
		// point master ding,2250 damage per hit! rascal ding
	}
	return result;
}

