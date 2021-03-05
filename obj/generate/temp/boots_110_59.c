#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(WHT"鸿爪鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 19);
		set("armor_prop/karma", 6);
		set("armor_prop/max_gin", 10);
		set("armor_prop/max_kee", 140);
		set("armor_prop/max_sen", 0);
		set("long","鸿爪鞋是踏雪鞋的改进版本，更为优质。\n");	// 已废弃
	}
	::init_boots();
}
