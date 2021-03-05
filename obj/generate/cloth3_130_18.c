#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(RED"风罩霞衣"NOR, ({ "cloth"}) );
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
		set("armor_prop/armor", 115);
		set("armor_prop/strength", 8);
		set("armor_prop/intelligence", 8);
		set("armor_prop/composure", 8);
		set("armor_prop/constitutionx", 7);	// 已废弃
		set("armor_prop/agility", 8);
		set("armor_prop/karma", 8);
		set("armor_prop/max_gin", 370);
		set("armor_prop/max_kee", 800);
		set("armor_prop/max_sen", 370);
		set("value", 1300000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

