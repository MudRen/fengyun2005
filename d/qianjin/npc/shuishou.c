// beggar.c

inherit NPC;

void create()
{
        set_name("水手", ({ "shuishou" }) );
        set("gender", "男性" );
        set("age", 23);
        set("long", "一个正在摆摆样子，以搏情调的千金楼家奴。\n");
        set("combat_exp", 20000);
        set("str", 27);
	set("attitude", "friendly");
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		"水手向你笑了笑，又伸出手，象行礼，又象要赏钱。\n",
        }) );
        
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您一定会在这儿玩的开心的！");
        return 1;
}
