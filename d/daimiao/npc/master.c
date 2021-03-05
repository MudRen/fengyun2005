inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    	set_name("羽天白", ({ "master yu", "master"}) );
    	set("nickname", HIR "万胜刀魔"NOR);
    	set("gender", "男性" );
    	set("age", 64);
    	set("per", 3);
    	set("reward_npc", 1);
	set("difficulty", 25);
	set("group", "demon");
        set("vendetta_mark","demon");
    	set("attitude","friendly");
    
    	set("combat_exp", 12000000);
    	set("score", 200000);
    	set("max_force", 5000);
    	set("force", 5000);
      	
    	set("long","
神刀堂曾经是江湖中势力最大的门派，在一个大雪纷飞的晚上，神刀堂的堂主
白天羽和手下三十余名高手神秘地死在梅花庵外。许多年过去了，江湖中忽然
多了一个神秘的西方神教，羽天白是西方神教中的教主，他的来历谁也不清楚，
也没人敢问。凡是问过或知道羽天白来历的人都不明不白的消失了。只是传说，
他的一手刀法隐约有当年神刀的神韵。\n");
    
    	create_family("西方神教", 1, "教主");
    	set("rank_nogen",1);
    	set("ranks",({"教徒","副堂主","堂主","副坛主","坛主",
                      "副舵主","舵主","护法","大护法",
                      "长老","大长老","副帮主"}));
    	set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,15000000 }));

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(90) :),
        }) );
        
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","demon-blade",2);
    	
    	setup();
    	carry_object(__DIR__"obj/wufu")->wear();
    	carry_object(__DIR__"obj/lou")->wield();

}

void attempt_apprentice(object me)
{
    	command("say 老夫的徒弟在三十年前都已背弃老夫，你不必再痴心妄想了。");
    	return;
}


int accept_object(object me, object obj)
{
    	if(obj->query("for_bandit"))
    	{
		command("? "+me->query("id"));
        	command("say 你．．你杀了本教的人，偷了本教的东西，还敢来愚弄老夫！\n");
		this_object()->kill_ob(me);
		me->kill_ob(this_object());
		return 1;
    	}
    	if(obj->query("for_bandit2"))
    	{
		command("smile");
		command("say 好，很好，若是再早三十年，老夫就收你为徒了。\n");
		return 1;	
    	}
    	return 0;
}
