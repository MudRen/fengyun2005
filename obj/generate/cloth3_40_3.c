#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(CYN"三教道装"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 40);
		set("armor_prop/strength", 3);
		set("armor_prop/intelligence", 3);
		set("armor_prop/composure", 3);
		set("armor_prop/constitutionx", 2);	// 已废弃
		set("armor_prop/agility", 3);
		set("armor_prop/karma", 3);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 300);
		set("armor_prop/max_sen", 120);
		set("value", 400000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

