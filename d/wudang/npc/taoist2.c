inherit NPC;

void create()
{
        set_name("彭长净", ({ "peng" }) );
        set("gender", "男性");
        set("age", 34);
        set("long",
		"彭长净乃武当火工道人，身着灰色道袍\n"
	);
        set("combat_exp", 5000+random(5000));
        set("class", "taoist");

        create_family("武当派", 58, "弟子");

        set_skill("move", 10+random(40));
        set_skill("force", 10+random(40));
        set_skill("unarmed", 10+random(40));
        set_skill("sword", 10+random(40));
        set_skill("parry", 10+random(40));
        set_skill("dodge", 10+random(40));
        set_skill("taijiforce", 10+random(30));
        set_skill("taiji", 10+random(30));
        set_skill("three-sword", 10+random(30));
        set_skill("five-steps", 10+random(30));

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");

        set_skill("changelaw", 10);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),
        }) );
        
        setup();

        carry_object(__DIR__"obj/sword")->wield();
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
 
void die()
{
//      int i;
        object killer,owner;

        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
	     killer->set_temp("marks/彭长净", 1);
	}
	
        ::die();

}
