#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("绯夜樱", ({"ye ying", "ye ju"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "朵");
	    set("long", "一朵绯夜樱。\n");
	    set("value", 10);
	}
	::init_item();
}



