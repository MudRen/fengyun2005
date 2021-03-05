inherit SMART_NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack();

void create()
{
        set_name("冷青霜", ({ "leng qingshuang","leng" }) );
        set("title",HIG "寒枫堡" NOR);
        set("gender", "女性");
        set("age", 28);
        set("long",
"一个手撑湘妃竹伞的白衣女子。\n");
       
        set("chat_chance", 1);
		set("chat_msg", ({
	 	"冷青霜看着长长叹息：“二妹，难道你也爱上了大旗门下的弟子，
难道你没有看到姐姐我的榜样？”\n",
	}) );
       
        set("attitude", "friendly");
        set("score", 200);
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 1);
        
        set("combat_exp", 2000000);        
        set("per",50);
        
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
        set_skill("cloud-dance",180);
        set_skill("anxiang-steps",180);
        set_skill("qingfeng-sword",180);            
        set_skill("hanmei-force", 150);
        set_skill("zhaixin-claw",140);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("force", "hanmei-force");
        map_skill("sword","qingfeng-sword");
        map_skill("parry","qingfeng-sword");
        map_skill("dodge","cloud-dance");
        map_skill("move","anxiang-steps");
        
        set_temp("apply/armor", 30);
        setup();

        carry_object("/obj/weapon/sword")->wield();
		carry_object("/obj/armor/cloth")->wear();
}

