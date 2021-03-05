// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("黑色劲装", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是风云城金狮镖局的招牌衣服。\n");
		set("value", 1);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
