
inherit NPC;

void create()
{
	set_name("寻仙客", ({ "wandering visitor","visitor"}) );
	set("gender", "男性" );
	set("age", 35);
	set("long", "一个漂泊四海的旅人，四处寻仙问道。\n");
	set("attitude", "peaceful");
        set("title", "一心向道");
        set("combat_exp", 750000);
        set_skill("unarmed", 100);
        set_skill("calligraphy", 120);
        set_skill("force", 50);
		set_skill("iron-cloth", 100);
		set_skill("dodge",100);
		set_skill("parry",100);
		set_skill("feixian-steps",100);
		map_skill("dodge","feixian-steps");
		map_skill("unarmed", "calligraphy");
    
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "\n寻仙客漫步长吟道：白云深处，白云深处？这仙人究竟在何方呢？\n",
        }) );

		setup();
        carry_object(__DIR__"obj/piyi")->wear();
 
}
