#include <ansi.h>
inherit ITEM;
string description();

void create()
{
        set_name("卷轴", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 1000);
        }
}


void init()
{
   	add_action("do_read","read");
}
    
int do_read(string arg)
{
    	object me;
    	mapping data;
    	me = this_player();
		me->set("name",CYN"琉璃"NOR);
    	return 1;
}
    