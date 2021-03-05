// TIE@FY3
inherit NPC;
int give_letter();
void create()
{
		set_name("黑珍珠", ({ "black pearl", "pearl" }) );
		set("title", "大漠飞鹰");
		set("gender", "男性" );
		set("age", 22);
		set("long","黑发，黑纱，黑袍，黑靴，黑鞭，黑衣人。\n");
        set("chat_chance", 2);
        set("chat_msg", ({
                "黑珍珠说道：唉，怎么转来转去都在这沙漠里，耽搁了送信可怎么办！\n",
        }) );

		set("inquiry", ([
			"送信": (: give_letter :),
			"信": (: give_letter :),
			"letter": (: give_letter :),
			"给谁":		"废话，信封上不是写着么！",
		]) );
	
		set("attitude", "peaceful");
	
		set_skill("whip", 100);
		set_skill("thunderwhip", 60);
		set_skill("parry",60);
		set_skill("dodge",60);
		set_skill("move",100);
		set_skill("zuixian-steps",100);
	
		map_skill("whip","thunderwhip");
		map_skill("parry","thunderwhip");
		map_skill("dodge","zuixian-steps");
		map_skill("move","zuixian-steps");
	
		set("combat_exp", 120000);
		setup();
        carry_object(__DIR__"obj/shenxue")->wear();
        carry_object(__DIR__"obj/baojia")->wear();
        carry_object(__DIR__"obj/zhiai")->wear();
        carry_object(__DIR__"obj/sidai")->wield();
}


int give_letter()
{
        object obj;
		if( !query("given"))
        {
			command("say 你能帮忙将此信送出么，可别丢了！\n");
			obj = new(__DIR__"obj/letter");
			obj->move(this_player());
			set("given",1);
        }
		else
		{
			command("say 咦？我那封信怎么不见了？是不是你偷了？还给我！\n");
			fight_ob(this_player());
		}
        return 1;
}

void reset()
{
	delete("given");
}
