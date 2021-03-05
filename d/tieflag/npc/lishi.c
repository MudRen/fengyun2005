// zhuo.c
inherit NPC;


void create()
{
        set_name("神斧力士", ({"li shi"}) );
        set("gender", "男性" );
        set("age", 26);
        set("agi",30);
        set("per", 10);
    	set("no_arrest",1);
        set("str",200);
        set("long",
		"神斧力士的精神已经被风九幽所控制。\n"
		);
        set("force_factor", 0);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("eff_gin", 1000);
        set("eff_kee", 1000);
        set("eff_sen", 1000);
        set("gin", 1000);
        set("kee", 1000);
        set("sen", 1000);
        set("max_force", 1000);
        set("force", 1000);
        set("combat_exp", 699999);
        set("score", 10000);
        set_skill("move", 150);
        set_skill("force", 100);
        set_skill("parry", 150);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("axe",200);
	setup();
	carry_object(__DIR__"obj/xuanaxe")->wield();
        carry_object("/obj/armor/cloth")->wear();  
}
