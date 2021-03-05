#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("铁钩", ({ "hook" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把黑沉沉的铁钩，里面似乎还有着机关！");
                set("value", 300);
                set("material", "steel");
        }
        ::init_sword(20);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(damage_bonus)>300) return;
        if (random(me->query_skill("sword")) > victim->query_skill("dodge"))
        	victim->receive_wound("kee",damage_bonus/5);
        	return this_object()->name()+ HIB "中突然打出一丛黑黑的牛毛细针！\n"NOR;
}
