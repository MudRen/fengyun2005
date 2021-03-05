#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("马十二",({"ma shier","ma","shier"}));
	set("title","万马堂 侍卫");
   	set("long","马空群的侍卫，他们没有名字，只有代号。\n");
     	set("gender","男性");
    	set("age",42);

    	set("group","wanma");
    	set("combat_exp",6500000);  
    	set("attitude", "friendly");

    	set("reward_npc",1);
    	set("difficulty",3);
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: name()+"叫道：“来人啊，抓刺客啦！”\n",	
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        	
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","smallguy",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": "蓝马褂",
    						"long": "一件蓝马褂。\n",
    						 ]))->wear();    
    
}
