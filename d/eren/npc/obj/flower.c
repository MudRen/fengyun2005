inherit ITEM;
#include <ansi.h>
void create()
{
  set_name("七枝一叶花",({ "flower" }) );
  if( clonep() )
                set_default_object(__FILE__);
        else {
	  	  	set("wanchunliu",1);
	  	  	set("value",10);
	  	  	set("no_drop",1);
	  		set("unit","朵");
	  		set("long", "一朵看上去十分普通的野花，散发着奇异的香味。\n");
       	}
}
