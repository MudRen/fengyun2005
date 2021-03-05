//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("赤无极", ({ "chi wuji" }) );
        set("gender", "男性");
        set("age", 35);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"赤无极笑道：无极无极，果然是无聊至极，那CKG，当真是脑子进了大粪了。\n",
	}) );

        set("attitude", "friendly");
        set("title",HIG"氐狩"NOR);
        set("nickname", HIG"斧头帮帮主"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","shaolin");
        set("death_msg",CYN"\n$N叹道：人若是能死两次，也不失为一件新鲜的事。\n"NOR);
        set("combat_exp", 12000000);        
        
    set("perform_busy_u", "shaolin/unarmed/dabei-strike/qianshouqianbian");
    set("perform_busy_w", "shaolin/staff/fumostaff/hequhecong");
		set("perform_weapon_attack", "shaolin/axe/wuche-axe/sanbanfu");
		set("perform_weapon_attack1", "shaolin/axe/wuche-axe/xuanfengzhan");
		set("perform_buff_1", "shaolin/force/yijinjing/foguang");
		
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("axe", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("iron-cloth", 150);
        set_skill("staff", 200);
        set_skill("perception", 200);
        
        set_skill("xiaochengforce", 180);
        set_skill("yijinjing", 200);
		    set_skill("puti-steps", 200);
		    set_skill("wuche-axe", 200);
        set_skill("zen", 200);
        set_skill("fumostaff", 200);
        set_skill("dabei-strike", 180);
        
        map_skill("unarmed","dabei-strike");
        map_skill("force", "yijinjing");
        map_skill("dodge","puti-steps");
        map_skill("move","puti-steps");
        map_skill("parry","wuche-axe");
        map_skill("axe","wuche-axe");
        map_skill("iron-cloth","yijinjing");
        map_skill("staff","fumostaff");
        setup();
       	carry_object("/obj/weapon/axe",([	
    						"name":  HIY"泼风"NOR,
    						"long": "恩，没想好写什么。\n",
    						 ]))->wield();  
       	carry_object("/obj/weapon/staff",([	
    						 ]));
       	carry_object("/obj/armor/cloth",([	
    						"name":  "氐之衣",
    						 ]))->wear();  

}

