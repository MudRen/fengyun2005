// bandit_leader.c

inherit NPC;

void create()
{
        set_name("土匪首领", ({ "bandit leader", "chief", "leader" }) );
        set("title","老云寨");
        set("gender", "男性");
        set("age", 47);
        set("long",     "这家伙眼神凶恶，一双精光四射的眼珠正盯著你的脖子。\n");
        set("combat_exp", 50000);
        set("score", 7700);
        set("bellicosity", 3000);
        set("attitude", "aggressive");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                "\n土匪首领阴恻恻地说道：这种三脚猫的功夫也敢上老云寨来撒野？！\n",
                "\n土匪首领说道：去你的，老子今天要剁下你的头来练练毒爪！\n",
                "\n土匪首领虎吼一声，欺身上前。\n"
        }) );
        
        set_skill("blade", 60);
        set_skill("parry", 70);
        set_skill("dodge", 70);

        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 50);

        setup();
        carry_object("obj/weapon/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
}

