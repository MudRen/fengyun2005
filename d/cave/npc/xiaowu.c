#include <ansi.h>
inherit SMART_NPC;
int gao();

void create()
{
    	set_name("小武", ({"xiao wu","wu"}) );
    	set("gender", "男性" );
    	set("nickname", HIC"随手剑"NOR);
    	set("title", "青龙会 刺客");
    	set("long", "
小武看来仿佛是个很随便、很懒散的人，很喜欢笑，很喜欢酒。没有人能想象
到他杀人时的动作是多么迅速，多么准确。他若要刺瞎你的左眼，他的剑就绝
不会刺在你别的地方。\n");
 	set("attitude", "friendly");
    	set("age", 25);
		set("per", 25);
        set("combat_exp", 3000000);
    	set("class","assassin");
    	
    	set("reward_npc", 1);
        set("difficulty", 3);
            	
    	set("chat_chance", 1);
    	set("chat_msg", ({
 	   "小武皱了皱眉，喃喃道：该怎生救出高立那鲁莽家伙呢？\n",
    	}) );
		set("inquiry", ([
		"gaoli" : (: gao :),
		"gao" : (: gao :),
		"高立" : (: gao :),
		"gao li" : (: gao :),
		]));
		set("jadebox", 1);
	
	       	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(60) :),
        }) );	  
    		
		auto_npc_setup("wang",180,180,0,"/obj/weapon/","fighter_w","sharen-sword",1);
    	setup();
    	carry_object("/d/fugui/npc/obj/m_cloth3")->wear();
    	carry_object(__DIR__"obj/windsword")->wield();
       	if (!random(5)) carry_object(__DIR__"obj/stone_2");

}

int gao(){
	object me;
	me = this_player();
	if(query("answering")){
		return notify_fail("小武似乎正在忙。\n");
	}
	if(me->query("combat_exp") < 1000000) {
		message_vision("$N打量了$n一番，皱了皱眉道：唉，没等你见到高立，早就一命呜呼了。。\n", 
				this_object(), me);
	} else if (me->query_temp("marks/underground_gao")) {
		message_vision("$N咦了一声对$n道：我刚刚不是给了你雀翎玉盒吗？难道那个法子不管用？\n",
				this_object(), me);
	} else {
		message_vision("$N撇了$n一眼，沉思了半晌，双眸突然放出光来：对了，就这样，这样
一定可以救高立和双双，一定可以。\n", this_object(), me);
		set("answering", 1);
		call_out("give_jadebox", 2, me);
	}
	return 1;
}

void give_jadebox(object me){
	object box;
	if(!interactive(me) || environment(me) != environment(this_object())){
		return;
	}  
	message_vision("$N愉快地笑了笑：好，你就把这个雀翎玉盒交给高立。。嗯，告诉他孔雀翎 
。。就在里面，但孔雀翎存在的真正目的，不是杀人，而是救命，所以。。。 
不到万不得已时，绝不要用它。\n", this_object(), me); 	
	me->set_temp("marks/underground_gao", 1);
	box = new(__DIR__"obj/jadebox");
	if(objectp(box)){
		box->move(me);
	}
	delete("answering");
	return;
}
