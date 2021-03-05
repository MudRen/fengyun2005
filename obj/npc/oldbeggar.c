// TIE@FY3
inherit NPC;
void create()
{
        set_name("老乞丐", ({ "old beggar","beggar" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个满脸风霜之色的老乞丐。\n");
        set("combat_exp", 4000);
	create_family("丐帮", 12, "弟子");
	set("title","丐帮一袋弟子");
	
	set("class","beggar");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "老乞丐说道：好心的大爷哪～ 赏我要饭的几文钱吧～\n",
                (: random_move :),
        }) );
              
       	set_skill("begging",150);
        
        setup();
        carry_object(BOOKS"force_11");
        carry_object("obj/armor/cloth")->wear();
}


int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + "，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
        return 0;
}
 
void init()
{
	object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
	{
		command("beg silver from "+ob->get_id());
	}
