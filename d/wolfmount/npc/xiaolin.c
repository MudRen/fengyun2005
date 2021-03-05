#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小琳", ({ "xiao lin"}) );
        set("gender", "女性" );
        set("age", 18);
        set("long","一个很文静的女孩子，很美但也很害羞的样子。\n");
        set("nickname", MAG"痴痴迷迷"NOR);
        set("title", "圣女");
        set("attitude", "friendly");
        set("no_arrest",1);
        set("str", 10);
        set("per",50);
		
        set("combat_exp", 4000);
        set_skill("unarmed", 10);
        set_skill("force",10);
        set_skill("parry",10);
        set_skill("dodge", 200);
        set_skill("move",200);
        setup();
}

void init()
{
	::init();
	add_action("do_kill","kill");
}

int do_kill(string arg)
{	object ob;
	if ((arg=="xiao lin") && ob=present("xiao ma",environment(this_object())))
	{
		ob->kill_ob(this_player());
		ob->ccommand("say 趁人之危，猪狗不如的东西！！");
		this_object()->remove_all_killer();
		return 1;
	}
	
	else
	{
		return 0;
	}
}

int accept_object(object me, object ob)
{
	object sunwaiter;
	if(sunwaiter = present("sun legate", environment(this_object())))
	{
		if (!userp(sunwaiter))
		return notify_fail("太阳使者就在旁边，不可轻举妄动。\n");
	}
	if(ob->query("name") == HIG"还魂草"NOR 
		&& me->query("marks/杀太阳使者"))
	{
		if(me->query_temp("marks/wolf_xiaoma_good"))
		{
			environment(me)->goodresult_notify(me,this_object(),0);
		}
		else if(me->query_temp("marks/wolf_xiaoma_normal"))
		{
			environment(me)->normalresult_notify(me,this_object(),0);
		}
		return 1;
	}
	else
		return 0;      
}
