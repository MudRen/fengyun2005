inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("一串小葡萄", ({ "grape", "pu tao" }) );
        set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "小小的葡萄色泽晶莹，就象用碧玉雕成。\n");
        set("unit", "串"); 
        set("value", 1);
        set("grape_remaining", 4);
    }
    ::init_item();
}

void init () {
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
    object grape, me;
    
    me = this_player();
    grape = present("grape", this_player());
    
    if (!arg || arg != "grape" && arg != "一串小葡萄" && arg != "pu tao") return 0; 	
	if ((int)query("grape_remaining") >= 0) {
	   	message_vision("$N潇洒地丢了一颗葡萄到嘴里。\n", me);
    	write("哇。。。。。。。你被酸得说不出话来。\n");
 		me->add("food", -3);
 		me -> set_temp("marks/桃源_酸葡萄", 1);
 		if ((string)me->query("gender") == "男性" ) {
	 		message("vision",me->name() + "被酸得紧紧皱起眉头。鼻子，眼睛，嘴巴，都聚到了一起，象极了一个包子。\n", environment(me), me);
    	} else {
    		message("vision",me->name() + "紧紧闭住嘴巴，眉头皱了起来。\n", environment(me), me);
    	}
		if ((int)query("grape_remaining") == 1) {
			destruct (grape);
		} else {
			add ("grape_remaining", -1);
		}
	}
    return 1;
}