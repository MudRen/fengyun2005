// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
string quest();

#include <ansi.h>
void create()
{
    	set_name("上官金虹", ({ "master shangguan", "master", "shangguan" }) );
    	set("nickname", RED"龙凤双环"NOR);
    	set("gender", "男性" );
    	set("class", "assassin");
    
    	set("long","
一个人正站在桌子前翻阅着，不时用朱笔在卷宗上勾划，批改，嘴里偶而会露出
一丝得意的笑容。他是站着的。他认为一个人只要坐下来，就会令自己的精神松
弛，一个人的精神若松弛，就容易造成错误。\n");
    	create_family("金钱帮", 1, "帮主");
       	set("rank_nogen",0); 
	set("guard_msg",HIW"$N喝道：在我面前杀我金钱帮的弟子，不想活了！\n"NOR);
    	set("combat_exp", 25000000);
    	set("score", 200+random(200000));
    
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "hammer.longfengshuangfei" :),
        }) );
    	set("age", 44);
    	set("per", 30);
    	
    	 set("inquiry", ([
	       	"招募": 	(: quest :),
	       	"工作": 	(: quest :),
	       	"zhaoren": (: quest :),
	       	"job": (: quest :),
         ]) );
    	
    	set("reward_npc", 1);
    	set("difficulty", 40);
    	set("attitude","friendly");

	set_temp("apply/haste",300);
	    	
    	set_skill("move", 200);
    	set_skill("parry", 240);
    	set_skill("dodge", 240);
    	set_skill("force", 200);
    	set_skill("jingxing",150);
    	set_skill("hammer", 300);
    	set_skill("flame-strike",200);
    	set_skill("unarmed",230);
    	set_skill("jinhong-steps",200);
    	set_skill("longfenghuan",200);
    	    	
    	map_skill("dodge", "jinhong-steps");
    	map_skill("hammer", "longfenghuan");
    	map_skill("parry", "longfenghuan");
    	map_skill("force", "jingxing");
    	map_skill("unarmed", "flame-strike");
    	map_skill("move","jinhong-steps");

	set_temp("apply/attack",100);
	
	setup();
	carry_object(__DIR__"obj/yellow_suit")->wear();
    	carry_object(__DIR__"obj/hat")->wear();
    	carry_object(__DIR__"obj/longfenghuan")->wield();
}


void attempt_apprentice(object me)
{      
	if(me->query_temp("won_master_jing",1)){
	command("recruit " + me->query("id") );
	//message_vision(CYN"$N淡淡地说：本座不想收徒，你从哪里来，便回哪里去。\n"NOR, this_object(), me);
	return;
}
message_vision(CYN"$N淡淡地说：本座不想收徒，你从哪里来，便回哪里去。\n"NOR, this_object(), me);
}


void smart_fight(){
	if (this_object()->query("kee") < this_object()->query("max_kee")/2) {
		this_object()->ccommand("exert riposte");
		this_object()->ccommand("haha");
	}
			
	if (this_object()->query_temp("weapon"))
	if (random(2))
		this_object()->ccommand("perform longfengshuangfei");
}
		
string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object me = this_player();
	
	if (me->query("quest/short") == "去上官金虹打听招募的事儿")
	{
		if (me->query("quest/duration") == 441)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","杀铁罗汉");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到少林罗汉堂杀XXX"+WHT"个铁罗汉"NOR);
				me->set("annie_quest/target","铁罗汉");
				
				me->set("quest/short", WHT"到少林罗汉堂杀"+ n + WHT"个铁罗汉"NOR);
				me->set("quest/location", "少林罗汉堂");
				me->set("quest/difficulty",n*30);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*60);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "少林不除，终成大患，你且去少林后门罗汉堂杀几个铁罗汉。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		
		if (me->query("quest/duration") == 442)	// 除小兽
		{
				n=1+random(3);
				me->set("annie_quest/name","杀铜罗汉");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到少林罗汉堂杀XXX"+WHT"个铜罗汉"NOR);
				me->set("annie_quest/target","铜罗汉");
				
				me->set("quest/short", WHT"到少林罗汉堂杀"+ n + WHT"个铜罗汉"NOR);
				me->set("quest/location", "少林罗汉堂");
				me->set("quest/difficulty",n*30);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*60);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg= "少林不除，终成大患，你且去少林后门罗汉堂杀几个铜罗汉。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}
		
		return "最近好象没什么事情，你不如趁机找巫师泡泡茶吧。\n";	// error mark.
	}
	else
		return "action上官金虹一语不发。";
	
	return " ";
}
