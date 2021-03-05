// greeting_bonze.c

inherit NPC;

void create()
{
        set_name("知客僧", ({ "greeting bonze", "bonze" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("age", 37);
        set("str", 26);

        set("long",
                "这个知客僧脸色和蔼，虽然在寺中的地位不高，但是他总是让人有一种\n"
                "值得信赖的感觉。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");

        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

int accept_fight(object me)
{
        command("say 阿弥陀佛！小僧武功低微，认输便是。\n");
        return 0;
}
