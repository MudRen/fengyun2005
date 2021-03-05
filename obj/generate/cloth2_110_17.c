#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(CYN"飞絮外裙"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 100);
		set("armor_prop/strength", 7);
		set("armor_prop/intelligence", 7);
		set("armor_prop/composure", 7);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 7);
		set("armor_prop/karma", 7);
		set("armor_prop/max_gin", 320);
		set("armor_prop/max_kee", 700);
		set("armor_prop/max_sen", 320);
		set("value", 1100000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

