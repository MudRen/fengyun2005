#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(CYN"青尼服"NOR, ({ "cyan cloth" }) );
	set_weight(1000);
	set("long", "一件粗布尼服，染成淡淡的青色。\n");
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
