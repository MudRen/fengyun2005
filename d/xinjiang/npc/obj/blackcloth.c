//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("黑纱袍", ({ "black robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是件黑色的纱袍，上面有一股很恶心的气味！\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
