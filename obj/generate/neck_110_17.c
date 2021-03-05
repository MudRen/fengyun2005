#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(MAG"迷迭香袋"NOR, ({ "necklace"}) );
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
		set("armor_prop/armor", 7);
		set("armor_prop/strength", 7);
		set("armor_prop/intelligence", 7);
		set("armor_prop/composure", 35);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 7);
		set("armor_prop/karma", 7);
		set("armor_prop/max_gin", 104);
		set("armor_prop/max_kee", 130);
		set("armor_prop/max_sen", 104);
		set("long","迷迭香又称作海中之露，氤氲醉人。\n");	// 已废弃
			set("value", 1100000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_neck();
}

// 凝輕·dancing_faery@hotmail.com

