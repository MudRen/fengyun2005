// dtz.c

inherit NPC;

void create()
{
	set("title","匹夫无罪");
        set_name("怀壁其罪", ({ "mf tester","tester" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "我靠！打我啊，你打啊打啊\n");

        set("combat_exp", random(10000));

        set_skill("unarmed", 20);
        set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
	add_money("silver", 1);
        carry_object("/obj/armor/cloth")->wear();        
}

void die()
{
	//目前成功率是100	
	MF_D->new_vo(random(100),"cloth")->move(this_object());
	::die();
}