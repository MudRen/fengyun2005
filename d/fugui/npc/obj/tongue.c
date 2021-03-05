#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(RED"卤猪舌"NOR, ({ "pigtongue" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
        set("long", "一根卤得香气扑鼻的猪舌头。\n");
        set("unit", "根");
        set("value", 5000);
	set("food_remaining", 3);
	set("food_supply", 60);
	}
	::init_item();
}
