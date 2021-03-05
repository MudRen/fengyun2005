
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(BLK"斩鬼刀"NOR, ({ "ghost blade","blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把刀身狭长漆黑的胡刀，闪烁着晦暗的血光。\n");
                set("value", 800);
                set("material", "steel");
        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_blade(20);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        if( victim->is_zombie())
        {
                victim->receive_wound("gin",random(me->query("mana")*50));
                return HIR "骤然间斩鬼刀突然放射出万道光华,肆意流转,摄人心魄...\n"NOR;        
        }
        if( victim->is_ghost() ) {
                if( random(me->query("max_mana")) > (int)victim->query("mana")/5 ) {
                        damage = me->query_spi();
                        victim->receive_wound("gin", damage*10);
                        victim->receive_wound("sen", damage*10);
                        me->receive_heal("kee", damage*5);
                        me->receive_heal("sen", damage*5);
                        victim->receive_wound("kee", damage*10);
                        return HIY "斩鬼刀骤然放射出万道金光,肆意流转,摄人心魄,却使$N觉地浑身如沐春风,舒泰万分...\n"NOR;
                }
                return random(me->query_spi());
        }
}

