#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIG"水绿色的袍子"NOR, ({ "green cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 0);
	}
	::init_cloth();
}
