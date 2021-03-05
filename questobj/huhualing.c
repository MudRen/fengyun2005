#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( RED "护花铃" NOR, ({ "huhualing" }) );
        set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        set("value", 0);
		set("material", "leather");
		set("rigidity", 70);
                set("long", "一条金线之上，两端各系有一双金色的小铃。昔年，汉献帝爱花成性，唯恐飞雀残花，\n便在宫园中的花木上，系了无数金铃，只要雀鸟一落花上，金铃之声大震，而宫廷中\n的护花使者，便即会来驱鸟。当时京朝中人，将这金铃称为‘护花铃’，后来诗人，\n也作有『十万金铃常护花』之句。后人以之赠送爱侣，一旦一方遇险，则花铃共振，\n另一方立可徇声而至！\n");
                set("wield_msg", "$N从怀间取出一条$n，握在掌中，铃声清越可闻。\n");
                set("unwield_msg", "$N将手中的$n藏入怀中。\n");
	}
    init_whip(20);
}


mixed hit_ob(object me, object victim)
{
       if (me->query_cps()+ me->query_int()+ random(me->query_kar()) 
       		> victim->query_cps()+ victim->query_int() + random(victim->query_kar())
       		&& !victim->query("boss") && !victim->query("big_boss")
       		&& random(2))
        {
     		victim->force_busy(3);
     		return HIY "护花铃叮当作响，宛如天籁之音，不禁令$n"HIY"心驰神往，身形渐缓。\n" NOR;
        }
        else
        {
     		me->perform_busy(4);
     		return HIB "护花铃叮当作响，宛如天籁之音，但$n"HIB"凝神定气，不为所动。\n" NOR;
        }
}
