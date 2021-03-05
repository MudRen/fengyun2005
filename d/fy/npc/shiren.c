// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_poem();
void create()
{
        set_name("浪游诗人", ({ "nomadic bard", "bard"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是一位小有才华的诗人，正在观望风云城。\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
	set_skill("dodge", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
                "吟游诗人看了看风云城叹道：好城！好城！\n",
                "吟游诗人踱来踱去，似乎正在打腹稿。\n",
        }) );
        set("inquiry", ([
                "风云赞歌" : (: give_poem :),
                "poem" : (: give_poem :)

        ]));
	setup();

        carry_object("/obj/armor/cloth")->wear();
}

int give_poem()
{
	object obj;
	if( !query("given"))
	{
		command("say 既然你对我的诗词如此崇拜，这首就送于你吧．\n");
		obj = new(__DIR__"obj/poem");
		obj->move(this_player());
		set("given",1);
	}
	else
		command("say 我知道你很崇拜我，但我还要一会儿才能写好这诗．\n");
	return 1;
}

void reset()
{
	delete("given");
}
