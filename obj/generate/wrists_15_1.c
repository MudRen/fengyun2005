#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
	set_name(YEL"吉祥手镯"NOR, ({ "wrists"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("generate_item",1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 1);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 1);
		set("armor_prop/karma", 5);
		set("armor_prop/max_gin", 8);
		set("armor_prop/max_kee", 10);
		set("armor_prop/max_sen", 8);
//		set("long","描述\n");	// 已废弃
            set("value", 150000);
		set("no_sell", 1);
             set("no_pawn",1);
	}
	::init_wrists();
}
