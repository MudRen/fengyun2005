#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("白果", ({"baiguo"}) );
	set_weight(5);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个白色有着坚硬外壳的果实。\n");
	    set("value", 10);
	}
	::init_item();
}



