// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "沉香海");
    set("long", "或许是因为处在难得的谷地，身边有星花盛放，四面是凉风习习，琴松风
而拂竹翠，藤萝冥冥而草木和鸣。离开了枯燥单调的黄树林步入这里，眼前青
碧的花木、淡淡的松香令你骤觉得仿然仙境，直想躺平在茸茸花草之间，享受
片刻的宁静。
"        );
	set("objects", ([
		__DIR__"obj/pine":1,
		__DIR__"obj/hole":1,
		__DIR__"npc/you":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : __DIR__"path7",
  		"eastup" : __DIR__"path8",
  		"southup" : __DIR__"forest5",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-40);
	set("coor/y",50);
	set("coor/z",70);
	setup();
}


void init()
{
 	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
   	object me, obj, girl;
   	int gin, kee, sen, duration;

   	me = this_player();
   	obj = this_object();

   	if (me->is_fighting()) return 1;
   	
   	if (me->is_busy()) {
   		tell_object(me,"你现在正忙。\n");
   		return 1;
   	}
   
   	if (this_object()->query_temp("marks/taken"))
   	{
      		tell_object(me, "草地上有人耶。。。。\n");
      		return 1;
   	}
    
    if (F_LEVEL->get_level(me->query("combat_exp"))<20){
    	tell_object(me,"你功夫这么差，还不赶着去练功？（至少需等级20）\n");
    	return 1;
    }
    
    duration = me->query("timer/cyan_dreamland") + 1200 - time();
    if (duration>0){
    	tell_object(me,"你最近刚来过，再等" + (duration/60) + "分钟吧。\n");
    	return 1;
    }
    
    me->set_leader(0);
    
	message_vision("$N揉揉眼、打个哈欠，躺到了草地上，", me);
	tell_object(me, "很快你就觉得睡意朦胧。\n");
	message("vision", me->name()+"翻了几个身，找到个舒适的姿势，很快就进入了梦乡。\n", environment(me), me);
	obj->set_temp("marks/taken", 1);

	switch (random(3))
	  {
	  case 0:
		  gin = (int) me->query("eff_gin");
		  me->set("gin", gin);
		  break;
	  case 1:
		  kee = (int) me->query("eff_kee");
		  me->set("kee", kee);
		  break;
	  case 2:
		  sen = (int) me->query("eff_sen");
		  me->set("sen", sen);
	  }
      	me->set("timer/cyan_dreamland", time());
      	me->set_temp("disable_inputs",1);
      	me->add_temp("block_msg/all",1);
      	me->set_temp("is_unconcious",1);
      	me->set("disable_type",HIG "<睡梦中>"NOR);


		if (!REWARD_D->riddle_check(me,"红尘劫") 
			&& !REWARD_D->check_m_success(me,"红尘劫") 
			&& me->query("score") > 4)
		{
			obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan/peak5");
			if (!obj)
				obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan/peak5");

			call_out("wake", 10, me,obj);
			return 1;
		}

		if (REWARD_D->riddle_check(me,"红尘劫") == 1 && me->query("score") > 4)
		{
			obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan3/forest4");
			if (!obj)
				obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan3/forest4");

			call_out("waked2", 10, me,obj);
			return 1;
		}

		call_out("wakexx", 10, me,obj);

      	return 1;
}

void wakexx(object me,object obj)
{
   		object oe,oc;

		if (!me || me->is_ghost()){
			obj->set_temp("marks/taken", 0); 
			return;
		}
			
		message_vision("$N在草地上翻了个身子，揉了揉眼睛，继续沉沉睡去。\n", me); 
		if (random(4))
			call_out("wakexx", 10, me);
		else
		{
			message_vision("一只小松鼠在树上探头探脑，似乎在偷偷窥视着$N。\n", me); 
			call_out("wake2", 10, me);
		}
		return;		
	
	return;
}

void wake(object me,object obj)
{
   	object oe,oc;
   	
   	set_temp("marks/taken", 0); 

	if (!me)	return;
	
	me->set("NO_KILL","你现在不能攻击此人。\n");
		
	oe=new("/d/phoenix/npc/cyan_player");
	oe->move(obj);
		
	oe->set_temp("block_msg/all",1);
	LOGIN_D->enter_world(me, oe, 1);

	if (present("cloth",oe))
		destruct(present("cloth",oe));

	
	"/feature/nada.c"->reset_player_status(oe);
	oe->full_me();
//	"/cmds/imm/full"->main(oe);

	oe->set_temp("block_msg/all",0);
	oe->set_temp("no_disconnect_during_idle",1);
	me->set_temp("no_disconnect_during_idle",1);

   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
   	me->delete_temp("is_unconcious");
	me->move(this_object());
   	tell_object(oe, CYN"迷迷糊糊间你似觉得正有人在颈边吹气，勉力睁开眼睛．．．\n"NOR);
	oc=new("/d/phoenix/cyan/npc/ruo");
	oc->move(obj);

	oe->move(obj);

	obj->trigger(oe);
	
//	me->move(obj);



	return;
}



void waked2(object me,object obj)
{
   	object oe,oc;

	set_temp("marks/taken", 0); 

	oe=new("/d/phoenix/npc/cyan3_player");
	oe->move(obj);
		
	oe->set_temp("block_msg/all",1);
	LOGIN_D->enter_world(me, oe, 1);

	if (present("cloth",oe))
		destruct(present("cloth",oe));

	
	"/feature/nada.c"->reset_player_status(oe);
//	"/cmds/imm/full"->main(oe);
	oe->full_me();
	
	oe->set_temp("block_msg/all",0);
	oe->set_temp("no_disconnect_during_idle",1);
	me->set_temp("no_disconnect_during_idle",1);


   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
   	me->delete_temp("is_unconcious");
	me->move(this_object());

	oc=new("/d/phoenix/cyan3/npc/feng");
	oc->move(obj);

	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","华山门下的尸体");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","华山门下的尸体");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","丐帮弟子的尸体");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","大旗门人的尸体");
	oc->move(obj);
	oc=new("/d/phoenix/cyan3/obj/corpse");
	oc->set("name","心霭的尸体");
	oc->set("long","心霭师拜古严大师门下，精修莲心影现刀法，与师弟心烛并称佛门双秀。
曾有无聊人事断言，心霭的刀法修为已近化境，当可列入世上七大名家之席。
然而，他已经死了，只剩下一具尸体静静地躺在这里。
他的相貌吗... 都已经死了，还有什么好看的！\n\n");
	oc->move(obj);

	oe->move(obj);

	oe->get_riddle_stat(me,oe);


	obj->trigger(oe);
	
//	me->move(obj);



	return;
}
void wake2(object me)
{
   	object obj;
   	obj = this_object();
   	
   	obj->set_temp("marks/taken", 0);
   	
   	if (!me || me->is_ghost()) {
   		return;
   	}
   		
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
	if (me->query_temp("block_msg/all")>=1)
	    me->add_temp("block_msg/all", -1);
   	me->delete_temp("is_unconcious");
	
	message_vision("一枚松果从树上飞砸而下，准准的砸中了$N的脑门，惊得$N跳了起来。\n", me); 
   	tell_object(me, "你觉得头上似乎被什么敲了一下，伸手揉揉隐隐作痛的头，睁开眼睛，\n");
   	tell_object(me, "只来得及见到一条大尾巴在松树上一转，消失无迹。\n");
   	if (me->query("kee") > 77)
		me->receive_damage("kee",77);
   	else
		me->receive_damage("kee", me->query("kee")-1);
   	me->set_temp("annie/cyan_lucky",1);
	return;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


