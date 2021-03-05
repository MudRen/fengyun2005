inherit NPC;
void checking();

void create()
{
        set_name("山野毛贼", ({ "thief" }) );
        set("gender", "男性" );
        set("age", 27);
        set("str", 20);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
这个毛贼面有菜色，好像饿了三天，衣服破破烂烂，连手中的刀都是锈的。
LONG
);
        set("attitude", "friendly");
        set("combat_exp", 10000);
        set("chat_chance", 3);
        set("chat_msg", ({
			(: checking :),
        }) );

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "毛贼显然是刚刚入行，刀刀偏离目标数尺。\n",
              "毛贼高喊：抢银子啊，抢了老婆孩子就有饭吃了。\n",
        }) );

        set("force",100);
        set_skill("unarmed", 80);
        set_skill("blade", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        setup();
        carry_object(__DIR__"obj/caidao")->wield();
        carry_object(__DIR__"obj/pocloth")->wear();
}

void checking()
{
        object robber,player,leader;
        robber = this_object();
        player = this_player();
        leader = present("thief leader", environment( this_object()));
           
        if (robber->is_fighting()) 
        {
                message_vision("\n$N叫道：点子扎手，加把劲啊！\n\n",robber);
                return;
        }
        
        if ( present("thief leader",environment(this_object())))
        {
        	if (leader->is_fighting())
        	{
        		command("addoil leader");
        		return;
        	}
        	else 
        	{
        		command("sigh");
        		command("say 这是个什么世道啊，象我这样的老实人也要打劫！\n\n");
        		return;
        	}
        }
        else
        {       	               	
        	message_vision("$N惊惶失措：“头头呢？头头呢？....”\n",robber);
		command("sigh");
		message_vision("$N将菜刀插回腰间，转身跑了。\n",robber);
		destruct(robber);
		return;
	}
}