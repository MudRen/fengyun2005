inherit NPC;

void create()
{
        set_name("中年道士", ({ "adult taoist" }) );
        set("gender", "女性");
        set("age", 42);
        set("long",
"这是个上了年纪的道士，正在琢磨着三清道术。\n"
);
        set("combat_exp", 300000);
        set("score", 200);

        set("class", "taoist");

        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("三清宫", 6, "弟子");

        set_skill("move", 80);
        set_skill("force", 200);
        set_skill("spells", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("gouyee", 80);
        set_skill("notracesnow",140);
        set_skill("taoism", 70);
        set_skill("necromancy", 70);            
	set_skill("tenderzhi",80);

	map_skill("force", "gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("dodge","notracesnow");
	map_skill("spells", "necromancy");

        setup();    
	carry_object(__DIR__"obj/m_cloth")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="三清宫" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 三清宫不和别派的人过招。");
        return 0;
}
 
