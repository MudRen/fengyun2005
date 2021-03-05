inherit SMART_NPC;
void create()
{
        set_name("花飞", ({ "huafei" }) );
        set("gender", "男性" );
        set("long","
此人满身锦衣，身亮欣长，苍白而清俊的面容上，带著一份孤傲冷
削之色，仿佛未将任何人看在眼里。\n");
        set("age", 18);
        set("per", 58);
        set("no_arrest",1);
         set("fly_target",1);
              
        create_family("帝王谷", 2, "弟子");            
                      
        set("combat_exp", 8100000);
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
		"花飞冷冷的盯了你一眼。\n",
        }) );
        
	    auto_npc_setup("wang",250,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);
		setup();
		
		set_skill("liangyi-force",200);
		set("perform_busy_w","yinshi/hammer/pangu-hammer/rufengsibi");
		set("smartnpc_busy",1);
		
		carry_object(BOOKS"skill/qidaoforce_11")->wear();
		carry_object(__DIR__"obj/9ring")->wield();
}
