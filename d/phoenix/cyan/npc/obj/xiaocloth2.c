#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(CYN"玄罗仙袖"NOR, ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件淡青色的丝线细细织就的长衣。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 4000);
	}
	::init_cloth();
}
