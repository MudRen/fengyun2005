// medicine.c
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIC"天山雪莲"NOR,({"snow lotus"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long", "一株奇寒无比的，百年一现的天山雪莲！\n");
	    set("unit","株");
	    set("value", 5000000);
	}
	::init_item();
}

void init()
{
  	if(this_player()==environment())
		add_action("apply_medicine","yong");
}

int apply_medicine()
{
	message_vision("$N一张口，将一株奇寒无比的天山雪莲服入体内！\n",this_player());	
	this_player()->apply_condition("cold_energy",10+random(10));
	destruct(this_object());
	return 1;
}




