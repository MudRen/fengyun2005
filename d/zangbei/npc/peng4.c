#include <ansi.h>
inherit SMART_NPC;



void create()
{
    	set_name("原冲",({"yuan chong"}));
	set("title",WHT"十二飞鹏帮  怒鹏"NOR);
   	set("long","万鹏王手下十二飞鹏帮的四大帮主之一。\n");
   	
     	set("gender","男性");
     	set("group","khlr");
     	
    	set("age",62); 	 	
    	    	
    	set("combat_exp",10000000);  
    	set("attitude", "friendly");
    	set("NO_KILL","你被锦衣大汉的气势所摄，竟不敢出招。\n");
    	set("resistance/kee",99);
    	set("resistance/gin",99);
    	set("resistance/sen",99);
    	set("boss",1);
    	
    	set("inquiry", ([
 
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,1,"/obj/weapon/","fighter_w","bat-blade",2);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 
}

