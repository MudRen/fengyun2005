#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create() {
	set_name("魔力盾牌", ({"magic shield", "shield" }));
    	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
		set("long", "晶莹的盾牌上有一层五彩光芒旋转流动，令人眩目。\n");
		set("value", 5000);
		set("armor_prop/armor", 10);
		set("armor_prop/parry", 3);
		set("block_rate",1000);
		set("block_level",100);
	}
	::init_shield();
}


