//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("独孤飘", ({ "dugu piao" }) );
        set("gender", "女性");
        set("age", 35);   
      	set("chat_chance", 1);
        set("attitude", "friendly");
        set("condition","");
        set("title",WHT"胃狩"NOR);
        set("nickname", HIC"北飘南漂校飘到处飘"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","bonze");
        set("combat_exp", 12000000);
    
    
    set("perform_busy_u", "/shaolin/unarmed/dabei-strike/qianshouqianbian");
    set("perform_unarmed_attack1", "/bonze/magic/essencemagic/light_sense");
    set("perform_unarmed_attack2", "/bonze/magic/essencemagic/mind_sense");
    set("perform_unarmed_attack3", "/bonze/magic/essencemagic/void_sense");
    set("perform_weapon_attack", "/bonze/staff/cloud-staff/longxianyuye");
    set("perform_buff_1", "/bonze/force/lotusforce/cheal");
    set("perform_buff_2", "/bonze/force/lotusforce/avatar");
	
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("staff", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("essencemagic", 220);
        set_skill("cloudstaff", 200);
		    set_skill("lotusforce", 200);
        set_skill("nodyst-steps", 220);
        set_skill("dabei-strike", 200);
        
        map_skill("unarmed","dabei-strike");
        map_skill("force", "lotusforce");
        map_skill("dodge","nodust-steps");
        map_skill("move","nodust-steps");
        map_skill("parry","cloud-staff");
        map_skill("staff","cloud-staff");
        map_skill("magic","essencemagic");
        setup();

       	carry_object("/obj/weapon/staff",([	
    						"name":  BLK"压碎者"NOR,
    						 ]))->wear();  

       	carry_object("/obj/armor/cloth",([	
    						"name":  "胃之衣",
    						 ]))->wear();  

}

