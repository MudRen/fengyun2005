// Silencer@fengyun workgroup	June.2005
// hmm, 我故意让ｋｅｙ　transferable here :P


#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("铜钥匙", ({ "key" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "copper");
        	set("long", "一柄铜钥匙，（Use key）。\n");
	}
    ::init_item();
}

void init()
{
        add_action("do_open", "use");
}

int do_open(string arg)
{
	object afei, me, room;
	int i;
	
	me = this_player();
	room = environment(me);
	
	if (arg == "key" || arg == "铜钥匙" || arg = "钥匙") {
		if (environment(this_object())!=me || !arg)
			return 0;
		if (room->query("short")!= "帝释天殿"
			|| !room->query("afei_cage"))
			return notify_fail("在这里你打不开什么门。\n");
		if (me->is_busy())
			return notify_fail("你现在正忙。\n");
				
		if (room->query("door_open"))
			return notify_fail("牢笼已经打开了。\n");
		
		afei = present("afei", room);
		if (!afei)
			return notify_fail("牢笼已经打开了。\n");
		
		if (present("fuhu monk",room))
			return notify_fail("伏虎尊者说：“善哉善哉，施主还是绝了这个念头吧。”\n");
		if (present("xianglong monk",room))
			return notify_fail("降龙尊者说：“善哉善哉，施主还是绝了这个念头吧。”\n");
				
		message_vision(YEL"$N把钥匙插到锁孔中一转，咯吱一声，打开了牢笼。\n"NOR, me);
		room->set("open_door",1);
		afei->delete_temp("condition_type");
		afei->kill_him(me);
		destruct(this_object());
		return 1;
	}
	return 0;
}
