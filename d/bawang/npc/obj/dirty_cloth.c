//By clone        6/2001

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("脏布衣", ({ "dirty cloth","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "件");
		set("long", "这是老山东平时烹调时穿的布衣，上面到处是黑乎乎的油渍，散发
着一股油烟，烧鸡和臭汗混合在一起的怪异的味道。\n");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
