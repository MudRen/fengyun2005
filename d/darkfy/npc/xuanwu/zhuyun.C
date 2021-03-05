//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("朱云", ({ "zhu yun" }) );
        set("gender", "男性");
        set("age", 28);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("title",BLK"斗狩"NOR);
        set("nickname", HIG"123456"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","wolfmount");
        set("combat_exp", 12000000);        
    
    set("perform_unarmed_attack1", "wolfmount/unarmed/wolf-strike/canzhi");    
    set("perform_unarmed_attack2", "wolfmount/unarmed/wolf-strike/duanhou");    
    set("perform_unarmed_attack3", "wolfmount/unarmed/wolf-strike/ningxie");    		
    set("perform_unarmed_attack4", "wolfmount/unarmed/wolf-strike/shigu");    		
		set("perform_buff_1", "wolfmount/dodge/xueyeqianzong/feline");
		set("perform_buff_2", "wolfmount/dodge/xueyeqianzong/wolverine");
		set("perform_buff_3", "wolfmount/force/wolf-force/assassinate");
		set("perform_buff_4", "wolfmount/force/wolf-force/bloodthirsty");
		set("perform_buff_5", "wolfmount/force/wolf-force/paragon");
	
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("blade", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("wolf-force", 180);
        set_skill("xueyeqianzong", 200);
		    set_skill("wolf-strike", 200);
        
        map_skill("unarmed","wolf-strike");
        map_skill("force", "wolf-force");
        map_skill("dodge","xueyeqianzong");
        map_skill("move","xueyeqianzong");
        map_skill("parry","wolf-strike");
        map_skill("unarmed","wolf-strike");

       	carry_object("/obj/armor/cloth",([	
    						"name":  "斗之衣",
    						 ]))->wear();  

}

