#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"腊梅"NOR, ({"lamei","wintersweet" }) );
	set_weight(100);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "枝");
	    set("long", "朵朵腊梅盛开，清香扑鼻。\n");
	    set("value", 10);
	}
	::init_item();
}



