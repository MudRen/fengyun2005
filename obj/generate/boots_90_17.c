#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(HIR"血殷鞋"NOR, ({ "shoes"}) );
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
		set("armor_prop/armor", 6);
		set("armor_prop/strength", 6);
		set("armor_prop/intelligence", 6);
		set("armor_prop/composure", 6);
		set("armor_prop/agility", 30);
		set("armor_prop/karma", 6);
		set("armor_prop/max_gin", 88);
		set("armor_prop/max_kee", 110);
		set("armor_prop/max_sen", 88);
		set("long","沾血的此鞋据说带有诅咒的不祥之力。\n");	// 已废弃
			set("value", 900000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_boots();
}

// 凝輕·dancing_faery@hotmail.com

