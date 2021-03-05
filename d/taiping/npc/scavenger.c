// scavenger.c

inherit NPC;

void create()
{
	set_name("捡破烂的", ({ "scavenger" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人不但自己捡破烂，身上也穿得破烂不堪。\n");
	set("combat_exp", 10);
	set("str", 27);
	set("force", 30);
	set("max_force", 30);
	
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		"捡破烂的吆喝道：收～破～烂～哪～\n",
		"捡破烂的嘴里嘟哝著，不知道说些什麽。\n",
		"捡破烂的伸手捉住了身上的虱子，一脚踩得扁扁的。 \n",
		(: random_move :)
	}) );
	carry_object("/obj/armor/cloth")->wear();
	add_money("coin", 5);
}

int accept_object(object me, object obj)
{
	command("smile");
	command("say 多谢这位" + RANK_D->query_respect(me) + "！");
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}
