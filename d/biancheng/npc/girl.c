#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("大眼睛的小姑娘",({"little girl","girl"}));
   	set("long","@@@@@@@@@@@@@@@@@@@@@\n");
     	set("gender","女性");
    	set("age",16);
    	 	
    	set("int",22);
    	set("cor",30);
    	set("cps",20);
    	
    	set("combat_exp",600000);  
    	set("attitude", "friendly");
    	    	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
			"大眼睛的小姑娘托着头，望着天空发呆。\n"
    	}) );    	    	
    	
    	auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","qingfeng-sword",1);
		setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  HIG"碎花绿缎小褂"NOR,
    						"long": "一件绿缎小褂，上面零零落落地绣着几朵小花。\n",
    						 ]))->wear();    
    
}
