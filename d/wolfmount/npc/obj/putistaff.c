#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"菩提法杖"NOR, ({ "putistaff", "puti staff", "staff" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("material", "wood");
		set("rigidity", 1000);
		set("experience",6000000);
		set("value", 10000);
		set("long", "一根万载菩提木所制的法杖，坚逾金钢，可避百邪，据传乃是佛祖圣物。\n");
		set("wield_msg", "金光闪耀，若同闪电划破长空，一柄$n跃现在$N手中。\n");
		set("unequip_msg", "金光一闪而逝，$N放下手中的$n。\n");
	}
	::init_staff(150);
}

int query_autoload() { return 1; }

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
    	int pro;
    	int dam_m, dam_f, dam_a;
    	
    	dam_m = (int) me->query("mana");
    	dam_f = (int)me->query ("force");
    	dam_a = (int)me->query ("atman");
    	
    	if((int)victim->query("mana") > dam_m/5){
    		victim->add("mana",-dam_m/5);
    		me->add("mana", dam_m/5);
    	}
        
        if((int)victim->query("force") > dam_f/5){
    		victim->add("force", -dam_f/5);
    		me->add("force", dam_f/5);
    	}
    	
    	if((int)victim->query("atman") > dam_a/5){
    		victim->add("atman", -dam_a/5);
    		me->add("atman", dam_a/5);
    	}
    	
    	if (me->query("mana")>2*me->query("max_mana")) me->set("mana",2*me->query("max_mana"));
    	if (me->query("atman")>2*me->query("max_atman")) me->set("atman",2*me->query("max_atman"));
    	if (me->query("force")>2*me->query("max_force")) me->set("force",2*me->query("max_force"));
    	
    	return HIY"菩提法杖放射出万道金华，将$n浑身罩住，$n只觉浑身精力飞逝而去。。\n"NOR;
}
 
*/

