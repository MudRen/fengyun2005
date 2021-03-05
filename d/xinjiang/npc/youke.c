// tea_waiter.c

inherit NPC;
void create()
{
        set_name("游客", ({ "you ke" }) );
        set("gender", (random(2)? "女性":"男性") );
        set("age", random(40)+10);
        set("long",
                "一个慕名前来游玩柏孜克里克千佛洞的人。\n");
	set("combat_exp", 2225+random(500));
        set("chat_chance", 1);
        set("chat_msg", ({
                "游客指着周围的景色叹道：真美呀．．\n",
		"游客道：不愧为当年的佛教重地．．\n",
                "游客对你说道：我好象在哪儿见过你？\n",
                "游客指着你道：这，这不是当今武林第一高手吗？！\n",
                "游客悄悄对你说道：听说你刚在中原闯了个大祸？\n",
                "游客对你说道：我也正要去乌拉泊，不如我们结伴而行？\n",
        }) );

        set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear();

}
