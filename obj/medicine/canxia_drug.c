#include <condition.h>
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name(HIG"月明风露"NOR,({"yueming"}));
  	set("long", "有着一个美丽名字的药膏，可以用来解烟锁残霞(cure canxia)。\n");
  	set("base_value",80000);
  	set("unit","包");
  	set("base_unit","份");
  	set("base_weight",100);
  	set("volumn",10);
  	set_amount(1);
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
  	if (!arg || arg!="canxia")	return 0;
  	  	
  	if (me->query_condition("canxia")<1)
  		return notify_fail("你没有中烟锁残霞。\n");
  			
  	message_vision("$N服下月明风露。",me);
  	me->change_condition_duration("canxia",0);
    tell_object(me,"你中的烟锁残霞被解去了。\n");
    add_amount(-1);
  	return 1;
}

