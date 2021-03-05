// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
int give_silk();
inherit NPC;

void smart_fight();

void create()
{
        set_name("老实和尚", ({ "lao shi", "lao"}) );
        set("gender", "男性" );
        set("age", 32);
        set("class", "bonze");
        set("long", "
老实和尚整天疯疯癫癫，怪里怪气的．他的功夫也是如此．
老实和尚从来不说谎话，所以得名＂老实和尚＂\n");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        
    	set_skill("unarmed", 120);
    	set_skill("dabei-strike",120);
    	set_skill("force", 120);
    	set_skill("dodge", 120);
    	set_skill("literate", 100);
    	set_skill("chanting", 120);
    	set_skill("parry", 120);
    	set_skill("lotusforce", 120);
    	set_skill("buddhism", 100);
    	set_skill("nodust-steps",120);
    	set_skill("staff",120);
    	set_skill("cloudstaff",120);
    	set_skill("perception", 100);
    	set_skill("foreknowledge", 100);
		set_skill("move", 100);
		set_skill("magic", 100);
		set_skill("essencemagic", 100);
				
		map_skill("force", "lotusforce");
    	map_skill("dodge","nodust-steps");
    	map_skill("unarmed","dabei-strike");
    	map_skill("staff","cloudstaff");
    	map_skill("parry","cloudstaff");
    	map_skill("magic","essencemagic");
    	
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
				(: smart_fight() :),
      	}) );
              
        set("chat_chance", 1);
        set("chat_msg", ({
			"老实和尚叹道：请佛祖罚我，我又去逛了千金楼！\n",
			"老实和尚捶了捶自己的头，＂出家人决不打诳语！\n",
			"老实和尚骂道：这个该死的四条眉，把这烫手的差事又给了我！\n",
			(: random_move :),
        }) );
        
        set("inquiry", ([
                "七彩丝缎带" : (: give_silk:),
                "silk" : (: give_silk:)
        ]));
	
		setup();
		carry_object(__DIR__"obj/monk_cloth")->wear();
}

void	smart_fight(){
		
		command("conjure mind_sense");
		return;
}

int give_silk()
{
	if( (int)query("given") >= 7 )
	{
		command("say 你晚了，都给光了．．．\n");
		return 1;
	}
	command("say 你也想在月圆之夜，去看那紫禁之巅的旷世决战吗？\n");
	command("say 那我得考考你，看你够不够格．\n");
	if (this_player()->query_temp("marks/laoshi_win")) 
		this_player()->delete_temp("marks/laoshi_win");
	this_player()->set_temp("marks/laoshi",1);
	return 1;
}

void win_enemy(object loser)
{
	command("say 这位" + RANK_D->query_respect(loser)+ "，你还不够格！\n");
}

void lose_enemy( object winner)
{
	object silk;
	command("say 这位" + RANK_D->query_respect(winner)+ "，你的功夫不错！\n");
	if (!winner->query_temp("marks/laoshi_win"))
	{
		silk = new(__DIR__"obj/silk");
		if (!silk->move(winner))
			silk->move(environment());
      	add("given",1);
		winner->set_temp("marks/laoshi_win",1);
		REWARD_D->riddle_done(winner,"七彩缎带",10,1);
	}
}


int accept_fight(object me)
{
	if(me->query_temp("marks/laoshi"))
	{
		command("say 好，你赢了我，这丝带就是你的．\n");
		full_me();
		me->delete_temp("marks/laoshi");
        return 1;
	}
	else
	{
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
	}
}


void reset()
{
	delete("given");
}
