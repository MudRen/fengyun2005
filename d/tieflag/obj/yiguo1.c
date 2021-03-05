
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("异果", ({ "yiguo"}) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
        set("unit", "个");
        set("long", "一种你从未见过的奇异果子。\n");
        set("value", 1);
    set("food_remaining", 1);
    set("food_supply", 16);
    }
    ::init_item();
}  
void init()
{
   add_action("do_eat","eat");
}
int do_eat(string arg)
{       
	object me;
	int gin,kee,sen,foods,drink;
	me=this_player();
	if(arg=="yiguo"||arg=="异果") {
        foods=(int)me->max_food_capacity();
        drink=(int)me->max_water_capacity();
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen"); 
	message_vision("$N感到快美异常，仿佛吃了什么灵丹妙药！！\n", me);
        me->set("food",foods);
        me->set("water",drink);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen); 
	destruct(this_object());  
	return 1; 
	}        
	return 0;
}
        

	



