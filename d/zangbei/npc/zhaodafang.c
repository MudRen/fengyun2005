#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("赵大方",({"zhao dafang","zhao","dafang"}));
   	set("long","
一个穿着孝服的男人。他哭得很伤心。他将桌上的纸人纸马纸刀拿下，
点起了火，眼睛里还在流泪。\n");
     	set("gender","男性");
    	set("age",32);
    	 	
    	set("combat_exp",5100000);  
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
		"赵大方将桌上的纸人纸马纸刀拿下，点起了火，眼睛里还在流泪。\n",
    	}) );    	    	
    	
	  	auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","scratmancy",1);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": WHT"白麻袍"NOR,
    						"long": "一件白麻袍。\n",
    						 ]))->wear();    
    
}
