
inherit NPC;
#include <ansi.h>


void create()
{
        set_name("孤松先生", ({ "gu song","song" }) );
        set("title", HIG "岁寒三友"NOR);
        set("long",     "
穿着墨绿绣花长袍，头戴白玉黄金高冠的老人，西方神教的三大护法之一。\n");
        set("gender", "男性" );
        set("age", 66);
        set("str", 6);
		set("per", 27);
             
        set("reward_npc", 1);
        set("difficulty", 2);
		set("fly_target",1);
		set("intellgent",1);
        set("attitude", "peaceful");
	        
        set("chat_chance", 3);
        set("chat_msg", ({
//                (: random_move :),
				"孤松先生冷笑道：巴山图丢失已久，没有巴山图的指引，想来那些名门正道
也找不到我小巴山总坛。\n",
        }) );
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.dimo" :),
		(: perform_action, "unarmed.renmo" :),
		(: perform_action, "unarmed.tianmo" :),
		(: exert_function, "mihun" :),
        }) );

        
        set("combat_exp", 999999);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
		set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("demon-force", 100);
        set_skill("demon-strike", 80);
        set_skill("demon-steps", 100);
		set_skill("parry",100);
	
		set_skill("meihua-biao",100);
		map_skill("parry","meihua-biao");
		map_skill("throwing", "meihua-biao");
	    map_skill("unarmed", "demon-strike");
        map_skill("dodge", "demon-steps");
		map_skill("force","demon-force");

        setup();

        carry_object(__DIR__"obj/stone")->wield();
        carry_object(__DIR__"obj/highhat")->wear();
        carry_object(__DIR__"obj/greenrobe")->wear();
}

void init()
{
        object me;
        me = this_player();
        
        ::init();
        if( REWARD_D->riddle_check( me, "计取罗刹"))
        {
        	remove_call_out("chase_him");
        	call_out("chase_him", 1,me );
		}

}

void chase_him(object me)
{
		if (!me || environment(me) != environment()) return;
			
        message_vision("$N向$n喝道：竟敢偷盗本教的罗刹牌！拿来！\n",this_object(),me);
        kill_ob(me);
        me->kill_ob(this_object());
		return;
}

int accept_object(object who, object obj)
{
	if( (string) obj->query("name") == "罗刹牌")
	{
    	if (REWARD_D->riddle_check(who,"计取罗刹") !=5)
    	{
    		command("say 原来是你偷的罗刹牌，拿命来吧！");
    		kill_ob(who);
    		who->kill_ob(this_object());
    		return 0;
    	}
    	
    	if (obj->query("fake"))
    	{
    		command("say 大胆，竟敢拿假货来骗老夫！");
    		kill_ob(who);
    		who->kill_ob(this_object());
    		return 0;
    	}
    		
    	message_vision("$N对$n哼了声：咱们的前嫌旧怨，一＂璧＂勾销！\n",this_object(),who);
		who->remove_all_killer();
    	REWARD_D->riddle_done(who, "计取罗刹", 20,1);
		return 1;		
	}
		
	return 0;
}
