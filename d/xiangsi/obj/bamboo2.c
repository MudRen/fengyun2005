#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIG"碧绿竹竿"NOR, ({ "bamboo" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根青碧中又透着一丝淡红色的竹竿。\n");
		set("value", 0);
		set("rigidity", 5);
        set("material", "wood");
        set("wield_msg", "$N拿出一根$n握在手中。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
		set("count",10+random(20));
    }
    ::init_staff(1);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int damage;
	if( random(me->query_kar()) < victim->query_kar()) return 0;
	if (query("count")<=0) return 0;
	add("count",-1);
	damage = me->query_kar();
	if (damage>40) damage = 40;
	victim->receive_wound("gin", damage*5);
	victim->receive_wound("sen", damage*5);
	victim->receive_wound("kee", damage*10);
	me->receive_heal("gin", damage*3);
	me->receive_heal("kee", damage*5);
	me->receive_heal("sen", damage*3);
	return HIG "碧绿竹竿上的血色一聚，却又慢慢的散了开去．．．\n"NOR;
}




/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

