#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(WHT"晨露之结"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("1_only", 1);
		set("level_required", 135);
		set("armor_prop/armor", 10);
		set("armor_prop/strength", 10);
		set("armor_prop/intelligence", 10);
		set("armor_prop/composure", 10);
		set("armor_prop/constitutionx", 4);	// 已废弃
		set("armor_prop/agility", 10);
		set("armor_prop/karma", 50);
		set("armor_prop/max_gin", 152);
		set("armor_prop/max_kee", 190);
		set("armor_prop/max_sen", 152);
//		set("long","描述\n");	// 已废弃
             set("value", 1700000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_wrists();
}

// 凝輕·dancing_faery@hotmail.com

