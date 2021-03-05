// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    	set_name("一尘", ({ "master yi", "master"}) );
    	set("nickname", HIM "天龙"NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "男性" );
    	set("reward_npc", 1);
		set("difficulty", 5);
    
    	set("age", 64);
    	
		set("combat_exp", 1300000);
    	set("cor",30);
    	set("attitude","friendly");
    
    	set("long","少林第十八代长老，专门传授少林金刚武功。\n"	);
    	create_family("少林寺", 18, "长老");
    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"沙弥","僧人","罗汉","金刚","上人","高僧","大师",
		"长老","法堂长老","戒律院长老","法堂首座","戒律院首座",
		YEL"长老院首座"NOR,YEL"副主持"NOR,YEL"禅宗传人"NOR,HIY"禅宗宗主"NOR}));
		
    	set("class","shaolin");
    	
	set_skill("move", 140);
	set_skill("dodge", 140);
	set_skill("unarmed",140);
	set_skill("puti-steps",140);
	set_skill("dabei-strike",140);
	set_skill("zen",130);
	set_skill("chanting",140);
	set_skill("xiaochengforce",140);
	set_skill("parry",140);
	set_skill("foreknowledge",100);
	set_skill("perception",100);
	
	set_skill("force", 160);
	set_skill("literate", 100);
	
	set_skill("axe",150);
	set_skill("wuche-axe",150);
	set_skill("staff",150);
	set_skill("fumostaff",150);
	set_skill("blade",150);
    set_skill("lianxin-blade",150);
	set_skill("liuxing-hammer",150);
    set_skill("hammer",150);
	set_skill("duanhun-spear",150);
	set_skill("spear", 150);
	
	map_skill("axe","wuche-axe");
	map_skill("spear","duanhun-spear");	
	map_skill("staff","fumostaff");
	map_skill("parry","fumostaff");
	map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
	
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
	    	(: perform_action, "unarmed.qianshouqianbian" :)
	}) );
	setup();
	carry_object(__DIR__"obj/bigdan.c");
	carry_object(__DIR__"obj/monk20_cloth")->wear();

}

void attempt_apprentice(object me)
{
	if( me->query("class") == "shaolin" && me->query_temp("won_master_di")){
		command("smile");
        	command("recruit " + me->query("id") );
        	return;
    	} else {
		command("shake");
    	}
}



