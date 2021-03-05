#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name(HIG"仙人掌"NOR, ({ "cactus" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "一株长相十分可爱的仙人掌，上面有些尖锐的刺针。\n");
		set("value", 10);
        set("material", "wood");
        set("wield_msg", "$N举起一株$n当作锤子使用。\n");
        set("unwield_msg", "$N放下手中的$n。\n");
		set("count",2);
    }
    ::init_hammer(30);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (!query("count")) return 0;
	add("count",-1);
	victim->receive_wound("kee", damage_bonus,me);
	if (query("count"))
		return HIG "仙人掌上的刺针扎进了$n的皮肤，痛得$n吱哇大叫。\n"NOR;
	else
		return HIG "仙人掌上的最后一些刺针扎进了$n的皮肤，痛得$n吱哇大叫。\n"NOR;
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

