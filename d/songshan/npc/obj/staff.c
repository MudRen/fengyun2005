// staff.c : Gun zi

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name("捉魂如意钩", ({ "zhuo hun gou" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把浸过毒的如意钩，里面似乎还有着机关！");
                set("value", 30);
                set("material", "steel");
        }
        ::init_staff(23, TWO_HANDED);
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (userp(me) || victim->query_condition("unknown"))	
		return;
	
	victim->apply_condition("unknown",random(5)+5);
        return HIR "$n似乎染上了捉魂如意钩上的毒！\n"NOR;
}

