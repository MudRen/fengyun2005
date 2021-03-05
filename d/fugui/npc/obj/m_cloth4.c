// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(MAG"玄色紧身劲装"NOR, ({ "magcloth" }) );

	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这衣服便于飞檐走壁，窃玉偷香。\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
