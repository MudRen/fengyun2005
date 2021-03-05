#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
	set_name(RED"夕影刀"NOR, ({ "cyin blade","blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1000);
		set("material", "flex");	// :>>....flex blade
		set("no_get",1);
	}
	::init_blade(77);
}

mixed hit_ob()
{
	return RED"夕影刀映出一片朦朦胧胧的淡霞泠光，让人目驰神醉。\n"NOR;
}
