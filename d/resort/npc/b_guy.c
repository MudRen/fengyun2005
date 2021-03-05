inherit SMART_NPC;

void create()
{
        set_name("白袍公", ({ "oldguy" }) );
		set("class","legend");
        set("gender", "男性" );
        set("age", 65);
        set("no_arrest",1);

        set("attitude", "peaceful");

        set("long",     "白袍公除了下棋，什么也不做。\n");

        set("combat_exp", 1200000);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
		set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
		set_skill("meihua-biao",80);
        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
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
        carry_object(__DIR__"obj/bqi")->wield();
        carry_object(__DIR__"obj/wcloth")->wear();
}

