#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("玉石", ({ "jade" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "块");
            	set("for_create_ring",1);
               	set("material", "jade");
            	set("long","一块奇异的的玉石，是打造饰物的好材料。\n");
    		set("riddle_award",1);
    		set("value",20);
        }
        ::init_item();
}
