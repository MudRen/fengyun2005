#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("鬼降物品", ({ "ghost item", "item"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "块");
        	set("long","黑漆漆一股腐气，已经无法看出原来的样子了。\n");
        	set("value", 0);
    	}
    	::init_item();
}
