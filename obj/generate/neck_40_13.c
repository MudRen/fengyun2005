#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(HIR"吉祥护符"NOR, ({ "necklace"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 3);
		set("armor_prop/strength", 3);
		set("armor_prop/intelligence", 3);
		set("armor_prop/composure", 15);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 3);
		set("armor_prop/karma", 3);
		set("armor_prop/max_gin", 40);
		set("armor_prop/max_kee", 50);
		set("armor_prop/max_sen", 40);
		set("long","一个小小的香囊，保佑你吉祥平安。\n");	// 已废弃
			set("value", 400000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_neck();
}

// 凝輕·dancing_faery@hotmail.com

