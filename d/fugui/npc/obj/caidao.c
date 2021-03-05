#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("菜刀", ({ "caidao","cai dao","dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 0);
		set("material", "iron");
		set("long", "这是一寻常的菜刀，农家厨房常见。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	::init_blade(5);
}
