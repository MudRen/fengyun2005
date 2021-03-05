#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
	set_name(YEL"尖甲旋锋"NOR, ({ "sharp shoes","shoes"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("male_only", 1);
		set("level_required", 120);
		set("armor_prop/armor", 1);
		set("armor_prop/strength", 13);
		set("armor_prop/intelligence", 0);
		set("armor_prop/composure", 0);
		set("armor_prop/constitutionx", 0);	// 已废弃
		set("armor_prop/agility", 33);
		set("armor_prop/karma", 0);
		set("armor_prop/max_gin", 0);
		set("armor_prop/max_kee", 0);
		set("armor_prop/max_sen", 0);
		set("long","此鞋鞋尖锋锐无比，能在飞踢中致人死命。\n");	// 已废弃
	}
	::init_boots();
}
