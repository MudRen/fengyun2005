// tea_waiter.c

inherit NPC;
void create()
{
	set_name("游客", ({ "you ke" }) );
	set("gender", (random(2)? "女性":"男性") );
	set("age", random(40)+10);
	set("long",
	    "一个上山游玩的香客。\n");
	set("combat_exp", 80000+random(20000));
	set_skill("unarmed",random(30)+30);
	set("chat_chance", 10);
	set("chat_msg", ({
	    (: random_move :),
	    "游客指着周围的景色叹道：真美呀．．\n",
	    "游客对你说道：你也是来游山的？\n",
	    "游客对你说道：你看这儿多美呀！\n",
	    "游客对你说道：我真的被这儿陶醉了！\n",
	}) );
	
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
		
}
