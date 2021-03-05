//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("卡你瓦依衣", ({ "cotton shirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件白色的布衣，领子上还绣着花儿。\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
