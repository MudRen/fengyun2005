#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(YEL"秘法发簪"NOR, ({ "clasp"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value",2000);	// 有value，允许在用过后卖回商店；但建议设立前期保管处进行保存。
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 12);
		set("armor_prop/armor", 6);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", -10);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", -5);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","藏宗秘法加护过的衣物，能保护主人免受伤害。\n");	// 已废弃
	}
	::init_head();
}

// 凝輕·dancing_faery@hotmail.com

