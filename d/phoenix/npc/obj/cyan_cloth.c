#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(CYN"明光长衣"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("lore",1);
		set("material", "cloth");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("no_stack",1);
		set("male_only", 1);
		set("level_required", 75);
		set("armor_prop/armor", 50);
		set("armor_prop/strength", 50);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 30);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 800);
		set("armor_prop/max_sen", 0);
//		set("long","描述\n");	// 已废弃
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

