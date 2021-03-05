

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("青衣家丁", ({ "guard" }) );
        set("gender", "男性" );
        set("attitude", "aggressive");
        
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        
        set("max_force", 100);
        set("force", 100);
        set("force_factor", 10);

        set("long","这是一位黑松堡的家丁，专负责盘察去黑松堡的行人。\n");

        set("combat_exp", 2000);
        
        set_skill("hammer", 40);
	set_skill("dodge", 40);
	set_skill("parry", 50);
	setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/6hammer")->wield();

}

void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checklooking");
                call_out("checklooking", 1, ob);
        }
}

void checklooking(object ob)
{

	 if (!ob || environment(ob)!=environment())
	 	return;
	 	
	 if ( random((int)ob->query("per")) < 5  )
	 {
		command("say 站住！你干什么的。");
		command("say 看你那贼眉鼠眼，尖嘴猴腮的样儿，决不是什么好东西！");
        kill_ob(ob);
	 }	
}
