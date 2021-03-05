inherit NPC;

void create()
{
        set_name("老道士", ({ "old taoist" }) );
        set("gender", "男性");
        set("age", 72);
        set("long",
"这是个很老的道士，眼光却炯炯有神。\n"
);
        set("combat_exp", 400000);
        set("score", 200);

        set("class", "taoist");
        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
        }) );

        create_family("三清宫", 5, "弟子");

        set_skill("move", 120);
        set_skill("force", 200);
        set_skill("spells", 100);
        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("gouyee", 120);
        set_skill("notracesnow",160);
        set_skill("taoism", 120);
        set_skill("necromancy", 100);            
	set_skill("snowshade-sword",120);

	map_skill("force", "gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("dodge","notracesnow");
	map_skill("spells", "necromancy");
	map_skill("parry", "snowshade-sword");
	map_skill("sword", "snowshade-sword");
	

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        add_money("coin", 30);
	carry_object(__DIR__"obj/o_cloth")->wear();
	carry_object(__DIR__"obj/r_sword")->wield();
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
 
