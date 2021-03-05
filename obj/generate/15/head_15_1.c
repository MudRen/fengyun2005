#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(CYN"飞鸟发簪"NOR, ({ "clasp"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 20);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","一根银质发簪，簪头飞鸟雕得栩栩如生。\n");	// 已废弃
	}
	::init_head();
}
