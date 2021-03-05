#include <weapon.h>
inherit BLADE;

void create() {
	set_name("铁尺", ({ "ruler" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "iron");
		set("long", "这是一把公差们常用的铁尺，刃口磨的锃亮。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n捏在手中。\n");
		set("unequip_msg", "$N将手中的$n放入口袋里。\n");
	}
	::init_blade(10);
}
