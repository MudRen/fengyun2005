
inherit NPC;

void create()
{
        set_name("农夫", ({ "farmer" }) );
        set("gender", "男性" );
        set("age", 25+random(20));
        set("long", "一位相貌平凡农夫，正在为生活而忙碌着。\n");
        set("combat_exp", 200+random(200));
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                        (: random_move :)
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

