#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIW"素色宫装"NOR, ({ "gongqun" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("long", "一件动人的素色宫装。\n");
		set("material", "cloth");
		set("value", 5);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
