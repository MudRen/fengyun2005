#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

void create()
{
    	set_name("中年伙计",({"huo ji","huoji"}));
	set("title","绸缎庄");
   	set("long","
伙计显得没精打采的样子，只希望天快黑，他们在店里虽然是伙计，
在家里却是老板。\n");
     	
     	set("gender","男性");
    	set("attitude", "friendly");
    	set("group","citizen");
    	
    	set("combat_exp",1000000);  
    	set("age",42);
    	 	
    	set("int",40);
    	set("cor",40);
    	set("cps",40);
    	   	
    	set("inquiry", ([
        	
	   	]));

		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );
        
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		10: name()+"叫道：“来人啊，强盗上门抢劫啦！”\n",

        ]) );    	
        
    	set("chat_chance",1);
    	set("chat_msg",({
			name()+"说：“客官尽管挑，尽管挑。。。”\n",
    	}) );    	    	
    	
		auto_npc_setup("wang",100,100,0,"/obj/weapon/","fighter_w","tianlongwhip",1);
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object("/obj/weapon/whip",([	"name": "皮尺",
    						"long": "一条量衣料的皮尺。\n",
    						"value": 1,
    						 ]))->wield();    
}

