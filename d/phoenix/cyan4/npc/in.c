#include <ansi.h>
inherit SMART_NPC;
int do_ref(string arg);
int do_exp(string arg);

void try_to_run()
{
	if (is_busy())
		return;

	if (query_temp("marks/escape") + 6 > time())
		return ;


	if ("/cmds/std/go"->check_flee(this_object(),"黄树林外"))
	{
		message_vision("$N往黄树林外落荒而逃了。\n",this_object());
		destruct(this_object());
		return;
	}
	set_temp("marks/escape",time());
	ccommand("pain");
}

void create()
{
	set_name("凝轻", ({"in"}) );
	set("gender", "女性" );
	set("combat_exp", 10000000);
	set("attitude", "peaceful");
	set("age",32);

	set("n_type",2);
	set("accept_npc_fight",0);
   
	

	auto_npc_setup("in",300,220,1,"/obj/weapon/","random","random",query("n_type"));
	setup();
}

int leave()
{
	object me = this_object();
	if (!query("t"))
		set("t",time());
	if (query("t") + 10 < time())
	{
		message_vision("$N往黄树林外离开。\n",this_object());
		destruct(this_object());
		return 0;
	}
		
	return 1;	
}


int init_me(object me,int type)
{
	int exp = me->query("combat_exp");

	if (type == 6)
		exp = exp * (3+random(7))/10;

	set("combat_exp",exp);
	do_ref("smallguy");

//	ccommand("say Done. Set my exp to "HIG+ exp+NOR" ,my npc-type is "HIW+query("npc")+NOR" .\n");
//	ccommand("say kee = "+HIR+query("kee")+NOR+" ,str = "HIC+query_str()+NOR" ,resist = "HIY+exp/333333+NOR" .\n");

		set("n_type",2);
		set("nb_chat_chance", 100);
		set("nb_chat_msg_combat", ([
			35: 	(: try_to_run() :),
		]) );
		set("chat_chance",100);
		set("chat_msg", ({
			(: leave() :),
		}) );


	if (type == 1)				// Drunk Guest, 60%-80% kee
	{
		set("max_kee",query("max_kee")*(12+random(4))/10);
		set("max_gin",query("max_gin")*(12+random(4))/10);
		set("max_sen",query("max_sen")*(12+random(4))/10);

	}

	if (type == 2)				// Oldguy, long kee 120%-200%
	{

		set("max_kee",query("max_kee")*(25+random(15))/10);
		set("max_gin",query("max_gin")*(4+random(3))/10);
		set("max_sen",query("max_sen")*(4+random(3))/10);

	}

	if (type == 3)				// Monk, Can't be busied
		set("busy_immune",4);


	if (type == 4)				// Highhand. Resist gen/Sen, or Worse have damage shield, -1k 
	{
		switch (random(3))
		{
		case 0:
			set("max_mana",20000);
			set("mana",20000);
			set_temp("shield_force/type","mana");
			set_temp("shield_force/ratio",10000);
			set_temp("shield_force/msg",
				MAG"$N"MAG"招式甫及$n"MAG"身前三尺之外，便如泥牛入海，消失在紫气中。\n"NOR);

			if (random(2))
			{
			set("resistance/sen",50);
			set("resistance/gin",-100);
			}
			else
			{
			set("resistance/sen",-100);
			set("resistance/gin",50);
			}
				break;
		case 1:
			set("resistance/sen",100);
			set("resistance/gin",100);
			break;
		case 2: 
			set_temp("damage_shield/type","kee");
			set_temp("damage_shield/amount",query("str") * query("str") * query("str") /100 * query("str") / 50);
			set_temp("damage_shield/msg",HIW"$n一触$N衣衫，忽然如遭电击。\n"NOR);
			break;
		}

	}

	if (type == 5)			// Short Kee, but have 30% backfire
	{
		set("max_kee",query("max_kee")*(6+random(3))/10);
		set("max_gin",query("max_gin")*(12+random(5))/10);
		set("max_sen",query("max_sen")*(12+random(5))/10);


		set_temp("buffup/backfire","kee");
		set_temp("buffup/backfire_amount",30+random(11));
		set_temp("buffup/backfire_msg",HIW"一阵锥心刺骨的寒冷沁进了$n心中，$n不由打了一个寒颤。"NOR);

	}

	set("agi",me->query_agi()/3);
	set("max_kee",query("max_kee")/2);
	set("max_gin",query("max_gin")/2);
	set("max_sen",query("max_sen")/2);
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object()); This has full message.

