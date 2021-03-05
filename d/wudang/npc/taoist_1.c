inherit NPC;

void create()
{
        set_name("打杂的道士", ({ "taoist" }) );
        set("gender", "男性");
        set("long",
		"武当派打杂的弟子，着一身灰色的道袍。\n"
	);
        set("combat_exp", 70000);
        set("score", 200);
        set("class", "wudang");

        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("staff", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("taijiforce", 50);
        set_skill("taiji", 40);
        set_skill("five-steps", 40);
        set_skill("pangu-hammer",60);

        map_skill("force", "taijiforce");
        map_skill("staff","pangu-hammer");
        map_skill("parry", "pangu-hammer");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        setup();

        carry_object("/obj/weapon/hammer")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        

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
 
