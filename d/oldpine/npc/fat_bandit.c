// fat_bandit.c

inherit NPC;
void call_for_help();
void create()
{
        set_name("矮胖子土匪", ({ "bandit" }) );
        set("title","老云寨");
        set("gender", "男性");
        set("age", 36);
        set("long", "这家伙又矮又胖，圆滚滚的眼珠子在满脸肥肉中骨碌碌地转来转去。\n");
        set("combat_exp", 400000);
        set("class","lama");
        
        set("attitude", "aggressive");
        
        set_skill("iron-cloth", 120);
        set_skill("unarmed", 150);
        set_skill("bloodystrike", 150);
        set_skill("jin-gang",80);
        set_skill("parry",150);
        
		map_skill("unarmed", "bloodystrike");
		map_skill("iron-cloth","jin-gang");
	
		set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fofawubian" :),
                "\n矮胖子土匪大叫：把你身上的钱通通留下来！\n",
                "\n矮胖子土匪嘴里不乾不净地咒骂著。\n",
                (: call_for_help :),
        }) );

        setup();
        carry_object(__DIR__"obj/leather")->wear();
}


void call_for_help()
{
        object ob;

        if( query("called_help") || present("bandit chief", environment()) ) return;
        set("called_help", 1);
        command("say 他妈的，点子爪子太硬....");
        say("矮胖子土匪大叫：老大！老大！兄弟撑不住啦！\n");
        ob = new(__DIR__"bandit_chief");
        ob->move(environment());
        ob->start_help();
}
