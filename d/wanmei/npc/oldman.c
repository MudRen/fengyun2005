inherit NPC;
void create()
{
        set_name("满脸风霜的老人", ({ "oldman", "old man", "man" }) );
        set("gender", "男性");
        set("age", 74);
        set("long",
"这是一个满脸风霜的老人，但他双目有神，太阳穴高高隆起！\n"
               ); 

	set("class","fighter");
        set("attitude", "peaceful");
        set("combat_exp", 2000000);
        set("reward_npc", 1);
	set("difficulty", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
                "满脸风霜的老人用袖子远远地一拂，你立刻感到透不过气来。\n",
        }) );
        
        set_skill("force", 100);
        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 200);
	set_skill("move", 150);
	set_skill("doomforce", 150);
        set_skill("doomstrike", 150);
	set_skill("doomsteps", 150);
        
        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hantian" :),
        }) );

        setup();
	carry_object("/obj/armor/cloth")->wear();
}
