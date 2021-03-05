#include <condition.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("玉真散",({"drug","depoison drug"}));
  	set("long", "行走江湖，难免会中些毒瘴，这是一包用来解普通毒气的药粉（depoison）!\n");
  	set("base_value",5000);
  	set("unit","包");
  	set("base_unit","份");
  	set("base_weight",100);
  	set("volumn",2);
  	set_amount(2);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","depoison");
}

int do_cure()
{
	object me;
	me = this_player();
  	if (!me->query_all_condition())
		return notify_fail("你没有中毒。\n");
	if  (sizeof(me->query_all_condition())<1)
		return notify_fail("你没有中毒。\n");		
  	message_vision("$N服下玉真散。",me);
    me->clear_condition_type(LOW_POISON);
    
    if( sizeof(me->query_all_condition())>=1)
   		tell_object(me,"你身上的病疾似乎还没有完全清除。\n");
	else
        	tell_object(me,"你终于清除了体内所有的病疾，感觉好多了！\n",me);
  	add_amount(-1);
  	return 1;
}

