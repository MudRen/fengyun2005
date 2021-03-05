#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR"炙盛靴"NOR, ({ "boots"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 70);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 4);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 16);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 40);
		set("long","鲜红色的炙盛靴能同时提高主人在各个方面的战斗能力。\n");	// 已废弃
	}
	::init_boots();
}
