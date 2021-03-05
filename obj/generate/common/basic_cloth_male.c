#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(BLU"风云开裆裤"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value",2400);	// 有value，允许在用过后卖回商店；但建议设立前期保管处进行保存。
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 0);
		set("armor_prop/armor", 5);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", -120);
		set("long","一件风云城中的小孩们爱用的衣物。\n");	// 已废弃
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

