#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(BLU"神驼鞋"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 8);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/agility", 40);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
		set("value", 1300000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_boots();
}

// 凝輕·dancing_faery@hotmail.com

