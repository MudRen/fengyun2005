// medicine.c

inherit MEDICINE;

void create()
{
	set_name("野人参",({"renshen"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一株野人参，可以用来治疗200点精力损伤。\n");
	    	set("unit","把");
        	set("base_unit","株");
        	set("base_value", 1000);
        	set("base_weight",60);
	    	set("type","cure");
	    	set("field","gin");
	    	set("effect",200);
	    	set("heal_type","gin/200");
	    	set("usage_type","herb");	
	    	set("volumn", 2);
	}
	set_amount(2);
}
