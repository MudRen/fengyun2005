#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(YEL"罡气冑"NOR, ({ "armor"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 18);
		set("armor_prop/strength", 45);
		set("armor_prop/intelligence", 9);
		set("armor_prop/composure", 9);
		set("armor_prop/constitutionx", 8);	// 已废弃
		set("armor_prop/agility", 9);
		set("armor_prop/karma", 9);
		set("armor_prop/max_gin", 136);
		set("armor_prop/max_kee", 170);
		set("armor_prop/max_sen", 136);
		set("value", 1500000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_surcoat();
}

// 凝輕·dancing_faery@hotmail.com

