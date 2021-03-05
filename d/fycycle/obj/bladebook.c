inherit __DIR__"tutor";

void create()
{
        set_name("白玉石刀", ({ "jade blade","白玉石刀", "blade" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "一柄弯弯的白玉石刀。弯弯的弧线，给人一种天成的启迪和无懈的气势。\n");
 		set("no_shown", 1);
		set("no_get",1);
 		set("teaching", "blade");
 		set("teaching_limit", 400);
 	}
 	
 }
