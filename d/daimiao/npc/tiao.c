inherit NPC;

void create()
{
	set_name("挑山夫", ({ "labor" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人是以往山上挑东西为生的。\n");
	set("combat_exp", 70000);
	
	set_skill("staff",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		(: random_move :)
	}) );
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/biandan")->wield();
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
