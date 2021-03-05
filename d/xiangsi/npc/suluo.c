// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>

void smart_fight();
int leave();
int look_stone();

void create()
{
        set_name("薛苏萝", ({ "xue suluo", "xue", "suluo", "master" }) );

		set("class","moon");

		create_family("皓月宫", 3, "");
		set("nickname",HIC"夜雨闻霖断肠声"NOR);
		set("title","皓月天宫");

        set("gender", "女性");
        set("apprentice_available", 1);

		set("guard_msg",CYN"$N皱眉道：欺负我皓月宫的人，欺负上我这里来了？\n"NOR);

        set("reward_npc", 1);
		set("difficulty", 4);
		set("per", 32);
		set("age",20);
		set("attitude","peaceful");

        set("combat_exp", 3000000);
        
		set("long","薛苏萝正半倚在妆案边，愁眉不展。\n");
		set("chat_chance", 1);
		set("chat_msg", ({
			"薛苏萝轻声叹息：不知道素姐姐与李坏的这段缘分，会落作怎生的了断．．．\n",
			"薛苏萝说道：你能想到么？这里曾经是荒山一座，连山门的石坊都是素姐姐亲自立的。\n",
		}) );

		set("inquiry",([
		"月神": (: look_stone :),
		"李坏": (: look_stone :),
        "leave": (: leave :),
        "素姐姐": (: look_stone :),		
    	]) );

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

        set("rank_nogen",1); 
//		set("ranks",({ "小喽罗","大喽罗","小头目","大头目","大头领",RED"大盗"NOR,RED"盗帅"NOR,HIR"副山主"NOR }));
        
        set_skill("force", 160);    
		set_skill("dodge", 200);    
		set_skill("move", 150);    
		set_skill("parry", 150);    
		set_skill("literate", 100);
		set_skill("blade", 200);    
		set_skill("chanting",150);
		set_skill("snowforce",170);
		set_skill("chillblade",190);
		set_skill("stormdance",150);
		set_skill("perception",150);
		set_skill("foreknowledge",100);
		set_skill("spells",100);
		
	    map_skill("force","snowforce");
	    map_skill("blade","chillblade");
	    map_skill("parry","chillblade");
	    map_skill("move","stormdance");
	    map_skill("dodge","stormdance");
     	setup();

		carry_object(__DIR__"obj/xueyu")->wear();
		carry_object(__DIR__"obj/xianyue")->wield();

}

void reset()
{
	set("apprentice_available", 1);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("bored");
                command("shake");
                command("lazy xue suluo");
        }
}


void do_recruit(object me)
{
	if( (string)me->query("class") != "moon" )
	{
		command("loveme " + me->query("id") );
	}
	else
	{
		command("woman");
		command("say "+me->name()+"，你一定要把皓月一脉传承下去．．");
		// 遥想当年，雪姑娘拍着我说：你日后必有大成！．．．
		command("recruit " + me->query("id") );
	}
}
		
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "moon");
	add("apprentice_availavble", -1);
}

void init()
{	
	::init();
	add_action("do_killing", "kill");
//	add_action("do_accept", "accept");
        if( !query_heart_beat(this_object()) ) {
		set_heart_beat(1); 
	}
}

int do_accept(string arg)
{
	object me = this_player();
	if (me->query("family/master_name") == "薛苏萝" && me->query("family/master_id") == "xue suluo" && me->query("class") == "moon" && !me->query("annie/moon_master"))
	{
		if (arg == "yes")
		{
			ccommand("consider");
			ccommand("look "+me->query("id"));
			if (me->query("combat_exp") < 1280000)	// 过1.28M不怕死就可以去leh
			{
				ccommand("say 他是名扬天下的飞刀传人，要想胜他，你还需多加练习。");
				ccommand("pat "+me->query("id"));
				return 1;
			}
			else
			{
				ccommand("shu "+me->query("id"));
				ccommand("consider");
				ccommand("ok");
				ccommand("say 你代素姐姐去见他，想来就可以了结这桩事故．．");
				ccommand("say 你可以到山下去找公孙无胜老先生，他一定知道李坏在哪里。");
				ccommand("pat "+me->query("id"));
				ccommand("sweat "+me->query("id"));
				me->set("annie/moon_master",1);
				return 1;
			}
		}
		else if (arg == "no")
		{
			ccommand("sigh");
			ccommand("say 可要怎么办才好？．．．");
			return 1;
		}
	}

	return 0;
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}

int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	object target;
	int i;
	target = select_opponent();
	
	i = query("combat_exp") * 100 / target->query("combat_exp") ;

	ccommand("exert bingpojingbi");
	ccommand("perform dodge.shuangtianxuewu");

	if (!query_temp("weapon"))
		if (ccommand("get newmoon blade"))
			if (ccommand("wield newmoon blade"))
				stop_busy();
	
	if (i > 180 && (userp(target) || query("test")))
		SKILL_D("chillblade")->perform_target(this_object(),"yuhouchuhong",target);
		
	if (query("mana") && (userp(target) || query("test")))
		ccommand("perform qinghui");
}

int leave()
{
    if (this_player()->query("class")!="moon") return 0;
	message_vision(CYN"$N淡淡的扫了$n一眼。\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：既然你一心要走，我也不想勉强。\n"NOR,this_object(),this_player());
	message_vision(CYN"$N说：只是门中各艺的精髓，你是都无法再用的了。\n"NOR,this_object(),this_player());
    return 1;
}

int look_stone()
{
	object me;
//	int i;
//	string msg;
	me=this_player();
	if (REWARD_D->riddle_check(me,"两世恩怨") != 4 && REWARD_D->riddle_check(me,"两世恩怨") !=5 )
	{
		ccommand("say ……姐姐说，陌上花开，可缓缓归矣……");
		return 1;
	}

	if (REWARD_D->riddle_check(me,"两世恩怨") == 4 )
	{
		ccommand("say 这……");
		ccommand("emote 凝眉苦思片刻，似乎略有所得．．．");
			REWARD_D->riddle_set(me,"两世恩怨",5);
		return 1;
	}

	message_vision("$N说道：素姐姐与李坏一战之期已近，惟今之计，只有先设法找到李坏，私下调解。\n"NOR,this_object(),this_player());
	message_vision("$N说道：传说山下的公孙太夫人往年曾与李坏一战，她或许知道李坏住在哪里。\n"NOR,this_object(),this_player());
			REWARD_D->riddle_set(me,"两世恩怨",6);
    return 1;
}

/*
薛苏萝目前共学过十种技能：

  基本刀法 (blade)                         - 出神入化 150/    0
＊冰镜七诀 (chillblade)                    - 出神入化 150/    0
  纵跃闪躲之术 (dodge)                     - 登峰造极 160/    0
  内功心法 (force)                         - 一代宗师 180/    0
  读书识字 (literate)                      - 了然於胸 135/    0
  基本轻功 (move)                          - 一代宗师 180/    0
  拆招卸力之法 (parry)                     - 登峰造极 160/    0
  听风辨器之术 (perception)                - 出类拔萃 100/    0
＊冷雪心经 (snowforce)                     - 出神入化 140/    0
＊天岚凝舞 (stormdance)                    - 登峰造极 160/    0
*/

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/