#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(HIY"菩提法杖"NOR, ({ "puti staff", "staff" }) );
	set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("material", "wood");
		set("rigidity", 1000);
		set("value", 10000);
		set("long", "一根万载菩提木所制的法杖，坚逾金钢，可避百邪，据传乃是佛祖圣物。\n");
		set("wield_msg", "$N拿出一根$n握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	::init_staff(150);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam_m, dam_f, dam_a;
    dam_m = (int) me->query("mana");
    dam_f = (int)me->query("force");
    dam_a = (int)me->query("atman");
    if((int)victim->query("mana") > (int)victim->query("max_mana")*1/2){
    	victim->add("mana",-dam_m/5);
    	me->add("mana", dam_m/100);
    }
    
    if((int)victim->query("force") > (int)victim->query("max_force")*1/4){
    	victim->add("force", -dam_f/5);
    	me->add("force", dam_f/100);
    }
    if((int)victim->query("atman") > (int)victim->query("max_atman")*1/3){
    	victim->add("atman", -dam_a/5);
    	me->add("atman", dam_a/100);
    }
    return HIY"菩提法杖放射出万道金华，将$n浑身罩住，$n只觉浑身精力飞逝而去。。\n"NOR;
}
 
