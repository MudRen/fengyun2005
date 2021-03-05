#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create() {
	set_name(HIB"青蓝映雪"NOR, ({ "surcoat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 70);
		set("armor_prop/armor", 12);
		set("armor_prop/strength", 30);
		set("armor_prop/intelligence", 6);
		set("armor_prop/composure", 6);
		set("armor_prop/constitutionx", 2);	// 已废弃
		set("armor_prop/agility", 6);
		set("armor_prop/karma", 6);
		set("armor_prop/max_gin", 88);
		set("armor_prop/max_kee", 110);
		set("armor_prop/max_sen", 88);
		set("long","一件以宝蓝绸缎绣织的披风，珍贵无比。\n");	// 已废弃
			 set("value", 900000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_surcoat();
}

// 凝輕·dancing_faery@hotmail.com

