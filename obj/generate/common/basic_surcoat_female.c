#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(MAG"短披风"NOR, ({ "surcoat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value",300);	// 有value，允许在用过后卖回商店；但建议设立前期保管处进行保存。
		set("generate_item_common",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 0);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", -10);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", -20);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 100);
		set("armor_prop/max_sen", 0);
		set("long","母亲常常为女儿织的小披风。\n");	// 已废弃
	}
	::init_surcoat();
}

// 凝輕·dancing_faery@hotmail.com

