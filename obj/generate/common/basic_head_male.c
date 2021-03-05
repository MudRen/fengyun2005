#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(CYN"小兜帽"NOR, ({ "cap"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("value",1000);	// 有value，允许在用过后卖回商店；但建议设立前期保管处进行保存。
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 0);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", -10);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", -20);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", 0);
		set("long","一个小小小兜帽，风云城中的小男孩人人都戴着。\n");	// 已废弃
	}
	::init_head();
}

// 凝輕·dancing_faery@hotmail.com

