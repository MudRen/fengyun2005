//Tushen@Fygroup
//Based on Silencer's code.Copyright all reserved.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("梦儿", ({ "meng er" }) );
        set("gender", "女性");
        set("age", 26);   
      	set("chat_chance", 1);
	set("chat_msg", ({
"梦儿怔怔的坐在地上，又开始发起呆了。\n",
	}) );

        set("attitude", "friendly");
        set("title",HIR"張狩"NOR);
        set("nickname", HIG"梦里花落知多少"NOR);
        set("score", 80000);
        set("reward_npc", 1);
		    set("difficulty",20);
		    set("class","legend");
        set("death_msg",CYN"\n$N叹道：人若是能死两次，也不失为一件新鲜的事。\n"NOR);
        set("combat_exp", 12000000);        
        
    set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
    set("perform_busy_d1", "legend/dodge/fall-steps/qiufengluoye");
		set("perform_weapon_attack", "npc/sword/zensword/menghuankonghua");

		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(40) :),
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
        
        set_skill("cloudforce", 180);
		    set_skill("fall-steps", 180);
		    set_skill("zensword", 200);
        set_skill("zen", 180);
        set_skill("dabei-fu", 200);
        set_skill("xiaodao", 180);
        set_skill("six-sense", 200);
        
        map_skill("unarmed","dabei-fu");
        map_skill("force", "cloudforce");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");
        map_skill("parry","zensword");
        map_skill("sword","zensword");
        setup();
    	carry_object("/obj/weapon/sword",([	
    						"name":  MAG"梦里花落"NOR,
    						 ]))->wield();  

    	carry_object("/obj/armor/cloth",([	
    						"name":  "張之衣",
    						 ]))->wear();  

}

