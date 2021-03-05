// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    	set_name("无花", ({ "master wu", "master"}) );
    	set("nickname", HIM "妙僧"NOR);
    	set("gender", "男性" );
    	set("age", 29);
    	set("per", 55);
    	set("int",30);
    	set("attitude","friendly");
    
    	
    	set("long", " 素衣白袜，一尘不染，就连面上的微笑也有出尘之意。\n");
    	create_family("少林寺", 16, "大师");
    	set("class", "shaolin");
    	    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	name()+"正在一心一意地为大师煮茶。。。\n",
            	name()+"道：你终于来了，当年我就说过，唯一能破坏这个计划的就是你。\n"
            }) );
            
    	set("combat_exp", 5000000);
    	set("reward_npc", 1);
    	set("difficulty", 10);   
    	
    	set_skill("move", 200);
    	set_skill("dodge", 200);
    	set_skill("force", 200);
    	set_skill("literate", 200);
    	set_skill("unarmed",200);
    	set_skill("puti-steps",200);
    	set_skill("yiyangzhi",200);
    	set_skill("buddhism",250);
    	set_skill("chanting",200);
    	set_skill("xiaochengforce",200);
    	set_skill("staff",200);
    	set_skill("parry",200);
    
    	map_skill("parry","yiyangzhi");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "yiyangzhi");
    	map_skill("move", "puti-steps");
    	
    	
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	  (: perform_action, "unarmed.qiankun" :)
        }) );
    	setup();
    	carry_object(__DIR__"obj/monk_cloth")->wear();
}

void attempt_apprentice(object me)
{
    	command("shake");
    	command("say 我常年云游在外，你还是去找方丈吧。\n");
}


void init()
{
		if (interactive(this_player()))
			call_out("confess",1,this_player());
		::init();
}

int confess(object me)
{
		if (!me || environment(me)!= environment())	return 1;
		
		if (REWARD_D->riddle_check(me,"多事之秋") != 9 || 
			! REWARD_D->check_m_success(me, "浪人的悲哀"))
		{
			return 0;
		}
		REWARD_D->riddle_set(me,"多事之秋",10);
    	ccommand("say 看来你什么都知道了。。。\n");
    	ccommand("say 这世上有你没我！！\n");
		kill_ob(me);
		return 1;
}

void die()
{
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
			if(owner=killer->query("possessed"))
				killer = owner;
			me = killer;

		if (REWARD_D->riddle_check(me,"多事之秋") == 10)
		{
			REWARD_D->riddle_set(me,"多事之秋",11);
	    	ccommand("emote 脸色惊惧，叫道：且慢！");
	    	ccommand("say 我杀师傅是因为．．．\n");
			message_vision(HIC"\n\n一把长剑突然穿过幕帘直穿而入，不偏不倚地穿过$N心口。\n"NOR,this_object());
			message_vision(HIW"$N猛低下头，不敢相信地看着胸前剑柄，喃喃道：拜．．．拜．．．\n\n"NOR,this_object());
			tell_object(me,YEL"无花死了，他临死前的声音却在你耳边徘徊不散．．．\n");
//			REWARD_D->riddle_done(me,"武林风波",10,1);
		}
		}		
		::die();
}



int accept_object(object who, object ob)
{
	string msg;
	
	if(ob->query("name")!="乌鞘长刀") return 0;
	if (REWARD_D->riddle_check( who, "浪人的悲哀") == 2)
//	if (who->query("天枫_quest2")=="成功")
	{
		msg=HIG"无花嘿嘿冷笑道：“那老鬼和那家伙都该死，谁阻了我和我母亲的霸业，
都得死。你也得死。”\n"NOR;
		REWARD_D->riddle_set( who,"浪人的悲哀",3);	
//		who->set("天枫_quest3","成功");
	}
	else
		msg=HIM"无花眉梢扬了扬，冷笑一声：“就让你和那老鬼一同上黄泉吧。”\n"NOR;
	message_vision(msg,who);
	kill_ob(who);
	return 0;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/



