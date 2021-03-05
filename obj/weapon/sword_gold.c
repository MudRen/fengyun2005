#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIY"金剑"NOR, ({ "goldsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把与干将,莫邪齐名的上古神兵。\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从宝玉剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的宝玉剑鞘。\n");
	}
	::init_sword(70);
}

