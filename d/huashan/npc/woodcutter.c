// woodcutter.c
inherit NPC;

void create()
{
        set_name("青年樵夫", ({"woodcutter"}) );
        set("gender", "男性" );
        set("age", 26);
        set("agi",30);
        set("per", 10);
        set("long",
		"樵夫正用力的砍着眼前的大树。\n"
		);
        set("combat_exp", 100000);
        set_skill("move", 150);
        set_skill("parry", 150);
	set_skill("dodge", 160);
        set_skill("axe",150);
	setup();
	carry_object("/obj/weapon/woodaxe")->wield();
	carry_object("/obj/armor/cloth")->wear();  
}
