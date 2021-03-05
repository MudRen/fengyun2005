inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("盛存孝", ({ "sheng cunxiao","cunxiao" }) );
        set("nickname",HIM "紫心剑客" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long","一条面膛紫红、狮鼻阔口，颔下蓄着短髭的中年大汉。\n");
       
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 1);

        set("combat_exp", 1750000);        
       
		set("perform_busy_d", "huashan/dodge/cloud-dance/yexuechuji");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 150);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
        set_skill("sword",150);
                
        set_skill("qiuzhi-sword",150);            
        set_skill("hanmei-force", 150);
		set_skill("anxiang-steps",170);
        set_skill("zhaixin-claw",140);
        set_skill("cloud-dance",180);
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("sword","qiuzhi-sword");
        map_skill("parry","qiuzhi-sword");
        map_skill("dodge","cloud-dance");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object(__DIR__"obj/n_sword1")->wield();
		carry_object("/obj/armor/cloth")->wear();
}
 