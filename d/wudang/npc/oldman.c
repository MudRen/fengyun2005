inherit NPC;

void create()
{
        set_name("老者", ({ "old man", "man" }) );
        set("gender", "男性");
        set("age", 54);
        set("long",
		"这位老人正在悠闲自得地抽着旱烟。\n"
	);
	set_skill("dagger", 10+random(50));
	set("combat_exp",2000);
        setup();
	carry_object(__DIR__"obj/yandou")->wield();
	carry_object("/obj/armor/cloth")->wear();
}
