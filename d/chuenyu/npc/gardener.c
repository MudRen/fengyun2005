inherit NPC;

void create()
{
        set_name("园工", ({ "gardener" }) );
        set("nickname", "黑松一剪");
        set("gender", "男性");
        set("age", 32);
        set("long",
"黑松一剪是方园几十里有名的园工。一把大剪使的出神如化。");
        set("combat_exp", 30000);
        set("class","taoist");
        set("score", 200);
        set_temp("max_guard",4);
        
        set("fly_target",1);
        
        set("atman", 1500);
        set("max_atman", 1500);

        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 50);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :)
        }) );

        set_skill("spells", 50);
        set_skill("scratching", 30);
        set_skill("unarmed", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("gouyee", 30);
        set_skill("necromancy", 30);

        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();
        carry_object(__DIR__"obj/lscissors")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

