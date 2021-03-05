inherit NPC;

void create()
{
        set_name("金府门房", ({ "jin guard","guard" }) );
        set("long",
                "他年纪已经很老，满脸都是老奸巨滑的样子。\n"
                );

        set("attitude", "peaceful");
        set("cor", 26);
        set("agi", 60);
        set("combat_exp", 500000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "门房慢吞吞地说：是。。想见金大帅的吗？。。\n",}) );

        set_skill("unarmed", 100);
        set_skill("parry", 80);
        set_skill("dodge", 100);
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
