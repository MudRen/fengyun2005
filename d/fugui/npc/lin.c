#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("林太平", ({ "lin taiping","lin" }) );
        set("long",
"林太平是个很秀气、很纤弱，而且非常漂亮的人。若说燕七长的有点
像女孩子，那么他简直就象是个女孩子化装的。他的嘴很小，就算用
“樱桃小嘴”来形容他也决不过分。\n");
        set("attitude", "friendly");
        create_family("富贵山庄",7,"副庄主");
//      set("vendetta_mark", "fugui");
        set("class","baiyun");
                		
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "move.tianwaifeixian" :),
        }) );

        set("combat_exp", 4000000);
        
        set_skill("unarmed", 100);
        set_skill("force",100);
        set_skill("parry",180);
        set_skill("dodge", 200);
        set_skill("move",200);
        set_skill("sword",100);
        set_skill("feixian-sword",140);
        set_skill("feixian-steps",140);
        set_skill("chessism",100);
        set_skill("literate",100);
        
        map_skill("parry","feixian-sword");
        map_skill("sword","feixian-sword");
        map_skill("dodge","feixian-steps");
        map_skill("move","feixian-steps");
        map_skill("force","chessism");

		set_temp("apply/damage",130);
        setup();
		this_object()->disable_player(" <昏迷不醒>");
		this_object()->set_temp("is_unconcious",1);
		set_temp("block_msg/all", 1);
		carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
		COMBAT_D->announce(this_object(), "unconcious");

}

void init()
{
		::init();
		add_action("do_kill","kill");
}

void heart_beat()
{
		if(query_temp("is_unconcious"))
		{
			this_object()->unconcious();
			return;
		}
		else return ::heart_beat();
}

int do_kill(string arg)
{	object ob;
	if ((arg=="lin"||arg=="lin taiping") && ob=present("yan qi",environment(this_object())))
	{
		ob->kill_ob(this_player());
		ob->ccommand("say 要杀我林兄弟，就得先杀了我！！");
		this_object()->remove_all_killer();
		return 1;
	}
	else if((arg=="lin"||arg=="lin taiping") && !(ob=present("yan qi",environment(this_object()))))
	{
		this_object()->set_temp("is_unconcious",0);
		this_object()->revive();
		call_out("heart_beat", 0, this_object());
		this_object()->ccommand("say 趁人之危，不知羞耻！！\n");		
		return 0;
	}
}