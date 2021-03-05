//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("红玫瑰", ({ "red rose" }) );
        set("gender", "女性");
        set("age", 33);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("title",HIR"星狩"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","demon");
        set("combat_exp", 12000000);
    
    set("perform_busy_d","/bat/dodge/fengyu-piaoxiang/zonghengsihai");
    set("perform_unarmed_attack", "/demon/unarmed/spicyclaw/extrahit5");
    set("perform_buff_1", "/demon/force/divineforce/baocanshouque");
	
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
        set_skill("perception", 200);
        
        set_skill("fengyu-piaoxiang", 300);
        set_skill("divineforce", 200);
        set_skill("spicyclaw", 220);
        set_skill("xisui", 150);
        
        map_skill("unarmed","spicyclaw");
        map_skill("force", "divineforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","spicyclaw");
        map_skill("iron-cloth","xisui");
        setup();


       	carry_object("/obj/armor/cloth",([	
    						"name":  "星之衣",
    						 ]))->wear();  

}

