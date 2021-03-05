// XXDER@FY
inherit NPC;
void create()
{
	set_name("燕儿" , ({ "yaner", "yan er", "girl" }) );
	set("long", "一位十一二岁的小丫头，正在玩弄手上的一个草编蚂蚱。\n");
	set("attitude", "friendly");

	set("age", 11);
        set("gender", "女性" );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/mazha");
}
