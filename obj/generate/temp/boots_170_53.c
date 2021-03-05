#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR"火晶履"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 135);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 9);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 9);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 21);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 370);
		set("armor_prop/max_sen", 0);
		set("long","以稀有的天山火晶雕成的鞋子，价值连城。\n");	// 已废弃
	}
	::init_boots();
}
