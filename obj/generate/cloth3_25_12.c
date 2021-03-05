#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name(WHT"云衬道袍"NOR, ({ "cloth"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
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
		set("long","绘有云霞花纹，道姑所爱使用。\n");	// 已废弃
			set("value", 250000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_cloth();
}

// 凝輕·dancing_faery@hotmail.com

