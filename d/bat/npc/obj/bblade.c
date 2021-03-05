#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(RED "滴血刀" NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);
		set("material", "iron");
		set("long", "这是一把充满邪气和杀机的钢刀。\n");
		set("wield_msg", "$N抽出一把暗红色的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	::init_blade(15);
}
