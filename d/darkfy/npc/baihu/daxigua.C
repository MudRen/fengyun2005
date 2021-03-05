//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("打西瓜", ({ "hit watermelon,watermelon" }) );
        set("gender", "女性");
        set("age", 28);   
      	set("chat_chance", 1);
	      set("chat_msg", ({"打西瓜大喝一声，把面前的西瓜劈成了两半。\n",	}) );
        set("attitude", "friendly");
        set("condition","");
        set("title",HIG""NOR);
        set("nickname", WHT"昴狩"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","knight");
        set("combat_exp", 12000000);
    
    
    set("perform_busy_u", "/knight/herb/dream-herb/kaixiehua");
    set("perform_unarmed_attack", "/knight/unarmed/hanshan-strike/zhangjian");
    set("perform_unarmed_attack", "/knight/herb/dream-herb/canyunbi");
    set("perform_unarmed_attack", "/knight/herb/dream-herb/buzichi");
    set("perform_unarmed_attack", "/knight/herb/dream-herb/yujiliang");
    set("perform_weapon_attack", "/knight/axe/xuanyuan-axe/jiuqipoxiao");
    set("perform_weapon_attack", "/knight/axe/xuanyuan-axe/kaitianpidi");
    set("perform_buff_1", "/knight/dodge/windy-steps/xingyun");
	  set("perform_buff_1", "/knight/herb/dream-herb/xiumugong");
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 200);
        set_skill("perception", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
        set_skill("unarmed", 200);
        set_skill("axe", 300);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic", 200); 
        set_skill("herb", 300)
        
        
        set_skill("xuanyuan-axe", 200);
        set_skill("dream-herb", 200);
		    set_skill("windy-steps", 200);
        set_skill("hanshan-strike", 220);
        set_skill("longlife-force", 200);
        
        map_skill("unarmed","hanshan-strike");
        map_skill("force", "longlife-force");
        map_skill("dodge","windy-steps");
        map_skill("move","windy-steps");
        map_skill("parry","xuanyuan-axe");
        map_skill("axe","xuanyuan-axe");
        map_skill("herb","dream-herb");
        
        setup();

       	carry_object("/obj/weapon/axe",([	
    						"name":  "切西瓜的斧头",
    						 ]))->wear();  

       	carry_object("/obj/armor/cloth",([	
    						"name":  "昴之衣",
    						 ]))->wear();  

}

