#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("冯浩",({"feng hao","feng"}));
	set("title","忠厚老实");
   	set("long","
冯浩是菊花园里的马夫，一张平凡朴实的脸，说起话来低声低气，不过只要
老伯一声令下，他总是能以最快的速度从马房里牵出一匹整装待发的骏马。\n");
     	
     	set("gender","男性");
     	set("group","juhua");
     	
    	set("age",42); 	 	
    	
    	set("combat_exp",3500000);  
    	set("attitude", "friendly");
    	
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
    	
	auto_npc_setup("wang",180,200,0,"/obj/weapon/","fighter_u","thunderwhip2",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
 	carry_object("/obj/weapon/whip",([	"name": "竹筋马鞭",
    						"long": "一条竹筋马鞭。\n",
    						"value": 0,
    						 ]))->wield();    
}

