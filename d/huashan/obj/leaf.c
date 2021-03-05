#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("白果树叶", ({"ginkgo leaf", "baiguo leaf"}) );
	set_weight(5);
	if( clonep() )
  	  set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个碧绿色的扇形叶片。\n");
	    set("value", 1);
	}
	::init_item();
}



