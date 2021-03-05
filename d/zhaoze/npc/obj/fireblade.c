#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name( HIR "火焰长刀" NOR, ({ "fireblade" }) );
	set_weight(7000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "把");
	    set("long",	"一把非金非木，通体暗红的长刀。\n");
	    set("red_dragon_bane",1);
	    set("value", 0);
	    set("material", "steel");
	    set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	    set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	
	::init_blade(15);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	
	dam = (int) me->query("force");
	if(!userp(me))
	{
		victim->receive_wound("kee",100, me);
		return HIR "火焰长刀喷出一股猩红的火焰，燎烤着$n的全身。\n" NOR;
	}
}
 
