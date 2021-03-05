#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(WHT"短打背心"NOR, ({ "coat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 20);
		set("armor_prop/armor", 4);
		set("armor_prop/strength", 10);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 1);	// 已废弃
		set("armor_prop/agility", 2);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 24);
		set("armor_prop/max_kee", 30);
		set("armor_prop/max_sen", 24);
		set("value", 250000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_surcoat();
}

// 凝輕·dancing_faery@hotmail.com

