// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(YEL"木屐"NOR, ({ "wood shoes","shoes" }) );
	set_weight(2000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "双");
	    set("material", "wood");
	    set("value", 1000);
	    set("long", "一双高齿乌木的木屐。\n");
	}
	::init_boots();
}
