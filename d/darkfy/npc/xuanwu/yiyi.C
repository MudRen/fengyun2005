//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("倾盆大雨", ({ "dayu qingpen" }) );
        set("gender", "女性");
        set("age", 23);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("condition","drunk");
        set("title",BLK"室狩"NOR);
        set("nickname", HIC"天上下起"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","shenshui");
        set("combat_exp", 12000000);        
    
    set("perform_busy_d1", "shenshui/dodge/nine-moon-steps/lianhuanbu");
    set("perform_busy_w1", "shenshui/sword/nine-moon-sword/yanduhantan");
    set("perform_weapon_attack1", "shenshui/sword/nine-moon-sword/shuanglengcanxia");
    set("perform_weapon_attack2", "shenshui/sword/nine-moon-sword/yirancangyun");
    set("perform_unarmed_attack", "shenshui/dodge/nine-moon-steps/zhuiming");
		set("perform_buff_1", "shenshui/force/nine-moon-force/mihunshu");
		set("perform_buff_2", "shenshui/force/nine-moon-force/powerup");
		set("perform_buff_3", "shenshui/sword/nine-moon-sword/biyingguanghan");
		set("perform_buff_4", "shenshui/force/nine-moon-force/huaxue");
		set("perform_buff_5", "shenshui/force/nine-moon-force/chill");
	
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("nine-moon-claw", 200);
        set_skill("nine-moon-steps", 200);
        set_skill("nine-moon-sword", 200);
        set_skill("qingpingsword", 200);
        set_skill("qingpingforce", 200);
        set_skill("bai-quan", 200);

        
        map_skill("unarmed","nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("dodge","nine-moon-steps");
        map_skill("move","nine-moon-steps");
        map_skill("parry","nine-moon-claw");
        map_skill("sword","nine-moon-sword");
        setup();


       	carry_object("/obj/weapon/sword",([	
    						"name":  "再常见不过的常见的长剑",
    						 ]))->wear();  
    						 
       	carry_object("/obj/armor/cloth",([	
    						"name":  "室衣",
    						 ]))->wear();  

}

