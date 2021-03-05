inherit NPC;
void call_for_help();
void create()
{
        set_name("大喽罗", ({ "da louluo","louluo" }) );
        set("gender", "男性");
        set("age", 36);
        set("long",
                "一个饿得肚子看着寨门的饿虎岗强盗。。\n");
        set("combat_exp", 560000);
        set("score", 80);
        set("no_arrest",1);
        
        set("max_kee",3000000);
        set("kee",3000000);
        set("max_sen",1000000);
        set("sen",1000000);
        set("max_gin",1000000);
        set("gin",1000000);
	
	set("str",60);
	set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                "\n大喽罗撇撇嘴骂道：“这世道强盗真他妈难做，早知道还不如改行当要饭的。”\n",
                "\n大喽罗嘴里不停地地咒骂著。\n",
                
        }) );
        set_skill("blade", 100);
	set_skill("unarmed",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
	set_skill("demon-blade",80);
	map_skill("blade","demon-blade");
        setup();
        carry_object("/obj/weapon/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object me)
{
        command("say 到饿虎岗撒野？");
        command("kao");
        kill_ob(me);
        return 1;
}

int accept_object(object me, object obj)
{
        if(obj->query("id")=="meat")
	{
		me->set_temp("yuehu",1);
		say( "大喽罗双眼放光，放下家伙，饿虎扑食般冲过来大嚼大啃起来。\n");
    		return 1;
     	} 
     	else {
		command("shake");
       		return 0;
	}
	return 0;
}
