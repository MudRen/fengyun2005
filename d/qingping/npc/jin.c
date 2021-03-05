// XXDER@FY3
inherit SMART_NPC;
void create()
{
		set_name("金不畏" , ({ "buwei", "jin buwei", "jin" }) );
		set("long", "此人身高八尺，背阔三停，是条不折不扣的莽汉。\n");
		set("attitude", "friendly");

		set("age", 30);
        set("gender", "男性" );

        create_family("清平山庄", 1, "弟子");
		set("combat_exp", 500000);
	
		set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("qingpingsword", 120);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 120);
        set_skill("parry",100);
        
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        map_skill("parry","qingpingsword");
        
		set("perform_busy_w", "shenshui/sword/qingpingsword/fengzijue");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
