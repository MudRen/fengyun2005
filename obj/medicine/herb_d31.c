
inherit MEDICINE;
#include <ansi.h>

void create(){
	set_name("五心海棠",({"haitang", "herb"}));
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",(: herb_desc :));
	    set("unit","簇");
	    set("material","herb");
	    set("base_unit","棵");
	    set("base_weight",30);
	    set("base_value",600);
	    set("volumn",10);
	    
	    set("type","poison");	
	    set("field","gin");
	    set("level",180);
	    set("effect",250);	     
	    set("proc", 50);	// Proc rate
	}
	set_amount(10);
}

