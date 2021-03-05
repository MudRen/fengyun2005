// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int init_quest();

int leave();
void create()
{
    	set_name("南宫灵", ({ "master nangong", "master"}) );
    	set("nickname", HIR "神掌"NOR);
    	set("gender", "男性" );
    	set("class","beggar");
    
    	set("reward_npc", 1);
    	set("difficulty", 5);
    
    	set("age", 34);
    	set("per", 35);
    	set("attitude","friendly");
    
    	set("long", "现任天下第一大帮的帮主，前老帮主任慈的爱徒。\n");
    	create_family("丐帮", 7, "龙头帮主");
    	set("rank_nogen",1);
    	
		set("ranks",({"堂外弟子","一袋弟子","两袋弟子","三袋弟子","四袋弟子","五袋弟子","六袋弟子",
			"七袋弟子","八袋弟子","九袋弟子","传功长老","传法长老",WHT"净衣堂首座"NOR,
			WHT"污衣堂首座"NOR,WHT"副帮主"NOR,HIW"龙头大哥"NOR}));
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.xianglongwuhui" :),
             }) );

    	set("combat_exp", 2000000);
    	
    	set("chat_chance",2);
    	set("chat_msg", ({
			"南宫灵手中拿着只绿色的信鸽，若有所思。\n"
        }) );
            
    	set_skill("perception", 100);
    	set_skill("move", 150);
    	set_skill("parry",150);
    	set_skill("dodge", 150);
    	set_skill("force", 160);
    	set_skill("literate", 100);
    	set_skill("unarmed",160);
    	set_skill("doggiesteps",150);
    	set_skill("dragonstrike",160);
    	set_skill("huntunforce",140);
    	set_skill("staff",200);
    	set_skill("dagou-stick",150);
    	set_skill("begging",150);
    	set_skill("foreknowledge",150);
    	set_skill("chanting",100);
    	
    	map_skill("dodge", "doggiesteps");
    	map_skill("force", "huntunforce");
    	map_skill("unarmed", "dragonstrike");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dagou-stick");
    	
    	
	    set("inquiry", ([
	        "信鸽":			(: init_quest :),
	        "绿色的信鸽":	(: init_quest :),
	        "谋杀" : "action南宫灵惊讶地啊了一声说：有证据么？\n",
	         "leave" : (: leave :),
	        ]));
    	setup();
    	carry_object(__DIR__"obj/9bagcloth")->wear();

}

int	init_quest(){
	object me = this_player();
	
	if (REWARD_D->check_m_success(me,"魂断鹊桥"))
	{
		command("say 好小子，干得不错啊！");
		command("grin");
		if (me->query("class")=="beggar")
			command("say 你既然办成此事，就算是我的亲传弟子了，这帮里也任你走动。");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥"))
	{
		command("say 我交给你的事办得如何了？");
		command("heng");
		return 1;
	}
	
	if (me->query_skill("begging",1) < 150)
	{
		command("sigh");
		command("say 你的功夫还不到家，此行只是白白送死？");
		tell_object(me, WHT"此任务需要150级乞讨之术。\n"NOR);
		return 1;
	}	
	
	command("hmm");
	command("say 沉香镇分舵"YEL"飞鸽传信"CYN"，要我这儿派人去协助，我看你在我门下也不短了，
就代表总舵走一次，办得好，重重有赏！");
	REWARD_D->riddle_set(me,"魂断鹊桥", 1);
	return 1;
}
	

void attempt_apprentice(object me)
{
    if((int)me->query("deposit")<=0)
    {
	command("say 看在你一贫如洗的份上，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
        return;
    }
    else
    {
	command("sigh");
        command("say 看来真的是树大招风，你有钱有势的，为什么要加入我丐帮？");

    }
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "beggar");
}

int accept_object(object who, object ob)
{
	if(ob->query("name")!="乌鞘长刀") return 0;
	if (REWARD_D->riddle_check( who, "浪人的悲哀") == 2)
	{
        message_vision(HIC"南宫灵大笑着对$N道：把这刀捎我大哥！！\n"NOR,who);
		return 0;
	}
	if (!REWARD_D->riddle_check( who, "浪人的悲哀")) 
	{
		message_vision(HIR"南宫灵脸色一变，说道：“小子，只好怪你知道得太多了。。。”\n"NOR,who);
		kill_ob(who);
		return 0;
	}
    message_vision(WHT "南宫灵一把抹干眼泪，连声道：好好好，待我干完这杯，就和大哥
一起去把他老人家接回来。\n"NOR,who);
	message_vision(WHT"\n南宫灵将乌鞘长刀还给$N。\n"NOR,who);
    tell_object(who,"南宫灵轻声说道：劳烦帮我通知大哥无花，他现在少林出家为僧。\n");
	tell_room( environment(), "南宫灵在"+who->name()
		+ "耳边小声地说了些话。\n", ({ who, this_object() }) );
	REWARD_D->riddle_set( who, "浪人的悲哀",2);		
	return 0;
}


int leave() {
	if (this_player()->query("class")!="beggar") return 0;
	message_vision(CYN"$N叹了口气道，“你到底是贪图富贵呀。“\n"NOR, this_object());
	message_vision(CYN"$N说：打狗棒法和混饨心诀是祖师爷留下来的，你走了就学不会了。\n"NOR,this_object());
	return 1;
}