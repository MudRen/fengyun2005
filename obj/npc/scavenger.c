// scavenger.c

inherit NPC;

void create()
{
	set_name("收破烂的", ({ "scavenger" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人不但自己收破烂，身上也穿得破烂不堪。\n");
	set("combat_exp", 2000);
	
	setup();
	set("chat_chance", 2);
	set("chat_msg", ({
		"收破烂的吆喝道：收～破～烂～哪～\n",
		"收破烂的嘴里嘟哝著，不知道说些什麽。\n",
		"收破烂的伸手捉住了身上的□子，一脚踩得扁扁的。 \n",
		(: random_move :)
	}) );
	carry_object("/obj/armor/cloth")->wear();
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
