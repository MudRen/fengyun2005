inherit COMBINED_ITEM;

void create()
{
  	set_name("蛇药",({"drug","snake drug"}));
  	set("long", "这是一包用来解蛇毒的药,可以用(cure)来解蛇毒!\n");
  	set("base_value",500);
  	set("unit","包");
  	set("base_unit","份");
  	set("base_weight",100);
  	set("volumn",10);
  	set_amount(10);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","cure");
}

int do_cure()
{
	object me;
	me = this_player();
  	if  (((int) me->query_condition("snake_poison")) <= 0)
		return notify_fail("你没有中蛇毒。\n");
  	
  	message_vision("$N服下蛇药，顿时感觉好多了。",me);
        me->change_condition_duration("snake_poison",-2);
  	 	 	
  	if(me->query_condition("snake_poison")>1)
   		message_vision("但是$N中的蛇毒并没有完全清除。\n",me);
	else
    {
    	message_vision("$N终于清除了体内所有的蛇毒！\n",me);
    	me->change_condition_duration("snake_poison",0);
    }
    	
  	add_amount(-1);
  	return 1;
}

