#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIR"心剑"NOR, ({ "heartsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "剑无灵性，不过是凡铁而已，真正的剑士，剑就是人，人就是剑.\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N气定神闲，整个人似乎成了一把出鞘的剑.\n");
		set("unwield_msg", "$N身上那股无形的剑气消失了。\n");
	}
	::init_sword(120);
}

