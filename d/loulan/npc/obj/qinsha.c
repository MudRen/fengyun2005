#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(GRN"翠色轻纱"+RED"红罗裙"NOR, ({ "qingsha" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("long", "一件薄得不能再薄，透得不能再透的翠色轻纱红罗裙。\n");
		set("material", "cloth");
		set("value", 5);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
