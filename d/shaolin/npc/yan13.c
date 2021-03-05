// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int ask_fight();
void create()
{
    	set_name("燕十三", ({ "yan13", "yan shisan" }) );
      	set( "title",HIC"夺命十三剑"NOR);
    	set("gender", "男性" );
    	set("reward_npc", 1);
    	set("difficulty", 40); 
    	set("age", 34);
      
    	set("attitude","friendly");
      	   
    	set("toughness",1000);
    	set("long","
他露在黑巾外的一双眼睛，锐利如刀。他的手里握着剑，漆黑的剑鞘上，
镶着十三粒晶莹的明珠。 \n");

	set("combat_exp", 90000000);
    	set("score", 200000);
    
    	set_skill("move", 200);
    	set_skill("parry", 300);
    	set_skill("dodge", 300);
    	set_skill("force", 200);
    	
    	set_skill("sword",350);
    	set_skill("13-sword",200);
    	set_skill("cloudforce",120);
    	set_skill("unarmed",200);
    	set_skill("dragonstrike",200);
    
    	map_skill("force", "cloudforce");
    	map_skill("parry","13-sword");
    	map_skill("sword","13-sword");
    	map_skill("dodge","13-sword");
    	map_skill("move","shadowsteps"); 
    	map_skill("unarmed","dragonstrike");

    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"燕十三叹息着道:“鬼为什麽还没有哭泣？ 神为什麽还没有流泪？”\n",
        	"燕十三叹息着道：“天气这麽好，风景这麽美，我们在临死之前，至少 
也该先享受一下人生。” \n",
            }) );
	set("inquiry",([
        	"fight" : (: ask_fight :),
        	"挑战" : (: ask_fight :),
    	]) );

    	setup();
    	carry_object(__DIR__"obj/blackcloth")->wear();
    	carry_object(__DIR__"obj/yan13-sword")->wield();
	carry_object(__DIR__"obj/blackmask")->wear();
}

int ask_fight()
{
	object me;
	me = this_player();
	if (!me->query("marks/少林_神剑_燕十三") || me->query("marks/少林_神剑_谢晓峰"))
	{
		return 0;
	}
	if (!present("meizhi",me))
	{
		message_vision("$N对$n冷冷地道：“没有见过我剑法的人，没有资格向我挑战。”\n",this_object(),me);
		return 1;
	}
	message_vision(" $N瞥了$n手里的梅枝，淡淡地问：“这一剑的天机，你能悟得出来？” (answer yes/no) \n",this_object(),me);
	add_action("do_answer","answer");
	me->set_temp("yan13ask",1);
	return 1;
}

int do_answer(string arg)
{
	object me,meizhi;
	int i;
	me = this_player();
	if (arg != "yes" && arg != "no")
	{
		return notify_fail("你只可答yes/no \n");
	}
	if (!me->query_temp("yan13ask"))
	{
		return 0;
	}
	me->delete_temp("yan13ask");
	if (arg == "yes")
	{
		message_vision("$N握剑的手背上，青筋已凸起。“我一生都在寻求破解这一剑的天机， 
只要这愿望能够达到，败又何妨，死又何妨？” \n",this_object());
		message_vision("$N对$n道：“你既有把握向我挑战，那就来吧。”\n",this_object(),me);
		this_object()->kill_ob(me);
		//me->kill_ob(this_object());
	}else
	{
		if(me->query("宿命A/风云_蝴蝶"))
		{
			message_vision("$N说：“一这一剑本就是剑法中的「神」，「神」是看不见，也找不到的，他要来的时候，就忽然来了。可是你本身一定先达到
「无人、无我、无忘」的境界，他才会来。这道理也正如禅宗的「顿悟」一样。”\n\n",this_object());
			if (!me->query("marks/dunwu"))
			{
				message_vision("一道阳光从竹林林缺的枝隙照进来，落在青苔地上，就像是一柄金剑。 
$N在竹林的飒飒天籁中忽然感到顿悟。\n",me);
				tell_object(me, HIC "你的「" + SKILL_D("sword")->name() + "」突飞猛进！达到了一个新的境界。\n\n"NOR);
				i= me->query_skill("sword",1)+10;
				me->set_skill("sword",i);
				me->set("marks/dunwu",1);
			}
			message_vision("$N对$n点点头说：“你去吧。” \n",this_object(),me);
		}else
		{
			message_vision("$N道：“安禅制毒龙，可现在这一剑，已变成了毒龙，已经有了它自己的神通变化。”\n",this_object());
			message_vision("$N对$n摇摇说：“你去吧。” \n",this_object(),me);
		}
			me->delete("marks/少林_神剑_燕十三");
            me->set("marks/少林_神剑_死亡之剑",1);

	}
	return 1;
}

void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
	{
		if (killer->query("marks/少林_神剑_燕十三"))
		{
			killer->delete("marks/少林_神剑_燕十三");
			killer->set("marks/少林_神剑_谢晓峰",1);
		}
	}
    ::die();
}


int return_home(object home)
{
        //if jin is in action, don't make her returning home
        if (query("marks/inaction"))
        {
                return 1;
        }
        ::return_home(home);

}
