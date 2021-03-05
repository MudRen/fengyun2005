
inherit NPC;

void create()
{
        set_name("关东大汉", ({ "dahan"}) );
        set("gender", "男性" );
        set("age", 32+ random(10));
        set("long", "这是一位从白山黑水来的关东大汉。\n");
        set("combat_exp", 8000);
        set("attitude", "aggrensive");
        set_skill("unarmed", 30 + random(100));
        set("chat_chance", 1);
        set("chat_msg", ({
                "关东大汉豪爽得向你大笑！\n",
                (: random_move :),
        }) );
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/xuechang");
}

