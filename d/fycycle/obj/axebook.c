inherit __DIR__"tutor";

void create()
{
        set_name("开天斧", ({ "axe","开天斧" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "一柄嵌在正中的墙壁的开天斧。一劈之势并无任何变化，却有分割天地之威。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "axe");
 		set("teaching_limit", 400);
 	}
 	
 }
