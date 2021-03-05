// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("笔", ({ "bi" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "这是一支看起相当普通的笔，但通身漆黑。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(25);
}
