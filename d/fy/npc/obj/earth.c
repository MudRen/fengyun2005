#include <ansi.h>
inherit ITEM;
void create()
{
    	set_name(YEL"秦岭粘土"NOR, ({ "clay"}) );
    	set_weight(500);
    	set_max_encumbrance(1000);
		set("skull_make",1);
    	if( clonep() )
    		set_default_object(__FILE__);
    	else {
        	set("unit", "块");
        	set("long", "西域的粘土，是做瓷器的上好材料。\n");
        	set("value", 200000);
    	}
    	::init_item();
}

