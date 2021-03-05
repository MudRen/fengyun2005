#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create() {
	set_name(HIR"魔剑"NOR, ({ "sword" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("no_get",1);
		set("material", "iron");
		set("wield_msg", "$N抽出一把明晃晃的$n捏在手中。\n");
		set("unequip_msg", "$N将手中的$n放入口袋里。\n");
	}
	::init_sword(30);
}
