#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(CYN"淡青色道袍"NOR, ({ "cloth" }) );
	set_weight(1000);
	set("long", "淡青色的道袍，做工考究，衣袖上绣着一个“丁”字。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 1000);
	}
	::init_cloth();
}
