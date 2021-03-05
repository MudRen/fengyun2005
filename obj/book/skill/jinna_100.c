inherit "/d/fycycle/obj/tutor";

void create()
{
        set_name("紧那罗", ({"紧那罗","jinnaluo","jinna"}));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long","手持铁棍的紧那罗。\n");
 			set("no_shown", 1);
 			set("no_get",1);
 			set("teaching", "stuff");
 			set("teaching_limit", 50);
 		}	
 }
 
 