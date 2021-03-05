
inherit NPC;

void create()
{
        set_name("吐鲁番商人", ({ "tulufan trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位在丝绸之路行商的商人。\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
	set("env/wimpy", 50);
        set_skill("shuaijiao", 30);
	set_skill("unarmed",40);
	map_skill("unarmed", "shuaijiao");
        set("chat_chance", 30);
        set("chat_msg", ({
                "商人喃喃道：为了赚钱，天天要把脑袋系在裤腰带上过这丝绸之路！\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "商人嘶叫道：你无非就是要钱么，为什么一定要杀我？\n",
                (: random_move :),
        }) );

	
	setup();
        carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/nang");
	carry_object(__DIR__"obj/milk");
}

