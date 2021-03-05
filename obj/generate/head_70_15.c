#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIB"飞鸟发簪"NOR, ({ "clasp"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 50);
		set("armor_prop/armor", 10);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 25);
		set("armor_prop/composure", 5);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 5);
		set("armor_prop/max_gin", 500);
		set("armor_prop/max_kee", 220);
		set("armor_prop/max_sen", 500);
		set("long","簪头是一只栩栩如生的飞鸟。\n");	// 已废弃
			set("value", 700000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_head();
}

// 凝輕·dancing_faery@hotmail.com

