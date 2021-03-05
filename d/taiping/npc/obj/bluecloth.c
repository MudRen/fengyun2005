#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("蓝衣", ({ "blue cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件蓝色的紧身衣靠，袖口用白线绣着“七海山庄”四个字。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",100);
	}
	::init_cloth();
}
