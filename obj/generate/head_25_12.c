#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(BLU"乌蛮簪子"NOR, ({ "clasp"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 4);
		set("armor_prop/strength", 2);
		set("armor_prop/intelligence", 10);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 2);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 200);
		set("armor_prop/max_kee", 70);
		set("armor_prop/max_sen", 200);
		set("long","中原少见的乌蛮簪子。\n");	// 已废弃
			set("value", 250000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_head();
}

// 凝輕·dancing_faery@hotmail.com

