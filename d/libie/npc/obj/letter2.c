#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("南宫十二郎的信", ({ "letter", "信"}) );
        set_weight(50);
        set("for_di",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("value", 0);
                                set("long",
"这是封便条，上书：
      所托之务已办妥。
      
      			南宫十二郎"NOR);
        }
	::init_item();
}
