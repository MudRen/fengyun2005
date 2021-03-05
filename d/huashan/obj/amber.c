#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"琥珀"NOR, ({"amber", "hupo"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个晶莹剔透的琥珀发出淡淡的黄色。\n");
	    set("value", 10000);
	    set("inc", 1);
	}
	::init_item();
}



