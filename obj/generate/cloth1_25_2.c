#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(HIY"罗汉袈裟"NOR, ({ "jiasha"}) );
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
		set("armor_prop/armor", 25);
		set("armor_prop/strength", 2);
		set("armor_prop/intelligence", 2);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 2);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 70);
		set("armor_prop/max_kee", 200);
		set("armor_prop/max_sen", 70);
		set("value", 250000);
		set("no_sell", 1);
             set("no_pawn",1);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

