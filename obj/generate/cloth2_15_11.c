#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(WHT"半雪长裙"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 10);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 1);
		set("armor_prop/karma", 1);
		set("armor_prop/max_gin", 20);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", 20);
		set("long","一件浅素色的长裙。\n");	// 已废弃
			set("value", 150000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

