// 护镖 disabled for now due to bugs -- Silencer

#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;

int test_dart();

void create()
{
        set_name("财叔", ({ "cai shu","cai","caishu" }) );
        set("gender", "男性" );
        set("age", 52);
        set("richness",5000000);

        set("no_arrest",1);
        set("long",
		"一个乐呵呵地坐在柜台后眯着眼睛数着银子的小老头。\n");
        set("combat_exp", 600000);
        set("attitude", "friendly");

        set("chat_chance", 2);
		set("chat_msg", ({
       		"财叔嘟囔着：郭大路这混帐，欠了格老子几十吊钱，就不知躲到哪去鬼混了。\n",
//       		"财叔说道：金大帅要找人护镖，应该推荐谁去做这次任务（ｍｉｓｓｉｏｎ）呢？？\n",
        }) );
        set_skill("unarmed", 100);
        set_skill("dodge", 130);
		set_skill("force", 100);
		set_skill("yue-strike",40);
		set_skill("hammer",100);
		set_skill("liuxing-hammer",10);
		
		map_skill("hammer","liuxing-hammer");
		map_skill("unarmed","yue-strike");
        
/*      set("inquiry", ([
        	"mission" : (: test_dart :),
			"任务" : (: test_dart :),
        ]) );*/

        setup();

		set("mutant_rate",20);	// 20% chance
		set("mutant_name",1);	// Change Name?
		mutant();

		carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/goldabacus")->wield();
}

void init()
{
        ::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
		add_action("do_loan","loan");
//		add_action("do_accept", "accept");
}

void reset(){
	set("richness",5000000);
}

/*
int test_dart()
{
	object me;
	
	me=this_player();
	if (random(100)>50  || query("marks/gived") )
	{
		set("marks/gived",1);
		command("say 我已经找到押镖的英雄了，下次吧！");
		return 1;
	}
	else
	{
		me->set_temp("marks/caiasked",1);
		command("say 这个任务可是要用一千两金子做抵押的，你可愿意接受？(accept mission)");
		return 1;
	}
}

int do_accept(string arg)
{    
	object obj;
	object me;
	if (arg != "mission") 
		return notify_fail("什么？\n");
		
	me=this_player();
	
	if (! me->query_temp("marks/caiasked"))
	{
		return notify_fail("什么？\n");
	}
	
	if (me->query("marks/财叔护镖"))
	{
		command("heihei");
		command("say 这位"+RANK_D->query_respect(me)+"，为人要诚实，上次的任务完成啦吗？！");
		return 1;
	}
	
	if (me->query("combat_exp")<1500000)
	{
		command("heihei");
		command("say 护镖路途危险，我看这位"+RANK_D->query_respect(me)+"似乎不够资格！");
		return 1;
	}
	
	if (!intp(me->query("deposit")) || me->query("deposit")<10000000)
	{
		command("hmm");
		command("say 这次护送的镖银数目不小，我看这位"+RANK_D->query_respect(me)+"没有足够的存款做抵押。");
		return 1;
	}
	
	if ( query("marks/gived") )
	{
		command("sigh");
		command("say 你来晚了，已经有人接下这次镖了。");
		return 1;
	}

	set("marks/gived",1);
	me->set("marks/财叔护镖",1);
	me->set_temp("marks/推荐",1);
	command("say 好！我就把你推荐给金大帅，千两金子我已经从你的账户上扣除了。");
	me->add("deposit",-10000000);
	obj=new(__DIR__"obj/letter");
	if(obj)
		obj->move(me);
	message_vision("$N拿出一纸推荐信给$n。\n",this_object(),me);
	command("say 拿着这张纸条去金大帅那里吧！\n");
	return 1;
}
*/