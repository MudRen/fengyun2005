// pink_cloth.c

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(YEL"黄色的短衫"NOR, ({ "yellow shirt", "shirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件黄色的布衫，衫角及膝。 \n");
		set("unit", "件");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}