//	message_vision("\n",this_object());
	
//	ccommand("say Done. Set my exp to "HIG+ exp+NOR" ,my npc-type is "HIW+query("npc")+NOR" .\n");
//	ccommand("say kee = "+HIR+query("kee")+NOR+" ,str = "HIC+query_str()+NOR" ,resist = "HIY+exp/333333+NOR" .\n");
	return 1;

	
}


int do_ref(string arg)
{
	mapping skl;
	string *sname;

	skl = query_skills();
	while (sizeof(skl) > 0)
	{
		skl = query_skills();
		sname  = sort_array( keys(skl), (: strcmp :) );
		delete_skill(sname[0]);
	}


	if (arg)
		auto_npc_setup("in",300,220,1,"/obj/weapon/","random",arg,query("n_type"));
	else
		auto_npc_setup("in",300,220,1,"/obj/weapon/","random","random",query("n_type"));
	
	do_exp(query("combat_exp")+"");


	return 1;
}





int do_exp(string arg)
{
	int exp;
	int pow_exp;

    int loop;
	mapping skl,map;
	string *sname,*mapped;

	int flag,enforce,best_force=1;

	if (!arg)
		return notify_fail("[Usage]: Exp <NPC-EXP>\n");
	exp = atoi(arg);
	set("combat_exp",exp);

	pow_exp = to_int(pow(to_float(exp*10),0.3334));


	skl = query_skills();
	if (sizeof(skl))	// 设置skills
	{
		sname  = sort_array( keys(skl), (: strcmp :) );
		map = query_skill_map();
		if( mapp(map) ) mapped = values(map);
		if( !mapped ) mapped = ({});

		for(loop=0;loop<sizeof(skl); loop++)
		{
			// Basic skill : cap @ 300 | 按系数1.6计算.
			if (SKILL_D(sname[loop])->effective_level() == 50)
//				if (skl[sname[loop]] > 300 || skl[sname[loop]] > pow_exp*100/160)
				set_skill(sname[loop],300>pow_exp*100/160?pow_exp*100/160:300);	// 

			// Advance skill : cap @ 250.
			if (SKILL_D(sname[loop])->effective_level() != 50)
//				if (skl[sname[loop]] > 250 || skl[sname[loop]] > pow_exp*100/SKILL_D(sname[loop])->effective_level())
				set_skill(sname[loop],250>pow_exp*100/SKILL_D(sname[loop])->effective_level()?pow_exp*100/SKILL_D(sname[loop])->effective_level():250);	// 

			if (SKILL_D(sname[loop])->valid_enable("force"))
				if (SKILL_D(sname[loop])->effective_level() * skl[sname[loop]] > best_force)
					best_force = skl[sname[loop]];


		}
	}

	// Reset my force and hp.
	enforce = (query_skill("force",1) / 2 + best_force) / 3;
	set("force_factor",enforce);
	set("str",query_skill("unarmed",1)/5>60?60:query_skill("unarmed",1)/5);

	set("resistance/kee",exp/333333);
	set("resistance/gin",exp/333333);
	set("resistance/sen",exp/333333);

	"/feature/nada.c"->reset_npc(this_object());
	this_object()->full_me();
	return 1;
}

void unconcious()
{
	die();
	return;
}

void die()
{
	if (query("ol"))
	{
		if (query("value") != 1)
			query("ol")->add_temp("annie_quest/cyan4",1);
		else
		{
			query("ol")->add_temp("annie_quest/cyan42",1);
			if (query("ol")->query_temp("annie_quest/cyan42") == 2)
			{
				query("ol")->add_temp("annie_quest/cyan4",1);
				query("ol")->set_temp("annie_quest/cyan42",0);
			}

		}
	}
	::die();
	return;
}

/*
fengyun-
奁镜朱颜辞流水，年华不识花自飞……
dancing_faery@hotmail.com
annie.01.01.2004
*/




