#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIG"仙人刺"NOR, ({ "cactus needle","needle" }) );
	set_weight(35);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一根仙人掌上摘下的乳白色刺针。\n");
		set("unit", "把");
		set("base_unit","根");
		set("wield_msg", "$N将$n握在手中当武器。\n");
		set("level_required",50);
		set("material", "bone");
		set("volumn",10);
	}
	set_amount(10);
	::init_throwing(65);
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
