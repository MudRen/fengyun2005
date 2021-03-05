#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIG"林字服"NOR, ({ "cloth" }) );
	set_weight(1000);
	set("long", "黑色道服，上面用白丝线绣着个“林“字。\n");
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
