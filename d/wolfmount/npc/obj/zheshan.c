#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name( "香摺扇" , ({ "zheshan" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当精致的摺扇，还飘散着香味．\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n展开握在手中扇了两下。\n");
		set("unwield_msg", "$N将手中的$n合起收入袖中。\n");
	}
	::init_blade(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
    if (userp(me))	return;
    dam = (int) me->query("max_kee");
    victim->receive_damage("kee",dam/10);
	return BLU "香摺扇中突然喷出一股黄烟，$n猝不及防，被烟罩住。\n"NOR;
	tell_object(me,"\n你突然觉得一阵眩晕，好象中了毒！\n\n");
}
