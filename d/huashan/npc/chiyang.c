inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("赤阳道长", ({ "chi yang" }) );
        set("gender", "男性");
        set("age", 65);
        set("long","一个面色赤红，身材高大的道人。\n");
        
      	set("chat_chance", 1);
		set("chat_msg", ({
	        "赤阳道长笑道：“那大名鼎鼎的七妙神君，还不是一样栽在我手里。”\n",
		}) );
	  
        set("attitude", "friendly");
        set("title",HIW"武当"NOR);
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","wudang");
        set("combat_exp", 4400000); 
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		     	(: auto_smart_fight(70) :),
     	}) ); 		

		auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","taiji-sword",1);
        setup();
        carry_object("/obj/weapon/sword")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

 
