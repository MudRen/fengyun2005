#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIG"风翼鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 4);	// 已废弃
		set("armor_prop/agility", 22);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 210);
		set("armor_prop/max_kee", 210);
		set("armor_prop/max_sen", 0);
		set("long","此鞋是苏蓉蓉为香帅所织，后来流落在外。\n");	// 已废弃
	}
	::init_boots();
}
