#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("易大经",({"yi dajing","yi","dajing"}));
	set("title","铁手君子");
   	set("long","
一个穿着孝服的男人。他哭得很伤心。他将桌上的纸人纸马纸刀拿下，
点起了火，眼睛里还在流泪。\n");
     	set("gender","男性");
    	set("age",52);
    	 	  	
    	set("combat_exp",7500000);  
    	set("attitude", "friendly");
    	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","alchemy",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword",([	"name": "缅剑",
    						"long": "一把很常见的长剑。\n",
    						 ]))->wield();    
    
}
