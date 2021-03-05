//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("天意", ({ "tian yi" }) );
        set("gender", "男性");
        set("age", 36);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"天意痴痴的望着天然，口中流下了一丝。。。:O~~~~~~~~~~~~~~~~~~~~\n",
	}) );

        set("attitude", "friendly");
        set("title",HIG"心狩"NOR);
        set("nickname", HIC"看庭前花开花落"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","shaolin");
        set("death_msg",CYN"\n$N叹道：人若是能死两次，也不失为一件新鲜的事。\n"NOR);
        set("combat_exp", 12000000);        
        set("group", "couple");        
    set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
    set("perform_busy_w", "shaolin/staff/fumostaff/hequhecong");
		set("perform_weapon_attack", "shaolin/spear/duanhun-spear/qixingduopo");
		set("perform_weapon_attack1", "shaolin/spear/duanhun-spear/suomengchanhun");
		set("perform_buff_1", "shaolin/force/yijinjing/foguang");
		
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
        set_skill("iron-cloth", 150);
        set_skill("staff", 200);
        set_skill("perception", 200);
        
        set_skill("xiaochengforce", 180);
        set_skill("yijinjing", 200);
		    set_skill("puti-steps", 200);
		    set_skill("duanhun-spear", 200);
        set_skill("zen", 200);
        set_skill("fumostaff", 200);
        set_skill("dabei-strike", 180);
        
        map_skill("unarmed","dabei-strike");
        map_skill("force", "yijinjing");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
        map_skill("parry","duanhun-spear");
        map_skill("spear","duanhun-spear");
        map_skill("iron-cloth","yijinjing");
        map_skill("staff","fumostaff");
        setup();

    	carry_object("/obj/weapon/spear",([	
    						"name":  HIY"豹牙"NOR,
    						 ]))->wield();  
    	carry_object("/obj/armor/cloth",([	
    						"name":  "心之衣",
    						 ]))->wear();  


}

