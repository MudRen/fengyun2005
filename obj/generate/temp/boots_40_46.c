#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(RED"赤云鞋"NOR, ({ "shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 30);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 0);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 5);
		set("armor_prop/karma", 2);
		set("armor_prop/max_gin", 30);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 60);
		set("long","描绘着红色纹路的鞋子，不只能提升速度，也可以带来幸运。\n");	// 已废弃
	}
	::init_boots();
}
