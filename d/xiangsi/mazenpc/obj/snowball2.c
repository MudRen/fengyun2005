#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(WHT"大雪球"NOR, ({ "snowball"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一团没有化开的雪块。\n");
		set("unit", "堆");
		set("base_unit", "粒");
		set("volumn",10);
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(20);
	init_throwing(70);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (random(5))
		return 0;
	victim->force_busy(victim->query_busy()+1);
	return WHT"大雪球在$n身上碎开，$n但觉寒意彻骨．．\n"NOR;

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
