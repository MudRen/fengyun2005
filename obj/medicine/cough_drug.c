#include <condition.h>
#include <ansi.h>
inherit COMBINED_ITEM;

int do_cure(string arg);
void create()
{
  	set_name("川贝叶",({"drug","depoison drug"}));
  	set("long", "可以用来治疗伤风咳嗽的一种药草（cure cough）!\n");
  	set("base_value",800);
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

int do_cure(string arg)
{
	object me;
	me = this_player();
  	
  	if (!arg || arg != "cough")
  		return 0;
  		
  	if (me->query_condition("cough")<1)
  		return notify_fail("你没有咳嗽。\n");		
  		
  	message_vision("$N服下川贝叶。",me);
    me->change_condition_duration("cough",-2);	
    
    if( me->query_condition("cough") >1)
   		tell_object(me,"你的咳嗽好一些了。\n");
	else
    {
        tell_object(me,"你终于清除了体内所有的病疾，感觉好多了！\n",me);
        me->change_condition_duration("cough",0);	
    }
  	add_amount(-1);
  	return 1;
}

