// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int got_me();
int leave();
void create()
{
    	set_name("空慎", ({ "master kong", "master"}) );
    	set("nickname", HIG "无为" NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "男性" );
    	set("reward_npc", 1);
		set("difficulty", 1);
    	set("class","shaolin");
    	set("combat_exp", 100000);
    	set("age", 64);
    	set("per", 35);
    	    
    	set("attitude","friendly");
    	set("long","少林第二十三代的师傅，他专门传授少林俗家弟子武功。\n");
    	set("inquiry", ([
        	"出家前" : (: got_me :),
        	"chujiaqian" :  (: got_me :),
        	"leave" : (: leave :),
    		       
        ]) );
    	create_family("少林寺", 23, "长老");
    	    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"沙弥","僧人","罗汉","金刚","上人","高僧","大师",
		"长老","法堂长老","戒律院长老","法堂首座","戒律院首座",
		YEL"长老院首座"NOR,YEL"副主持"NOR,YEL"禅宗传人"NOR,HIY"禅宗宗主"NOR}));
		
        
    	set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.qianshouqianbian" :)
            }) );
    	
    
    	set_skill("move", 80);
    	set_skill("dodge", 80);
    	set_skill("force", 80);
    	set_skill("literate", 100);
    	set_skill("unarmed",80);
    	set_skill("parry",80);
    	set_skill("puti-steps",80);
    	set_skill("dabei-strike",80);
    	set_skill("zen",60);
    	set_skill("chanting",80);
    	set_skill("xiaochengforce",80);
		set_skill("foreknowledge",80);
		set_skill("perception",80);
    	set_skill("blade", 120);
    	set_skill("lianxin-blade",120);
    	
    	map_skill("blade","lianxin-blade");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "dabei-strike");
    	setup();
    	carry_object(__DIR__"obj/monk22_cloth")->wear();
}


void attempt_apprentice(object me)
{
    	if(me->query("gender") != "男性")
    	{
			command("say 善哉，善哉，这位女施主请回吧，本寺只收男弟子。\n");
			return;
		}
		else if(me->query("marry") && !me->query("jiebai"))
		{
			command("say 这位施主六根未净，还是请回吧。\n");
			return;
		}	
		else if( me->query_skill("dabei-strike",1)>=15 && 
        		me->query_skill("xiaochengforce",1)>=10 &&
        		me->query_skill("puti-steps",1)>=15 )
    	{
			command("smile");
       		command("recruit " + me->query("id") );
       		return;
    	}
    	else 
    	{
			command("smile");
    	    command("say 拜师要有诚意，你先去学学碑文吧！\n");
        	tell_object(me,"（需１５级大慈大悲手、１０级小乘心经、１５级菩提步法）\n");
        	return;
		}
}

int accept_fight(object me)
{

	if( is_fighting() )
		command("say 想倚多为胜？去找寺内的棍僧较量吧！\n");
		if(me->query("class") == "shaolin")
        {
        	if( query("gin") * 100 / query("max_gin") >= 90
			&& query("kee") * 100 / query("max_kee") >= 90
			&& query("sen") * 100 / query("max_sen") >= 90 )
		{
			command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
			me->set_temp("marks/fi_m_23",1);
        	return 1;
			
		}
		else
		       	command("say 好，不过，让老衲喘口气再来。\n");
			
        }
        else
        {
        	command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        	
        }
        return 0;
}

void win_enemy(object loser)
{
	if (loser->query_temp("marks/fi_m_23")) {
		command("say 阿弥陀佛！徒儿还要努力呀！\n");
		loser->delete_temp("marks/fi_m_23");
	}
}


void lose_enemy(object winner)
{
	if (winner->query_temp("marks/fi_m_23")) {
		command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
		winner->set_temp("won_master_kong",1);
		winner->delete_temp("marks/fi_m_23");
	}
}

int got_me()
{
	command("sigh");
	command("say 出家前的事不提也罢！\n");
	return 1;
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="shaolin") return 0;
	message_vision(CYN"$N合掌道：既是无缘，何必再留，以后也不要再回来了。\n"NOR, this_object(),this_player());
	return 1;
}
