
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("乌鞘长刀", ({ "black blade","blade" }) );
	set_weight(1000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "把");
	    set("long", "这是一把刃上有一个缺口的利器！\n");
	    set("value", 100);
		set("rigidity", 15000);
	    set("material", "steel");
	}
	::init_blade(20);
}

