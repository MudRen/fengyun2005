inherit NPC;
int tell_him();
void create()
{
        set_name("王镖师", ({ "biaoshi wang","wang"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "老王的个子不高但一副大胡子，相当地精明能干。\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");
        
        set_skill("hammer", 150);
	set_skill("dodge", 150);
        set_skill("iron-cloth", 200);
        set_skill("parry",150);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "王镖师道：什么？你肯出十倍的价钱？\n",
                "王镖师气得直跺脚：我被骗了！\n",
        }) );
    	set("inquiry", ([
	        "sword" : (: tell_him :),
	        "宝剑" : (: tell_him:),
	        "尚方宝剑" : (: tell_him:),
        ]));
	
	setup();
	
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

int tell_him()
{
    	object me;
    	me =this_player();
	
		if (REWARD_D->riddle_check(me,"失剑风波")==1 
			|| REWARD_D->riddle_check(me,"失剑风波")==2) {
			tell_object(me,"老王道：这事你都知道了？我已经把它卖了！卖给那个该死的矮胖子了！\n");
			REWARD_D->riddle_set(me,"失剑风波",2);
		}else{
    		message_vision("$N道：你别瞎猜，没有的事！\n",this_object());		
		}
    	return 1;
}
