
#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name("粉红袄", ({ "pink cloth","cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件粉红色的小棉袄，说它是棉袄，可比肚兜还小。\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}
