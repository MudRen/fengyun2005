// medicine.c

#include <ansi.h>

inherit MEDICINE;


void create()
{
    	set_name(RED"七色雨虹花"NOR,({"qisehua"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long",
"一棵七彩的雨虹花，藏人传说这种花只有在雨果虹现时才能绽放，而那时的雨虹花
才是最具功效的，可以用来治疗1000点精力损伤。\n");
        	set("unit","束");
        	set("base_unit","棵");
        	set("base_value", 6000);
        	set("base_weight",60);
        	set("field","gin");
	    	set("type","cure");
	    	set("effect",1000);
	    	set("heal_type","gin/1000");
	    	set("usage_type","herb");	
	    	set("volumn", 1);
	}
	set_amount(1);
}
