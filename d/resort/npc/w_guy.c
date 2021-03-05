inherit SMART_NPC;

void create()
{
        set_name("黑袍公", ({ "oldguy" }) );
        set("gender", "男性" );
	set("class","legend");
	set("reward_npc", 1);
	set("difficulty", 15);
	set("no_arrest",1);
	
        set("age", 65);
        set("attitude", "peaceful");

        set("max_atman", 1000);
        set("atman", 1000);
        set("max_force", 50000);
        set("force", 50000);
                
        set("long",     "黑袍公除了下棋，什么也不做。\n");

        set("combat_exp", 1500000);

        set_skill("unarmed", 100);
        set_skill("throwing", 250);
		set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 91);
        set_skill("fall-steps", 10);
		set_skill("parry",100);
		set_skill("meihua-biao",100);
	
		map_skill("parry","meihua-biao");
		map_skill("throwing", "meihua-biao");
		map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");
		map_skill("force","qidaoforce");

		set("perform_buff_1", "legend/force/qidaoforce/juqi");
		set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );;
        
        setup();
        carry_object(__DIR__"obj/wqi")->wield();
        carry_object(__DIR__"obj/bcloth")->wear();
}
