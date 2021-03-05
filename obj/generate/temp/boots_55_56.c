#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(CYN"灵叶鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 40);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 3);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 6);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 10);
		set("armor_prop/max_kee", 90);
		set("armor_prop/max_sen", 90);
		set("long","一双轻如落叶的丝织小鞋。\n");	// 已废弃
	}
	::init_boots();
}
