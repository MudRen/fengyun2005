//COPYRIGHT (C) APSTONE, INC. 1998

#include <armor.h>
inherit HEAD;
void create()
{
	set_name("维吾尔花帽", ({ "cotton hat" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "一顶很有特色，又很好看的帽子。\n");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	::init_head();
}
