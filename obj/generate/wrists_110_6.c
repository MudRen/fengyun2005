#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(HIG"翡翠编串"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("1_only", 1);
		set("level_required", 90);
		set("armor_prop/armor", 7);
		set("armor_prop/strength", 7);
		set("armor_prop/intelligence", 7);
		set("armor_prop/composure", 7);
		set("armor_prop/constitutionx", 3);	// 已废弃
		set("armor_prop/agility", 7);
		set("armor_prop/karma", 35);
		set("armor_prop/max_gin", 104);
		set("armor_prop/max_kee", 130);
		set("armor_prop/max_sen", 104);
//		set("long","描述\n");	// 已废弃
             set("value", 1100000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_wrists();
}

// 凝輕·dancing_faery@hotmail.com

