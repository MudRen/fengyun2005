// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
白水宫招待贵宾的所在，由于白水宫向来不许男人进入，而行走江湖的偏又多
是男子，所以这里一般是没有人住的，现在为了你的到来，已经特意打扫了一番，
屋中陈设华美，床上被褥齐全，到此可以卧枕安眠了。
LONG
        );
	set("exits", ([ 
		    "west" : __DIR__"woshi",
	   ]));
	set("item_desc", ([
      		"bed": "一张柔软的大床，睡上去一定很舒服。\n",
      		"床": "一张柔软的大床，睡上去一定很舒服。\n",
   	]) );
   	set("objects", ([
        	__DIR__"npc/needlegirl2" : 1,
        	__DIR__"npc/fightgirl2": 1,
                       ]) );
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
   add_action("do_sleep", "sleep");
}



int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen;

   me = this_player();
   obj = this_object();

   if (me->is_fighting()) return 1;
   if (this_object()->query_temp("marks/taken")) {
      tell_object(me, "床上有人耶。。。。\n");
      return 1;
   }
   if ( !(girl = present("housework girl", obj))) {
      message_vision("$N揉揉眼、打个哈欠，躺到了床上，", me);
      tell_object(me, "很快你就觉得睡意朦胧。\n");
      message("vision", me->name()+"翻了几个身，找到个舒适的姿势，很快就进入了梦乡。\n", environment(me), me);
      obj->set_temp("marks/taken", 1);
      gin = (int) me->query("eff_gin");
      kee = (int) me->query("eff_kee");
      sen = (int) me->query("eff_sen");
      me->set("gin", gin);
      me->set("kee", kee);
      me->set("sen", sen);
      me->set_temp("disable_inputs",1);
      me->add_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<睡梦中>"NOR);
      call_out("wake", 20, me);
   }   
   else {
      	message_vision("$N揉揉眼、打个哈欠，躺到了床上。\n", me);
		message_vision(girl->name()+"喝到：＂这里是给贵宾休息的地方，你算什么人?＂\n", me);
   }
   return 1;
}

void wake(object me)
{
   	object obj;
   	obj = this_object();
   	obj->set_temp("marks/taken", 0); 

   	if (!me)	return;
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
   	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
   	me->delete_temp("is_unconcious");
   
   	if(!me->is_ghost()) {
   		message_vision("$N睁开了眼睛，一个鲤鱼打挺从床上跳了下来。\n", me); 
   		tell_object(me, "你觉得精神好了很多。\n");
   		me->status_msg("all");
   }
}
