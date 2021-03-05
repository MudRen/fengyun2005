// maple_leaf

#include <weapon.h>
#include <ansi.h>

inherit ITEM;


void create()
{
	set_name(HIR"五角枫叶"NOR, ({ "maple leaf", "leaf" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一片绚丽的枫叶。\n");
		set("unit", "片");
		set("weight",1);
		set("value", 1);
	}
	set("castable",1);
	::init_item();
}
