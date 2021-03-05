#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create() {
	set_name(WHT"软玉盾"NOR, ({ "jade shield","shield" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
		set("value", 5000);
		set("long", "一块圆盾，色泽润和，非金非玉，击之铛然有声，纵是宝剑亦不能伤。\n");
		set("armor_prop/armor", 8);
		set("armor_prop/parry", 0);
		set("experience",5000000);
	}
	::init_shield();
}


int query_autoload() { return 1; }