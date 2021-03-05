#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("乐乐山",({"leleshan"}));
	set("title","三无先生");
   	set("long","
他身上穿着件秀才的青衿，非但洗得很干净，而且连一只补钉都没有。不过，
两只又脏又黑的泥脚，穿着双破破烂烂的草鞋，有只草鞋连底都不见了一半。
好色而无胆，好酒而无量，好赌而无胜，所谓三无，所以他就自称三无先生。\n");
     	set("gender","男性");
    	set("age",42);
    	 	
    	set("combat_exp",7000000);  
    	set("attitude", "friendly");
    	
    	set("reward_npc",1);
    	set("difficulty",5);
	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"乐先生正色道：“洗澡最伤元气，那是万万洗不得的。”\n"
    	}) );    	    	
    	
    	
	auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","taiji",2);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "淡烟秀才装",
    						"long": "一件秀才的青衿，非但洗得很干净，而且连一只补钉都没有。\n",
    						 ]))->wear();        
    
}
