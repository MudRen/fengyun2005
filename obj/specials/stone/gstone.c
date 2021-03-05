#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"天灵翡翠"NOR, ({"jade", "fei cui", "green stone"}));
    	set_weight(200);
    	if( clonep() )
            set_default_object(__FILE__);
    	else {
        	set("unit", "块");
		set("long", "
这是一块碧绿的翡翠。集山林之灵气，天地之精华而成的翡翠翠绿欲滴，
仿佛充满着生命。\n");
        	set("value", 200);
		set("imbue", 1);
		set("lore", 1);
    }
	::init_item();
}


