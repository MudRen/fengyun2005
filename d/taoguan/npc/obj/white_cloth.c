#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("轻丝白衣", ({ "silk cloth" }) );
	set_weight(1000);
	set("long", "一件轻丝白衣，轻柔得就如同天鹅的羽毛。\n");
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
