#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"紫绣裙"NOR, ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件淡紫色的丝线细细织就的及地长裙。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value", 4000);
	}
	::init_cloth();
}
