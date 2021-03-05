#include <ansi.h>
#include <command.h>
inherit INQUIRY_MSG;
inherit SMART_NPC;

void create()
{

	set_name("张铁",({"zhang tie","zhang"}));
    	set("title",RED"戴红缨帽的官差"NOR);
    	set("long", "
张铁的名字虽有一个铁字，在他的身上，却只有一样东西是铁打的。
他的刀。刀锋虽未出鞘，刀柄已在他的手中。在这个地方，无论在做
着什么，他都绝不会让那把刀离开他的手。\n");
	set("age",37);
	set("combat_exp", 6500000);
        set("attitude", "friendly");	

	set("reward_npc",5);

	set("inquiry", ([
          	 "铁恨": "铁捕头和常老爷齐名，是天下四大名捕之一。",
          	 "tie hen": "铁捕头和常老爷齐名，是天下四大名捕之一。",
          	 "tiehen": "铁捕头和常老爷齐名，是天下四大名捕之一。",
   	]));
	
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	
        ]) );    	
        
        set("smartnpc_busy",1);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) ); 		

	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","wind-blade",1);
	
	set_skill("iron-cloth",150);
	set_skill("xisui",100);
	map_skill("iron-cloth","xisui");
		
	setup();
	carry_object(__DIR__"obj/o_cloth3")->wear();
	carry_object(__DIR__"obj/redhat")->wear();
}


void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	return;
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	message_vision(CYN"张铁打了个谒说：“常大人正在楼上歇息，若有事可去后院找唐大林二。”\n"NOR,ob);
	return;
}
