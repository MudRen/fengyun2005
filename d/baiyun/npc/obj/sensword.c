#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIG"摇光"NOR, ({ "sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这把剑透体辉光，寒气湛然，一见即知并非凡物。\n");
        set("value", 200);
		set("material", "steel");
		set("no_get",1);
		set("nodrop_weapon",1);
	}
    ::init_sword(90);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

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

