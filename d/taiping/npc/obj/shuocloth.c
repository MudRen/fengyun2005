#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIG"绿蓑衣"NOR, ({ "raincoat" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","这是一件打鱼人常穿的绿蓑衣。\n");
		set("material", "cloth");
		set("value",1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
