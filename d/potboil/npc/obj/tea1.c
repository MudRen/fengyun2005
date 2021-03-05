//
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;
void init()
{
        if(environment()==this_player())
	        add_action("do_drink", "drink");
        if(environment()==this_player())
	        add_action("do_fill", "fill");

}

void create()
{
	set_name(HIR"波斯红葡萄酒"NOR, ({ "wine" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "水晶杯里清冽透明的液体中无数细小的气泡极度美丽。\n");
		set("unit", "盏");
		set("value", 1500);
        set("liquid", ([
        "type": "wine",
        "name": "波斯红葡萄酒",
        "remaining": 1,
        "drunk_apply": 1,
        ]) );	
	}
	 ::init_item();
}

int do_fill()
{
	write("这个水晶杯太小了，什么也装不下诶。\n");
	return 1;
}
