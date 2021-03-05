//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("顽石", ({ "wan shi" }) );
        set("gender", "男性");
        set("age", 35);   
      	set("chat_chance", 1);
	      set("chat_msg", ({"\n顽石就那样站在那儿一动也不动，宛如一块石头。",	}) );
        set("attitude", "friendly");
        set("title",HIG""NOR);
        set("nickname", WHT"奎狩"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","fighter");
        set("combat_exp", 12000000);
    
    
    set("perform_weapon_attack", "/fighter/dodge/doom-steps/feitiantui");
    set("perform_weapon_attack", "/fighter/dodge/doom-steps/hantian");
    set("perform_weapon_attack", "/fighter/sword/doom-sword/hunranyijian");
    set("perform_buff_1", "/fighter/force/doom-force/powerup");
	
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
        
        map_skill("unarmed","doom-strike");
        map_skill("force", "doom-force");
        map_skill("dodge","doon-steps");
        map_skill("move","doom-steps");
        map_skill("parry","doom-sword");
        map_skill("sword","doom-sword");
        map_skill("iron-cloth","jin-gang");
        setup();

       	carry_object("/obj/weapon/sword",([	
    						"name":  HIR"血光"NOR,
    						 ]))->wear();  

       	carry_object("/obj/armor/cloth",([	
    						"name":  "奎之衣",
    						 ]))->wear();  

}

