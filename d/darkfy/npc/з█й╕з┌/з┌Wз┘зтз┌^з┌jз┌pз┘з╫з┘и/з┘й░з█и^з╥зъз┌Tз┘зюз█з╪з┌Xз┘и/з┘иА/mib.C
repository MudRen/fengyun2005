//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("不惊云", ({ "bu jingyun" }) );
        set("gender", "男性");
        set("age", 33);   
      	set("chat_chance", 1);
	      set("chat_msg", ({"123456\n",	}) );
        set("attitude", "friendly");
        set("condition","");
        set("title",HIG""NOR);
        set("nickname", HIG"123456"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","");
        set("death_msg",CYN"\n$N叹道：123。\n"NOR);
        set("combat_exp", 12000000);
    
    set("perform_busy_d", "");
    set("perform_busy_w","");
    set("perform_busy_u","");
    set("perform_unarmed_attack", "");
    set("perform_weapon_attack", "");
    set("perform_buff_1", "");
	
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("perception", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("blade", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        
        
        set_skill("doom-force", 200);
        set_skill("doom-steps", 200);
		    set_skill("doom-sword", 200);
        set_skill("doom-strike", 220);
        set_skill("jin-gang", 150);
        
        map_skill("unarmed","");
        map_skill("force", "");
        map_skill("dodge","");
        map_skill("move","");
        map_skill("parry","");
        map_skill("sword","");
        map_skill("iron-cloth","");
        map_skill("spells","");
        map_skill("magic","");
        setup();


       	carry_object("/obj/armor/cloth",([	
    						"name":  "衣",
    						 ]))->wear();  

}

