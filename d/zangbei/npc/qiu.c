#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("邱凤城",({"qiu fengcheng","qiu"}));
	set("title",HIW"银枪公子"NOR);
   	set("long","
他年轻、健康、高大、英俊，而且有一种教养良好的气质。他身上穿的是
一袭价值千金的貂裘，手里拿著对光华夺目的银枪。他仰面看著蓝天，痴
痴的出神，眼睛里带著种说不出的悲痛和忧虑。
\n");
     	
     	set("gender","男性");
     	
    	set("age",32); 	 	
    	set("per",40);
	
		set("reward_npc",10);
    	
    	set("combat_exp",7500000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		name()+"坐在那里，痴痴的出神，好像根本没看见你的来到。\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",300,250,0,"/obj/weapon/","fighter_w","xuezhan-spear2",2);
	
		setup();
    	carry_object(__DIR__"obj/qiucloth")->wear();
    	carry_object(__DIR__"obj/qiuspear")->wield();    
    
}

