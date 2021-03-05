#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(WHT"莳罗须香囊"NOR, ({ "necklace"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 9);
		set("armor_prop/strength", 9);
		set("armor_prop/intelligence", 9);
		set("armor_prop/composure", 45);
		set("armor_prop/constitutionx", 5);	// 已废弃
		set("armor_prop/agility", 9);
		set("armor_prop/karma", 9);
		set("armor_prop/max_gin", 136);
		set("armor_prop/max_kee", 170);
		set("armor_prop/max_sen", 136);
		set("long","散发着淡淡的香气，有安定心灵的力量。\n");	// 已废弃
			set("value", 1500000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_neck();
}

// 凝輕·dancing_faery@hotmail.com

