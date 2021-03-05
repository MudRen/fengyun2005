inherit NPC;
int tell_him();
void create()
{
        set_name("无聊少年", ({ "bored youngster","youngster" }) );
        set("gender", "男性" );
	set("title","游手好闲的");
        set("age", 19);
        set("long", "一个游手好闲无所事事的少年人。\n");

        set("combat_exp", 4000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
	set_skill("dodge", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
                (:random_move :),
	"无聊少年道：听说最近一个金狮镖局的镖师得到了口宝剑，锋利无比，当真是件神
兵利器。。。。 回头跟他去比试一下。\n",
        }) );
    	set("inquiry", ([
	        "宝剑" : (: tell_him :),
	        "sword" : (: tell_him:),
	        "镖师" : (: tell_him :),
	        "biaoshi" : (: tell_him:),
        ]));
	setup();
	add_money("coin", 1);
        carry_object("/obj/armor/cloth")->wear();
        if (!random(2))
		carry_object(__DIR__"obj/jade_sword");
        
}
int tell_him()
{
    	object me;
    	me =this_player();
    	tell_object(me,"无聊少年白了你一眼：就是那个老王喽。。。\n");
    	if (!REWARD_D->riddle_check(me,"失剑风波") && !REWARD_D->check_m_success(me,"失剑风波"))
    		REWARD_D->riddle_set(me,"失剑风波",1);
    	return 1;
}
