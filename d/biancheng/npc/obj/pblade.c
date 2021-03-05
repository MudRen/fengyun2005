#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name("杀猪刀", ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1);
		set("long","一把明晃晃的杀猪刀。\n");
		set("material", "iron");
		set("wield_msg", "$N抽出一把明晃晃的$n捏在手中。\n");
		set("unequip_msg", "$N将手中的$n放入口袋里。\n");
	}
	::init_blade(10);
}
