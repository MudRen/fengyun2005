
inherit NPC;

void create()
{
        set_name("文人墨客", ({ "wenren", "ren"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是一位小有才华的文人，正在追求灵感。\n");

        set("combat_exp", 50000);
        set("attitude", "friendly");

	set_skill("dodge", 100);

        set("chat_chance", 1);
        set("chat_msg", ({
                "文人张了张口，又合上了。\n",
                "墨客踱来踱去，似乎正在打腹稿。\n",
        }) );
	
	setup();
        carry_object("/obj/armor/cloth")->wear();
}

