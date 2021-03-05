inherit NPC;
void create()
{
        set_name("乌拉泊商人", ({ "wulapo trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位在丝绸之路行商的商人。\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
	set("env/wimpy", 50);
        set_skill("shuaijiao", 30);
	set_skill("unarmed",40);
	map_skill("unarmed", "shuaijiao");
	set_skill("blade",100);
        set("chat_chance", 30);
        set("chat_msg", ({
                "商人喃喃道：我不会迷路了吧？\n",
                "商人道：听说天山中一百年才得一见的雪莲今年会出现！\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "商人叫道：杀人是要偿命的！\n",
                (: random_move :),
        }) );

	
	setup();
	add_money("coin", 5);
	carry_object(__DIR__"obj/knife")->wield();
	carry_object(__DIR__"obj/carpet")->wear();
}

