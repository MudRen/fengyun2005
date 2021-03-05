#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(WHT"狐踪鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("female_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 1);
		set("armor_prop/composure", 2);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","传说穿上这双鞋就能变得与狐狸一样敏捷。\n");	// 已废弃
	}
	::init_boots();
}
