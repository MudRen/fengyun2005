inherit NPC;
#include <ansi.h> 

void create()
{
        set_name("五兆ぁこぐちえ", ({"wu"}));
        set("long", "一个精明能干，武功高强的赏罚堂堂主。\n");
        set("gender","男性");
				set("title",  "金钱帮"HIR" 赏罚堂堂主"NOR);
        set("class", "legend");   
           
        set("combat_exp", 6000000);
	
	set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("blade", 200);
        set_skill("shortsong-blade",200);
        set_skill("force", 150);
        set_skill("qidaoforce", 170);
        set_skill("fall-steps", 150);
        set_skill("move",200);
	set_skill("iron-cloth", 150);
	set_skill("xisui", 80);
	
	
	map_skill("iron-cloth", "xisui");
	map_skill("blade","shortsong-blade");
	map_skill("parry", "shortsong-blade");
        map_skill("unarmed", "qidaoforce");
        map_skill("dodge", "fall-steps");
	map_skill("force","qidaoforce");
	map_skill("move","fall-steps");

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
		(: perform_action, "blade.duangechangmeng" :),
        }) );

        setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  HIY"明黄锦袍"NOR,
    						"long": "一件黄缎长袍，做工非凡。\n",
    						 ]))->wear();    
	carry_object("/obj/weapon/blade",([	
    						"base_damage":  100,
    						 ]))->wield();    
}
