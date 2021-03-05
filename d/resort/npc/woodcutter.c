// woodcutter.c

inherit NPC;

void create()
{
	set_name("樵夫", ({ "woodcutter" }) );
	set("gender", "男性" );
	set("age", 26);
	set("long", "你看到一个粗壮的大汉，身上穿著普通樵夫的衣服。\n");
	set("combat_exp", 3340);
	set("str", 30);
	set("chat_chance", 1);
	set("chat_msg", ({
		"樵夫说道：唉....日子越来越不好过罗。\n",
		(: random_move :)
	}) );
	set("env/wimpy", 10);
	setup();
	carry_object(__DIR__"obj/lumber_axe")->wield();
	carry_object("/obj/armor/cloth")->wear();
}
