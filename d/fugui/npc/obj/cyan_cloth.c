#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIC"相公袍"NOR, ({ "shayi" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "时下非常流行的一种华丽服饰，奶油小生的最爱。\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
