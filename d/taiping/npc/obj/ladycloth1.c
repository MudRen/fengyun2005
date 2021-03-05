#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIG"翡翠撒花洋绉裙"NOR, ({ "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件翡翠色的撒花洋绉裙。\n");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value",100);
	}
	::init_cloth();
}
