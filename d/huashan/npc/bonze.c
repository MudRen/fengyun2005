// woodcutter.c
inherit NPC;

void create()
{
        set_name("脚行僧", ({"bonze", "travel bonze"}) );
        set("gender", "男性" );
        set("age", 36);
        set("long",
		"一个游走四方的脚行僧。\n"
		);
        set("combat_exp", 120000);
        set_skill("move", 150);
        set_skill("parry", 150);
	set_skill("dodge", 160);
	set_skill("unarmed",150);
	setup();
	carry_object("/obj/armor/cloth")->wear();  
	carry_object("/obj/armor/sandal")->wear();
}
