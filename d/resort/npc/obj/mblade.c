
#include <weapon.h>
#include <ansi.h>
inherit BLADE;


void create()
{
        set_name("垓下刀", ({ "wangblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把轻如雪片，快如闪电的宝刀。\n");
                set("value", 200);
		set("rigidity", 200);
                set("material", "steel");
        }
        init_blade(30);

        set("wield_msg", "$N从乌皮刀鞘中抽出一把杀气逼人的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回乌皮刀鞘中。\n");


}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
	if(damage_bonus < 300 ) return 0;
        badint = 
        victim->query_skill("sword") * 10;
        if(badint && victim->query_temp("weapon") && 
	victim->query_skill_mapped("sword") == "doomsword")
        message_vision( HIR "$N人刀合一，手中的"+name()+ HIR "突然切入$n的破绽！\n" NOR,me,victim);
        return badint;
}

*/