#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"幽冥紫晶"NOR, ({"amethist", "stone", "purple stone"}));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "块");
				set("long", "一块紫色的晶石。仔细看时，有丝丝幽幽的紫光在其中流动。\n"); 
            	set("value", 200);
				set("imbue", 1);
        }
	::init_item();
}


