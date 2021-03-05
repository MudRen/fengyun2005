inherit __DIR__"tutor";

void create()
{
        set_name("铸铁塑像", ({ "iron statue","塑像", "statue" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "一个怒目圆睁，须发戟张的壮士。他手提大铁椎，形象栩栩如生。\n你细看之下，觉得这个塑像似乎在展示运锤的方法。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "hammer");
 		set("teaching_limit", 400);
 	}
 	
 }
