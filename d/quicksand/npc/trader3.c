inherit NPC;

void create()
{
        set_name("西夏商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位从西夏来的商人。\n");
        set("combat_exp", 70000);
        set("attitude", "friendly");
	
		set("env/wimpy", 50);
        set("agi", 2);
        
        set_skill("blade", 50);
		set_skill("shortsong-blade", 50);
		set_skill("fall-steps", 50);
		set_skill("dodge", 50);
		set_skill("parry", 50);
	
		map_skill("blade", "shortsong-blade");
		map_skill("parry", "shortsong-blade");
		map_skill("dodge", "fall-steps");
	
		set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
                "西夏商人说道：其揣可可，中原人大大地坏！\n",
        }) );

		setup();
	
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/hu-blade")->wield();
		carry_object(__DIR__"obj/perfume");
		carry_object(__DIR__"obj/fake-tooth");
}

