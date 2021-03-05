#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(HIY"闪雷手链"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("1_only", 1);
		set("level_required", 50);
		set("armor_prop/armor", 5);
		set("armor_prop/strength", 5);
		set("armor_prop/intelligence", 5);
		set("armor_prop/composure", 5);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 25);
		set("armor_prop/max_gin", 72);
		set("armor_prop/max_kee", 90);
		set("armor_prop/max_sen", 72);
//		set("long","描述\n");	// 已废弃
             set("value", 700000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_wrists();
}

// 凝輕·dancing_faery@hotmail.com

