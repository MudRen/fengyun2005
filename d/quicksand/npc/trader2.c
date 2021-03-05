
inherit NPC;

void create()
{
        set_name("准葛儿商人", ({ "trader"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是一位从准葛儿来的商人。\n");
        set("combat_exp", 50000);
        
        set("attitude", "friendly");

		set("env/wimpy", 50);
        set("agi", 2);
        
        set_skill("unarmed", 50);
		set_skill("iron-cloth", 100);
		set_skill("bloodystrike", 70);
		set_skill("parry",50);
		map_skill("unarmed", "bloodystrike");
        
        set("chat_chance", 2);
        set("chat_msg", ({
                "商人说：胡里马，忽里牛，兜兜儿布刷夏？\n",
                (: random_move :),
        }) );
        
        
	
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/teablock");
		carry_object(__DIR__"obj/perfume");
}

