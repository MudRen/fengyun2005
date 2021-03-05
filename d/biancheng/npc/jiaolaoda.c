#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("焦老大",({"jiao laoda","jiao","laoda"}));
	set("title","马师");
   	set("long","
焦老大是马师中年纪最长的一个。他这一生，几乎全都是在万马堂度过
的，他已将这一生最宝贵的岁月，全都消磨在万马堂中的马背上。现在
他双腿已弯曲，背也已有些弯了，一双本来很锐利的眼睛已被劣酒泡得
发红。每当他睡在又冷又硬的木床上抚摸到自己大腿上的老茧时，他也
会想到别处去闯一闯。可是他已没有别的地方可去，因为他的根也生在
万马堂。\n");
     	set("gender","男性");
    	set("age",52);
    	 	
    	set("combat_exp",5000000);  
    	set("attitude", "friendly");
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(80) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	    	
    	
    	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","thunderwhip2",1);
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/weapon/whip",([	"name": "长马鞭",
    						"long": "一条长长的马鞭。\n",
    						"value": 0,
    						 ]))->wield();    
}
