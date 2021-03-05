// medicine.c

inherit MEDICINE;

void create()
{
	set_name("回天散",({"huitiansan"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一丸被视为少林之宝的回天散。可以用来治疗1000点外伤 。\n");
	    	set("base_unit","丸");
        	set("unit","包");
        	set("base_value", 0);
        	set("base_weight",60);
	    	set("type","cure");
	    	set("heal_type","kee/1000");
	    	set("usage_type","herb");	
	}
	set_amount(1);
}
