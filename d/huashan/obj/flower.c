#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"小野菊"NOR, ({"daisy", "ye ju"}) );
	set_weight(20);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "朵");
	    set("long", "一朵嫩黄色的小野菊，散发着清雅的香气。\n");
	    set("value", 10);
	}
	::init_item();
}



