#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"凝露黄石"NOR, ({"topaz", "huangshi", "yellow stone" }));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            	set("unit", "块");
		set("long", "
这是五金之英聚成的凝水石。看来柔润晶莹，触手却丝丝寒气刺肤如割。
细细的水珠凝在石面，拂而再聚。\n");
            	set("value", 200);
		set("imbue", 1);
		set("lore", 1);
        }
	::init_item();
}


