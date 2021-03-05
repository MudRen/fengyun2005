// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("羊毛裙", ({ "skirt", "white skirt" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件雪白的羊毛裙上闻起来还有一股少女的幽香。\n");
		set("unit", "件");
		set("value", 6);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("female_only", 1);
	}
	::init_cloth();
}

