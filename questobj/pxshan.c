#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name( GRN"踏月飘香扇"NOR , ({ "pxshan" }) );
    	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "柄");
        set("long", "这是柄相当雅致的折扇，扇骨描金，扇面洋洋洒洒写着『踏月而来』\n四字狂草，隐约散发着缥缈的郁金花香。\n");
        set("value", 0);
		set("material", "steel");
        set("wield_msg", "$N「唰」地一声把$n展开握在手中，徐徐扇了两下。\n");
		set("unwield_msg", "$N将手中的$n合起收入袖中。\n");
	}
        ::init_dagger(20);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
		int dam;
    	dam = (int) me->query("max_sen");
    	victim->receive_damage("sen",dam/100,me);
        return HIG "踏月飘香扇隐隐散发出一丝若有若无的郁金花香，缥缈柔和，清远淡泊。\n" NOR;
}
