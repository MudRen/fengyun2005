#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("蓝缎长袍", ({ "blue cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件用丝绸织成的蓝色长袍，一看就是有钱人穿的。");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",10);
	}
	::init_cloth();
}
