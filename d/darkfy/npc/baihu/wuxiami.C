//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
//你负责给他弄几个护卫
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("无虾米", ({ "wu xiami" }) );
        set("gender", "男性");
        set("age", 22);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"无虾米低头呆呆的数着面前的虾米，根本没有注意到你的到来。\n",
	}) );
        set("family/master_id","master yue");
        set("attitude", "friendly");
        set("title",WHT"婁狩"NOR);
        set("nickname", HIG"诛恶犬杀喇嘛"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","official");
        set("death_msg",CYN"\n$N叹道：人若是能死两次，也不失为一件新鲜的事。\n"NOR);
        set("combat_exp", 12000000);        
    set("perform_busy_d", "shaolin/dodge/puti-steps/si");
    set("perform_busy_d", "shaolin/dodge/puti-steps/wu");
    set("perform_busy_d", "shaolin/dodge/puti-steps/liu");
    set("perform_busy_d", "shaolin/dodge/puti-steps/qi");
    set("perform_busy_d", "shaolin/dodge/puti-steps/jiu");            
		set("perform_weapon_attack", "official/spear/yue-spear/zonghengtianxia");

		
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("spear", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("perception", 200);
        
        set_skill("manjianghong", 180);
        set_skill("puti-steps", 200);
		    set_skill("yue-spear", 200);
		    set_skill("leadership", 250);
        set_skill("strategy", 250);
        set_skill("changquan", 220);
        
        map_skill("unarmed","changquan");
        map_skill("force", "manjianghong");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
        map_skill("parry","yue-spear");
        map_skill("spear","yue-spear");
        setup();

       	carry_object("/obj/weapon/spear",([	
    						"name":  HIY"麟角"NOR,
    						"long": "恩，没想好写什么。\n",
    						 ]))->wield();  

       	carry_object("/obj/armor/cloth",([	
    						"name":  "婁之衣",
    						 ]))->wear();  

}

