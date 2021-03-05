// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
		set_name("陆五川" , ({ "wuchuan", "lu wuchuan", "lu" }) );
		set("long", "他眉头紧锁，似乎有什么解不开的难题。\n");
		set("attitude", "friendly");

		set("age", 48);
        set("gender", "男性" );
        create_family("清平山庄", 1, "庄丁");
		set("combat_exp", 10000);
		set_skill("dodge", 20);
        set_skill("sword", 30);
        set_skill("qingpingsword", 20);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 20);
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");

		setup();
		carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}

void init()
{	
	   object me;
	
	   ::init();
	   if(query("given")<3) {
		   add_action("do_answer","answer");
		   me = this_player();
		   if( interactive(me) && !is_fighting() ) {
		      remove_call_out("greeting");
		      switch (random(2)) {
		         case 0:
		            call_out("greeting", 1, me);
		         break;
		         case 1:
		            call_out("ask_him", 5,me );
		         break;
		      }
		   }
	 	}
}

void greeting(object me)
{
   		if( !me || environment(me) != environment() ) return;
   		message_vision("$N摇头低声吟道：三人同行七十稀，五树梅花廿一枝，七子团
圆正半月，馀百零五便得知。\n",this_object(),me);
   		return;
}

int ask_him(object me)
{
   object obj;

   obj = this_object();
   if (!me)	return 1;
   	
   if(environment(me) == environment())
   tell_object(me,name()+"道：『今有物不知其数，三三数之剩二，五五数之剩三，
七七数之剩二，问物几何？』（answer）\n");
   obj->set_temp("marks/asking",1);
   return 1;
}

int do_answer(string arg)
{
   	object me, obj, kite;
   	obj = this_object();
   	me =this_player();
   	
   	if(!query_temp("marks/asking")) return 0;
   	if(!arg) {
      	message_vision(name()+"道：看来"+me->name()+"也帮不了我！\n", me);
      	obj->set_temp("marks/asking", 0); 
      	return 1;
   	}
   	if( arg == "23" )
   	{
      	message_vision(name()+"道：真是一语道破梦中人！好！\n", me);
      	if (REWARD_D->check_m_success(me,"神水探幽")) {
      		tell_object(me,"陆五川道：好，没想到你竟然这么聪明，我给你个小风筝，以后你也许能用到。\n");
      		tell_object(me,"陆五川在你的如意燧链挂了个小小的风筝。\n");
      		return 1;
      	}
            
      	switch(random(2)) {
         	case 0:
            	tell_object(me, name()+"道：这个风筝将来你也许用的到！\n");
            	message_vision(name()+"递给"+me->name()+"一个风筝。\n", me);
            	kite = new(__DIR__"obj/kite");
            	kite->move(me);
	    		add("given",1);
         		break;
         	case 1:
            	tell_object(me,name()+"道：告诉你个秘密，有人在这清平山庄后花园的树上钓鱼，钓出了个大宝藏！\n");
      	}
		obj->set_temp("marks/asking", 0); 
      	return 1;
   }
   else {
      	tell_object(me, name()+"道：我觉得不大对！\n");
      	obj->set_temp("marks/asking", 0); 
      	return 1;
   }
}



void reset()
{
	delete("given");

}
