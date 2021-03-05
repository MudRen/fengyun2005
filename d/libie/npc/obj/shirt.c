// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW"雪白绸衫"NOR, ({ "white cloth" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件一尘不染的雪白绸衣\n");
		set("material", "cloth");
		set("value", 4);
		set("armor_prop/armor", 5);
	}
	::init_cloth();
}
