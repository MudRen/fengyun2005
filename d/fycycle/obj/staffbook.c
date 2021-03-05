inherit __DIR__"tutor";

void create()
{
        set_name("草人", ({ "caoren","草人" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "一个芒鞋竹杖的草人。手里的竹杖似乎是支撑着身体，又似乎是不经意地轻点地面。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "staff");
 		set("teaching_limit", 400);
 	}
 	
 }
