#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"白菊丝罗帕"NOR, ({"handkerchief", "luo pa"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "条");
	    set("long", "一条白色的丝罗帕，上面的一角绣着一朵可爱的白色小菊花。\n");
	    set("value", 100);
	}
	::init_item();
}



