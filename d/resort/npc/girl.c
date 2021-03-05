// girl.c

inherit SMART_NPC;

void create()
{
        set_name("小翠", ({ "xiao cui", "cui", "xiao" }) );
		set("class","legend");
        set("gender", "女性" );
        set("age", 15);

        set("attitude", "peaceful");

        set("long",     "小翠是铁雪山庄的丫环，经常偷吃茶园里的糕点。\n");

        set("combat_exp", 10000);

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set_skill("sword", 40);
        set_skill("force", 30);
        set_skill("literate", 70);

        set_skill("qidaoforce", 40);
        set_skill("diesword",20);
        set_skill("meihua-shou", 20);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("sword","diesword");
        map_skill("parry", "diesword");
        map_skill("dodge", "fall-steps");

		set("perform_busy_u", "legend/unarmed/meihua-shou/meihai");
//		set("perform_weapon_attack", "legend/sword/diesword/caidiekuangwu");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(50) :),
        }) );

        setup();

        carry_object(__DIR__"obj/thin_sword")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}

 
