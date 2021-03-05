// TIE@FY3

inherit NPC;
void create()
{
        set_name("香客", ({ "xiang ke","xiang ke" }) );
        set("gender", (random(2)? "女性":"男性") );
        set("age", random(40)+10);
        set("long","一个上山进香和游玩的香客。\n");
		set("combat_exp",5000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                "香客指着周围的景色叹道：真美呀．．\n",
				"香客道：不愧为一座名山．．\n",
                "香客对你说道：你也是来进香的？\n",
                "香客对你说道：在这儿进香可灵了！\n",
                "香客对你说道：你在这儿拜拜试试，百求百灵！\n",
                "香客对你说道：我上次在此进香求子，还真的灵验了，这次是来还愿的！\n",
        }) );

        set("attitude", "friendly");
        set("rank_info/respect", "施主");
        setup();
        carry_object("/obj/armor/cloth")->wear();

}
