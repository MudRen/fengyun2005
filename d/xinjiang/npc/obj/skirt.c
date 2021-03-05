//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("艾提拉斯裙", ({ "cotton skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件很漂亮的裙子，上面似乎还有淡淡的葡萄香味。\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}
