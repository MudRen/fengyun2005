// tall_bandit.c

inherit NPC;

void create()
{
        set_name("瘦子土匪", ({ "bandit" }) );
        set("title","老云寨");
        set("gender", "男性");
        set("age", 27);
        set("long",     "这家伙长得高高瘦瘦，脸色苍白，一付无精打采的样子。\n");
        set("combat_exp", 650000);
        set("class","assassin");
        set("attitude", "aggressive");
        
        set_skill("move", 150);
        set_skill("dodge", 150);
		set_skill("sword",150);
		set_skill("lefthand-sword",150);
		set_skill("jinhong-steps",150);
		
		map_skill("sword","lefthand-sword");
		map_skill("dodge","jinhong-steps");
		map_skill("parry","lefthand-sword");
		map_skill("move","jinhong-steps");
		
		set("chat_chance_combat", 90);
	    	set("chat_msg_combat", ({
        	(: perform_action, "sword.duxin" :),
        }) );
            
        setup();
        carry_object(__DIR__"obj/long_sword")->wield();
        carry_object("/obj/armor/cloth")->wear();
}
