#include <ansi.h>
inherit COMBINED_ITEM;

int do_cure(string arg);

void create()
{
	set_name("驱瘴散", ({ "pill" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
      	set("long","这是由红杏花亲手特制的驱瘴散，无论是什么样的毒瘴，
服了它都能安然无恙(cure malaria)。\n");
		set("unit", "包");
		set("base_unit", "丸");
		set("base_weight", 10);
		set("base_value", 2000);
		set("volumn",1);
	}
	set_amount(5);
}


void init()
{
  	if(this_player()==environment())
  		add_action("do_cure","cure");
}


int do_cure(string arg)
{
  	object me = this_player();
	
		
	if (!arg || arg != "malaria")	
		return 0;
		
	message_vision("$N取出一丸驱瘴散服了下去。\n",me);
	tell_object(me,"你觉得满腹清香，神气飞扬。\n");
	me->set_temp("maze/桃花林驱瘴散",1);     
	if (me->query_condition("mag_mushroom")) {
		me->change_condition_duration("mag_mushroom",-5);
		if(me->query_condition("mag_mushroom")>1)
   			tell_object( me, "你中的瘴毒减轻了一些，但并没有完全清除。\n",me);
		else
	    {
	    	tell_object(me, "你体内所有的瘴毒都被清除了！\n",me);
	    	me->change_condition_duration("mag_mushroom",0);
	    }
	}	
  	add_amount(-1);
  	return 1;
}