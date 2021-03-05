#include <condition.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("黑玉膏",({"drug","depoison drug"}));
  	set("long", "黑玉膏可外敷亦可内服，是解毒圣药（depoison）!\n");
  	set("base_value",300000);
  	set("unit","包");
  	set("base_unit","份");
  	set("base_weight",100);
  	set("volumn",10);
  	set_amount(1);
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
  	if  (!me->query_all_condition())
		return notify_fail("你没有中毒。\n");
	if  (sizeof(me->query_all_condition())<1)
		return notify_fail("你没有中毒。\n");		
  	message_vision("$N服下黑玉膏。",me);
        me->clear_condition_type(MID_POISON);
        if( sizeof(me->query_all_condition())>=1)
   		tell_object(me,"你身上的病疾似乎还没有完全清除。\n");
	else
        	tell_object(me,"你终于清除了体内所有的病疾，感觉好多了！\n",me);
  	add_amount(-1);
  	return 1;
}

