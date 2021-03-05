#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(BLU"道者披挂"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("both_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 11);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 70);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}
