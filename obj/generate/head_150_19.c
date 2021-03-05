#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
	set_name(HIR"彩虹云冠"NOR, ({ "coronal"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("generate_item",1);
		set("lore",1);
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 18);
		set("armor_prop/strength", 9);
		set("armor_prop/intelligence", 45);
		set("armor_prop/composure", 9);
		set("armor_prop/constitutionx", 7);	// 已废弃
		set("armor_prop/agility", 9);
		set("armor_prop/karma", 9);
		set("armor_prop/max_gin", 900);
		set("armor_prop/max_kee", 420);
		set("armor_prop/max_sen", 900);
		set("long","这是一顶漂亮的。\n");	// 已废弃
			set("value", 1500000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_head();
}

// 凝輕·dancing_faery@hotmail.com

