#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name(HIR"沥泉神枪"NOR, ({ "yue spear","spear" }) );
        set_weight(90000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                      
"一杆长约一丈三尺的蘸金钢枪,枪杆上赫然刻着“沥泉神枪”四个字，
竟是当年怒发冲冠,踏破贺兰山阙，一代名帅岳飞那柄无敌天下的神兵！\n\n"
);
                set("value", 0);
                set("no_stack",1);
                set("no_drop",1);
                set("material", "steel");
                set("level_required",30);
                set("wield_msg", "$N「唰」地一声擎出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n挂回腰后。\n");
        }
        ::init_spear(40);

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam;
	dam = (int) me->query("max_force")/40;
	dam = COMBAT_D->magic_modifier(me, victim, "gin", dam);
	victim->receive_damage("gin",dam,me);
    return HIR"沥泉神枪似巨蟒吐信上下翻滚，漫天血芒使$n魂飞魄散，精疲力尽。\n"NOR;
}

