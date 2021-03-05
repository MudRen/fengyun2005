// tblade.c
#include <ansi.h> 
#include <weapon.h> 
inherit SWORD;
void create()
{
        set_name( GRN "流星蝴蝶剑"NOR, ({ "hudie-sword" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","一把很普通很平凡的剑，唯一引人注目的是剑尖镶嵌了一粒宝石，有如流星\n划过夜空。\n");
                set("wield_msg", HIG"剑光乍起，有似流星，短促但灿烂，$N微笑地望着手中流星蝴蝶剑，\n但见剑光下似乎彩蝶飞舞，百花绽放，绚烂无比。\n"NOR);
                set("unwield_msg", HIG"$N微微一笑，缓缓将流星蝴蝶剑插入鞘中。\n"NOR);
                set("value", 0);
                set("material", "steel");
        }
        ::init_sword(60);
}

mixed hit_ob(object me, object victim,int extra,int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_atman")/10;
        extra = (int)me->query_skill("diesword",1);
        
        if(extra>100 && me->query("class")=="legend" && !random(2)
        	&& !victim->query("boss") && !victim->query("big_boss"))
        {
         	victim->receive_damage("sen",dam, me);
            victim->force_busy(random(5));
            return HIG "流星一闪，那一瞬间的辉煌却灿烂而永恒，$n"HIG"不禁心神俱醉。。\n" NOR;
         }
          else
         {
             me->receive_wound("kee",dam,victim);
             me->perform_busy(2);
             return HIY "$N只觉眼前星光伴彩蝶共舞，愈旋愈快，无法控制。\n" NOR;
         }
}

