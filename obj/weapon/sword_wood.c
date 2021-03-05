#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIG"木剑"NOR, ({ "woodsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "普普通通的一把木剑。\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从背后抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入背上的剑鞘。\n");
	}
	::init_sword(90);
}
