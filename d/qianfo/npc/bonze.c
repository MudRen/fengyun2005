inherit NPC;
void create()
{
        set_name("云游僧人", ({ "bonze" }) );
        set("gender", "男性" );
        set("class", "bonze");
        set("age", 52);
        set("str", 26);

        set("long", "一个笑咪咪的僧人对著你微微颔首。\n");
        set("combat_exp", 6000);
        set("attitude", "friendly");

        set_skill("force", 60);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/shoe")->wear();
}
int accept_fight(object me)
{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
}
