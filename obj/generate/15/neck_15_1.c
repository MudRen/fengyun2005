#include <ansi.h>
#include <armor.h>

inherit NECK;

void create() {
	set_name(MAG"定心珠"NOR, ({ "necklace"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 10);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 1);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 0);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 10);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 20);
		set("long","一串紫色石子雕成的佛珠，据信有安心定神之效。\n");	// 已废弃
	}
	::init_neck();
}
