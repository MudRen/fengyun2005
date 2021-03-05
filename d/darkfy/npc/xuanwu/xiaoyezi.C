//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("小叶子", ({ "little leaf" }) );
        set("gender", "女性");
        set("age", 27);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("condition","");
        set("title",BLK"危狩"NOR);
        set("nickname", HIY"秋天里的"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","huashan");
        set("combat_exp", 12000000);
    
    set("perform_busy_d", "/huashan/dodge/cloud-dance/yexuechuji");
    set("perform_busy_w","/huashan/throwing/tanzhi-shentong/tanzhijinhun");
    set("perform_unarmed_attack","huashan/dodge/cloud-dance/zhaixin");
    set("perform_weapon_attack1", "huashan/throwing/tanzhi-shentong/mantianhuayu");
    set("perform_weapon_attack2", "huashan/force/hanmei-force/chill");    
    set("perform_buff_1", "/huashan/iron-cloth/spring-water/bingwangtianzhi");
    set("perform_buff_2", "/huashan/iron-cloth/spring-water/yingyueliuhui");
    set("perform_buff_3", "/huashan/force/hanmei-force/remedy");    
    set("perform_buff_4", "/huashan/force/hanmei-force/aoshuang");
		  
		  
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("perception", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("throwing", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("sword", 200);
        
        
        set_skill("qingfeng-sword", 200);
        set_skill("tanzhi-shentong", 240);
		    set_skill("cloud-dance", 200);
        set_skill("anxiang-steps", 200);
        set_skill("spring-water", 150);
        set_skill("hanmei-force", 200);
        set_skill("zhaixin-claw", 200);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("dodge","cloud-dance");
        map_skill("move","anxiang-steps");
        map_skill("parry","tanzhi-shentong");
        map_skill("sword","qingfeng-sword");
        map_skill("iron-cloth","spring-water");
        map_skill("throwing","tanzhi-shentong");

        setup();

       	carry_object("/obj/weapon/sword",([	
    						"name":  BLK"萧瑟"NOR,
    						 ]));  
       	carry_object("/obj/weapon/throwing",([	
    						"name":  "枯叶",
    						 ]))->wear();  
    						 
       	carry_object("/obj/armor/cloth",([	
    						"name":  "危之衣",
    						 ]))->wear();  

}

