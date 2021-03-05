#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(BLK"乌铁护腕"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("1_only", 1);
		set("level_required", 40);
		set("armor_prop/armor", 4);
		set("armor_prop/strength", 4);
		set("armor_prop/intelligence", 4);
		set("armor_prop/composure", 4);
		set("armor_prop/constitutionx", 3);	// 已废弃
		set("armor_prop/agility", 4);
		set("armor_prop/karma", 20);
		set("armor_prop/max_gin", 56);
		set("armor_prop/max_kee", 70);
		set("armor_prop/max_sen", 56);
//		set("long","描述\n");	// 已废弃
             set("value", 550000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_wrists();
}

// 凝輕·dancing_faery@hotmail.com

