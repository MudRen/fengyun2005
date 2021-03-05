
inherit NPC;

void create()
{
	set_name("不丹人", ({ "bhutanese"}) );
	set("gender", "女性" );
	set("age", 25);
	set("str", 10);
	set("long", "一个喜穿紫衫的不丹年轻人。\n");
	set("attitude", "peaceful");
        set("title", "异乡客");
        set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
	set_skill("iron-cloth", random(30)+10);
        map_skill("unarmed", "bloodystrike");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "\n不丹人赞叹道：你听过西藏诗人密拉勒斯巴的一首诗么？那简简单单\n的十四个字啊，真象男儿们的热血一样叫人振奋。\n",
        }) );

	setup();
	carry_object(__DIR__"obj/magcloth")->wear();
}
