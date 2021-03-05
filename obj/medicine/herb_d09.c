
inherit MEDICINE;
#include <ansi.h>

void create()
{
	set_name("蓝花蛇草",({"shecao", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","簇");
	    set("material","herb");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("base_value",200);
	    set("volumn",10);
	    
	    set("type","poison");	
	    set("field","kee");
	    set("level",75);
	    set("effect",75);	    
	    set("proc", 50);	// Proc rate
	}
	set_amount(10);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{	
	int effect;
	string msg;
	object weapon = me->query_temp("weapon");
	if (!weapon || weapon->query_temp("herb_owner")!= me)	return "";
	
	if (weapon->query_temp("proc_rate")+ 25* ANNIE_D->check_buff(me,"khl-atk-stance")> random(100)) 
	{		
		effect = COMBAT_D->magic_modifier(me, victim, "kee",query("effect"));
		msg = HIB"$n伤口处一阵麻痒，似乎中了$N"+weapon->name()+ HIB"上的毒！\n"NOR;
		victim->receive_damage("kee",effect,me);
                return msg;
        } else
        	return "";
}