int accept_fight(object me)
{
        if( is_fighting() )
		command("say 想倚多为胜？去找寺内的棍僧较量吧！\n");
		
        if(me->query("family/family_name") == query("family/family_name") &&
	   	me->query("family/master_id") == query("id"))
        {
        	if( query("gin") * 100 / query("max_gin") >= 90
			&& query("kee") * 100 / query("max_kee") >= 90
			&& query("sen") * 100 / query("max_sen") >= 90 )
		{
        	       	if (me->query_skill("zen",1) >= 125) {
        			message_vision("$N将剩下的"HIR"大还丹"NOR"吃得乾乾净净。\n"
                       				HIR "$N深深吸了一口气，运功将药力化开。\n"NOR,
                       				this_object());
        			me->set_temp("marks/fi_m_18",1);
        			command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
        			return 1;
        		}
        		command("say 徒儿，你的禅道修为太浅，光练武可不行啊！\n");	
        		tell_object(me,"（需125级禅道）\n");	// 1.2M
        			
        	} else
        		command("say 好，不过，让老衲喘口气再来。\n");
        }	
        else
        {
        	command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
    	if (loser->query_temp("marks/fi_m_18")) {
        	command("say 阿弥陀佛！徒儿还要努力呀！\n");
			loser->delete_temp("marks/fi_m_18");
		}
    	else 	
    		command("say 阿弥陀佛！\n");
}

void lose_enemy(object winner)
{
    	if(winner->query_temp("marks/fi_m_18")) {
    		command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    		winner->set_temp("won_master_yi",1);
    		winner->delete_temp("marks/fi_m_18");
    	}
    	else 
    		command("say 阿弥陀佛！\n");
        
}

void check_answer(object me)
{

	if (objectp(me))
	{
		me->delete_temp("inask");
		if (present(me,environment(this_object())))
		{
			message_vision("$N手磨挲着梅枝，对$n叹道“看来你还未又所悟”\n",this_object(),me);
		}
	}
}

int accept_object(object who, object ob)
{
	if (ob->name() == "削断的梅枝"){
		if(who->query("marks/少林_面壁成功")) {
			message_vision("$N轻轻接过梅枝，仔细观看了一会儿。又抬头看了看$n道：“得失从缘，\n", 
					this_object(), who);
			message_vision("心无增减．．．．你即已领悟心当无挂。我佛慈悲！\n", this_object());
			return 1;
		}
		if (who->query("marks/少林_神剑_梅枝") && !who->query("marks/少林_神剑_谢晓峰")&& who->query("class")=="shaolin"){
			message_vision("$N轻轻接过梅枝，仔细观看了一会儿。\n",this_object());
            		message_vision("$N手捏剑诀，沿着梅枝断口的剑势比了一招剑法。 \n\n",this_object());
			message_vision("$n只觉得这一招剑法看来平平淡淡，然而剑势与天合一， 
风吹梅枝，在$N手中跳动不停，又彷佛是那一剑神奇的震动。 \n\n",this_object(),who);
			message_vision("$N手持梅枝，面现微笑，问$n道：“你可有所悟？”(answer yes/no) \n",this_object(),who);
			add_action("do_answer","answer");
			who->set_temp("inask",1);
			call_out("check_answer",120,who);
		} else {
			message_vision("看着梅枝的断口剑痕，$N幔慢的抬起头，显得说不出疲倦和悲伤。 
“我佛慈悲！”$N叹道：“这一剑所带来的只有毁灭和死亡！”\n ",this_object());
		}
		return 1;
	}
	return 0;
}

int do_answer(string arg)
{
	object me;
	me = this_player();
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("你只可答yes/no \n");
	}
	if (!me->query_temp("inask"))
	{
		return 0;
	}
	remove_call_out("check_answer");
	me->delete_temp("inask");
	if (arg == "yes")
	{
		message_vision("$n说：“此剑精妙绝伦，弟子今日大开眼界。” 
$N摇摇头：“老衲穷一生之学，对这一剑的了解也仅止于此了。” ",this_object(),me);

	}else
	{
		message_vision("$n说：“此剑暗合天数，弟子愚钝，尚未能有所悟。” \n $N双掌合十，颂道：“阿弥陀佛！”\n\n ",this_object(),me);
		message_vision("$N对$n说道：“当年燕十三来闯达摩堂，用的就是此招。此剑一出，伤了 
你太师叔，前达摩堂住持无根禅师。然而合寺武僧至今无人能悟破此剑， 
报仇也就无从谈起。”\n\n",this_object(),me);
		message_vision("$N顿了一敦，又对$n说道：“你剑术修为已经不逊你师，又知此剑之有不可悟，你可愿
担此重任挑战燕十三？” (accept yes/no)\n",this_object(),me );
		add_action("do_accept","accept");
		me->set_temp("inaccept",1);
		call_out("check_accept",120,me);
	}
	return 1;
}

void check_accept(object me)
{
	if (objectp(me))
	{
		me->delete_temp("inaccept");
		if (present(me,environment(this_object())))
		{
			message_vision("$N对$n叹道：“看来你是不愿，老纳也不便勉强。你去吧！”\n",this_object(),me);
			me->delete("marks/少林_神剑_梅枝");
		}
	}
}

int do_accept(string arg)
{
	object me,meizhi;
	me = this_player();
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("你只可答yes/no \n");
	}
	if (!me->query_temp("inaccept"))
	{
		return 0;
	}
	remove_call_out("check_accept");
	me->delete_temp("inaccept");
	if (arg == "yes")
	{
		message_vision("$N把梅枝还给$n，叮嘱道：“据传燕十三已去神剑山庄挑战谢晓峰，你 
可以去那里找他。这一剑的精意你还要加紧参悟。”\n",this_object(),me );
		meizhi = new("d/shaolin/obj/meizhi");
		meizhi->move(me);
        me->delete("marks/少林_神剑_梅枝");
        me->set("marks/少林_神剑_燕十三",1);
	}else
	{
		message_vision("$N摇摇头，不再说话。 \n",this_object());
		me->delete("marks/少林_神剑_梅枝");
	}
	return 1;
}


void init()
{	
	::init();
	add_action("do_killing", "kill");

}
