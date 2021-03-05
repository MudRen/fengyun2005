// medicine.c

inherit MEDICINE;
#include <ansi.h>

void create()
{
    	set_name(WHT"雪芝"NOR,({ "xuezhi"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    	set("long",
                "一朵采自圣母雪峰的雪芝，雪白无暇，芳香扑面，可以用来治疗1000点心神损伤。\n");
	        set("base_unit","朵");
        	set("unit","束");
        	set("base_value", 6000);
        	set("base_weight",60);
        	set("field","sen");
	    	set("type","cure");
	    	set("effect",1000);
	    	set("heal_type","sen/1000");
	    	set("usage_type","herb");	
	    	set("volumn", 1);
	}
	set_amount(1);
}

