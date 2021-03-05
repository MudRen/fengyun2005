inherit SMART_NPC;
#include <ansi.h> 

void create()
{
        set_name("吴青", ({"wu qing", "wu", "qing"}));
        set("long", "一个精明能干，武功高强的赏罚堂堂主。\n");
        set("gender","男性");
		set("title",  "金钱帮"HIR" 赏罚堂堂主"NOR);
        set("class", "legend");
        
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set("combat_exp", 5000000);
	
		set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("force", 150);
        set_skill("qidaoforce", 170);
        set_skill("fall-steps", 200);
        set_skill("move",200);

		set("perform_busy_d", "legend/dodge/fall-steps/luoyeqiufeng");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
		map_skill("parry", "qidaoforce");
        map_skill("unarmed", "qidaoforce");
        map_skill("dodge", "fall-steps");
		map_skill("force","qidaoforce");
		map_skill("move","fall-steps");

        setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  HIY"明黄锦袍"NOR,
    						"long": "一件黄缎长袍，做工非凡。\n",
    						 ]))->wear();    
}
 
 
int accept_object(object who, object ob)
{
            command("grin");
            command("say 瞎了眼的狗才，竟敢贿赂我？？");
	    kill_ob(who);
            return 0;
}
 
