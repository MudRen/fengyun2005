inherit __DIR__"tutor";

void create()
{
        set_name("水波的趋势", ({ "sword","波光" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "在水波凝聚的中心，波光似乎汇聚成一柄流光闪闪的宝剑。\n动中寓静，静中寓动，已包含了剑法的真谛。\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "sword");
 		set("teaching_limit", 400);
 	}
 	
 }
