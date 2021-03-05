inherit __DIR__"tutor";

void create()
{
        set_name("十万甲兵", ({ "wall","四壁"}));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "你细看之下,眼前竟然出现幻觉。只见无数战马，横卷一切，破冰而来。\n战马上武士的长枪森然相向，红缨熠熠，枪芒闪闪。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "spear");
 		set("teaching_limit", 400);
 	}
 	
 }
