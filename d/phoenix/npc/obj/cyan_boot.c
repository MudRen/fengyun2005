#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(BLU"行空短靴"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("lore",1);
		set("material", "cloth");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("no_stack",1);
		set("male_only", 1);
		set("level_required", 75);
		set("armor_prop/armor", 0);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 40);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 700);
		set("long","一双用硝过的小牛皮制成的黑色短靴。\n");	// 已废弃
	}
	::init_boots();
}

// 凝輕·dancing_faery@hotmail.com

