// bat_drug.c

inherit COMBINED_ITEM;
int do_cure(string arg);

void create()
{
	set_name("蝙蝠毒解药", ({ "bat drug", "drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
      		set("long",    	"这是一包用来解蝙蝠毒的药,可以用来解蝙蝠毒(cure batpoison)!\n");
		set("unit", "包");
		set("base_unit", "份");
		set("base_weight", 10);
		set("base_value", 1000);
		set("volumn",20);
	}
	set_amount(20);
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
  	
  	if (!arg || arg!="batpoison")
  		return 0;
  	
 	if  (((int) me->query_condition("bat_poison")) <= 0)
  		return notify_fail("你没有中蝙蝠毒。\n");
  	message_vision("$N服下解药，顿时感觉好多了。",me);
        me->change_condition_duration("bat_poison",-5);
  	 	
  	if(me->query_condition("bat_poison")>1)
       	tell_object(me,"但是你中的蝙蝠毒并没有完全清除。\n");
  	else
    {
        tell_object(me,"你终于清除了体内所有的蝙蝠毒！\n");
  		me->change_condition_duration("bat_poison",0);
  	}
  		
  	add_amount(-1);
  	return 1;
}

