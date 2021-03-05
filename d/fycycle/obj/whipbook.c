inherit __DIR__"tutor";

void create()
{
        set_name("清秋快马图", ({ "picture","清秋快马图", "壁画"}));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "大漠沙如雪，燕山月似钩。一个青衣侠士正在马上扬鞭急驶。\n挥出的马鞭勾勒出一道美丽的弧线。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "whip");
 		set("teaching_limit", 400);
 	}
 	
 }
