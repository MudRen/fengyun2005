#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(YEL"神驼鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 3);
		set("armor_prop/constitutionx", 7);	// 已废弃
		set("armor_prop/agility", 27);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","走千山，行百峰，不能没有神驼鞋。\n");	// 已废弃
	}
	::init_boots();
}
