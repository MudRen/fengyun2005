//Xxder@fy3
inherit ITEM;
void create()
{
	set_name("风筝", ({ "kite" }) );
	set_weight(150);
        set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("prep", "on");
		set("long", "一个蝴蝶风筝，放风筝的线上邦着一个小小的竹哨。 \n");
		set("desc_ext","play kite");
		set("value", 4);
	}
}

void init()
{
        add_action("do_play", "play");
}


int do_play(string arg)
{
   object me, ob;    
   if (!arg || (arg != "kite" && arg != "风筝")) return 0;
   me = this_player();
   ob = this_object();
   if( me->is_fighting() )
      return notify_fail("在战斗中放风筝，想找死吗！\n");
   if( me->is_busy() )
      return notify_fail("你上一个动作还没有完成，不能放风筝。\n");
   message_vision(me->name()+"掏出一个" + ob->name() + "，但没风放不起来。\n", me);
   environment(me)->kite_notify(ob, 0);
   return 1;
}

