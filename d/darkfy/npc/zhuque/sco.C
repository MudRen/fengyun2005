//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("轩辕三", ({ "xuanyuan san" }) );
        set("gender", "男性");
        set("age", 31);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("title",HIR"柳狩"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","legend");
        set("combat_exp", 12000000);        

    set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
    set("perform_busy_u1", "legend/unarmed/meihua-shou/wuzhanmei");
    set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
    set("perform_busy_d1", "legend/dodge/fall-steps/qiufengluoye");
		set("perform_weapon_attack", "legend/blade/shortsong-blade/duangechangmeng");
		set("perform_buff_1", "legend/force/qidaoforce/juli");
		set("perform_buff_2", "legend/force/qidaoforce/jushen");
		set("perform_buff_3", "legend/force/qidaoforce/juqi");
		
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
        
        set_skill("qidaoforce", 180);
        set_skill("fall-steps", 200);
		    set_skill("shortsong-blade", 200);
		    set_skill("six-sense", 300);
        set_skill("dormancy", 300);
        set_skill("meihua-shou", 200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        setup();

       	carry_object("/obj/weapon/blade",([	
    						"name":  HIC"月牙"NOR,
    						 ]))->wield();  

       	carry_object("/obj/armor/cloth",([	
    						"name":  "柳之衣",
    						 ]))->wear();  

}

