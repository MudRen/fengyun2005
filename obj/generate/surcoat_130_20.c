#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(BLU"深瑶羽衣"NOR, ({ "surcoat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 105);
		set("armor_prop/armor", 16);
		set("armor_prop/strength", 40);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 2);	// 已废弃
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 120);
		set("armor_prop/max_kee", 150);
		set("armor_prop/max_sen", 120);
		set("long","用靛蓝色羽毛织成的披风，无比美丽。\n");	// 已废弃
			set("value", 1300000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_surcoat();
}

// 凝輕·dancing_faery@hotmail.com

