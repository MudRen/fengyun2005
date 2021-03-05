#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIR BLK"鸿爪鞋"NOR, ({ "boots" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("generate_item",1);
		set("lore",1);
		set("level_required", 80);
		set("armor_prop/armor", 7);
		set("armor_prop/agility", 30);
		set("armor_prop/dodge", 10);
		set("armor_prop/max_gin", 90);
		set("armor_prop/max_kee", 90);
		set("armor_prop/max_sen", 90);

	}
	::init_boots();
}


