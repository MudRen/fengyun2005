inherit NPC;

void create()
{
        set_name("李长慎", ({ "li" }) );
        set("gender", "男性");
        set("age", 29);
        set("long",
		"武当派弟子，着一身灰色的道袍。\n"
	);
        set("combat_exp", 70000);
        set("score", 200);
        set("class", "wudang");

        create_family("武当派", 58, "弟子");

        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("taijiforce", 50);
        set_skill("taiji", 40);
        set_skill("three-sword", 50);
        set_skill("five-steps", 40);

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        setup();

        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/gongxiang");

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 10000 ) {
                        say("李长慎把钱放进怀里说道：你可以走了。\n");
                        who->set_temp("marks/偷书", 0);
                        return 1;
                } else {
                    say("李长慎厉声说道：我是不会接授贿赂的！\n");
                        return 0;
                }
        return 0;
} 

 
