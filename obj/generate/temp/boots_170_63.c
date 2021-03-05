#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR BLK"飞簷"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 135);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 33);
		set("armor_prop/karma", 11);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","来无影、去无踪，司空摘星曾苦苦追寻而不可得。\n");	// 已废弃
	}
	::init_boots();
}
