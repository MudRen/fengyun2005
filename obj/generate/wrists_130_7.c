#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(GRN"青金手链"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("1_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 8);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 40);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
//		set("long","描述\n");	// 已废弃
             set("value", 1300000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_wrists();
}

// 凝輕·dancing_faery@hotmail.com

