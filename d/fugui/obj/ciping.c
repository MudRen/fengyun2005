inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青瓷瓶", ({ "ping", "瓶" }) );
	set_weight(70);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个青瓷瓶。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 1);
	}

	set("liquid", ([
		"type": "water",
		"name": "赤炼毒的解药",
		"remaining": 1,
		"drunk_apply": 1,
	]) );
	::init_item();
}

int do_drink(string arg)
{
   
	object me;
	me=this_player();
   	
   	if(arg=="ping" || arg=="青瓷瓶" || arg == "瓶" || arg == "bottle") {
	   if (query("max_liquid"))
	   {
	        message_vision("$N把青瓷瓶里的解药一口吞了下去！\n",me);
			me->change_condition_duration("redsnake",0);
			set("max_liquid",0);
			set("liquid/remaining",0);
			me->unconcious();
	 		set("value",0);
	 		return 1;
	   } else { 
	   		tell_object(me,"瓶里面已经是空空如也了。\n");
	   		return 1;
	   }		
 	}
}

int do_fill(string arg) {
	if(arg=="ping" || arg=="青瓷瓶" || arg == "瓶" || arg == "bottle") {
		tell_object(this_player(),"瓶口太小，什么也灌不进去。\n");
		return 1;
	}
	return 0;
}