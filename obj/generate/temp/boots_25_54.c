#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(MAG"五行鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 3);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","画有五行花纹的鞋子，能让人变得敏捷。\n");	// 已废弃
	}
	::init_boots();
}
