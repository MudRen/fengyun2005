// maniac.c

inherit NPC;

void create()
{
//      object ob;

        set_name("逍遥侯", ({ "xiaoyao", "xiaoyao hou", "hou" }) );
        set("gender", "男性");
        set("age", 67);
        set("long",
                "这个老头子正对著你龇牙裂嘴，他看起来似乎疯了。\n");

        set("cor", 30);
        set("class","taoist");
        set("combat_exp", 3000000);
        set("bellicosity", 30000);
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("force", 100);
        set_skill("spells", 200);
       	set_skill("notracesnow",200);
       	set_skill("tenderzhi",150);
       	set_skill("necromancy", 160);
        set_skill("parry",150);
        set_skill("move",150);
        
        map_skill("move","notracesnow");
        map_skill("unarmed","tenderzhi");
        map_skill("dodge","notracesnow");
        map_skill("spells", "necromancy");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "feeblebolt" :),
        }) );
        
        setup();
		carry_object("/obj/armor/cloth")->wear();
}