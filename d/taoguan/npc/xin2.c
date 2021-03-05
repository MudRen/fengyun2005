// ; annie 07.2003
// dancing_faery@hotmail.com
// 
// 八部众之夜叉王 千魂集焰 辛望 
// EXP 8M KEE 40K GIN/SEN 24K RESIST/ALL 60
// STR 40 DMG 25 ATTACK 46K DODGE 45K PARRY 150K
// PETMASTER

// A/D/P：远低于标准8M，PARRY数值高，此人不可TK。
// 宠物群：6M EXP，完全BUFF之后50-81K ATTACK,32K D/P.

inherit NPC;
#include <ansi.h>
#include <combat.h>
int kill_him();

void kick_out(object me)
{
	message_vision(CYN"\n辛望一扬手，一张土黄色的符纸飞贴到$N额上，$N的身影逐渐在空气里模糊．．\n\n"NOR,me);
	me->move(load_object("/d/taoguan/taoguan"));
	message_vision(CYN"\n大门前的空气忽然开始阵阵波动，一个模糊的轮廓慢慢的从虚空中显现出来．．．\n\n"NOR,me);
}

void create()
{
	object armor,weapon;
	set_name("辛望", ({ "xin wang","xin"}) );
	set("gender", "男性" );
	set("title",YEL"仙风道骨"NOR);
	set("age", 60+random(10));
	set("attitude","friendly");

        set("inquiry", ([
                "三清道宗":  (: kill_him :),
        ]) );

	set("long",
		"此人乌衣白发，几络长须，手持纸剑，身披道袍，看起来一派\n道骨仙风。\n"
		);
	set("class","demon");
    set("score", 10000);

	set("no_fly",1);
	set("no_arrest",1);
		
	set("resistance/gin",60);
	set("resistance/kee",60);
	set("resistance/sen",60);

	set("max_kee",40000);
	set("max_gin",24000);
	set("max_sen",24000);
	
	set("NO_KILL","尽管辛望就站在你面前四尺之处，但这短短的四尺距离你就是无法跨越。\n");

	
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//               (: smart_fight() :),
        }) );


	setup();

	carry_object(__DIR__"obj/taopao")->wear();
	carry_object(__DIR__"obj/papersword")->wield();

}

int kill_him()
{
	object me;
	me = this_player();
	if (REWARD_D->riddle_check(me,"无字天书") != 5)
	{
		ccommand("heng");
		kick_out(me);
		return 1;
	}
	ccommand("hmm");
	ccommand("say 那本书上的文字，老夫已滚瓜烂熟。");
	ccommand("say 书可以还你，不过老夫有个条件，不知你答不答应？\n"HIY"(answer "HIW"yes"HIY"/"HIW"no"HIY")\n"NOR);
	me->set_temp("annie/riddle_ask_xin",1);
	return 1;
}


int do_answer(string arg)
{
	object me = this_player();
	if (!me->query_temp("annie/riddle_ask_xin"))
		return 0;
	me->set_temp("annie/riddle_ask_xin",0);
	if (arg == "no")
	{
		ccommand("hmm");
		return 1;
	}
	me->ccommand("ok");
	ccommand("nod");
	ccommand("say 果然爽快。");
	ccommand("say 你去提万马堂堂主马空群的头来见我，我便把书给你。");
	REWARD_D->riddle_set(me,"无字天书",6);
	kick_out(me);
	return 1;
}

void init()
{
	object me;
	::init();
	me = this_player();
	if (userp(me) && environment(me)->query("short") == "三清密室"  && REWARD_D->riddle_check(me,"无字天书") != 6)
		call_out("do_greeting",1,me,environment(this_object()));
	if (userp(me) && environment(me)->query("short") == "三清密室"  && REWARD_D->riddle_check(me,"无字天书") == 6)
		call_out("do_greeting",6,me,environment(this_object()));
	add_action("do_answer","answer");
}



void do_testppl(object me,int count,object room)
{
	string msg;
	string *event_msg = ({
"\n$N看到$n走进来，抬了抬眉毛，脸上露出一丝诧异之色。\n",
"$N笑道：这么快就已经还了心愿，可以来送死了么？\n",
"$N点点头道：我们本无怨仇，你替我杀了马空群，照理说我当感谢你才是。\n",
"$N顿了一顿，又道：只不过你又站在丁家兄妹一边．．丁家兄妹的朋友，就是我们的敌人。\n",
"$N突地微笑：四相转生之阵所缺的东西我终于找出来了，那就是＂杀机＂……或许你可以再帮我一次？\n",
"$N对着$n弹弹小指，一团浓密的黑雾忽在$n脚下升腾而起，转眼就将$n淹没。\n\n"});
	if (!me || environment(me) != room)
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+NOR,this_object(),me);
	if (count < sizeof(event_msg)-1)
		call_out("do_testppl",1+random(2),me,count+1,room);
	else
	{
		set("ggyy",0);
		me->set_temp("annie/demon_xin_1",1) ;
		me->move(load_object("/d/taoguan/fog"));
	}
	return;
}


void do_greeting(object me,object room)
{
	object book;
	if (!me || environment(me) != room)
		return;

	if (REWARD_D->check_m_success(me,"无字天书") == 1)
	{
		if (query("ggyy"))
		{
			kick_out(me);
			return;
		}
		// 转进战斗阶段。
		set("ggyy",1);
		do_testppl(me,0,room);
		return ;
	}

	if (REWARD_D->riddle_check(me,"无字天书") != 5)
	{
		kick_out(me);
		return;
	}
	ccommand("pat xin wang");
	ccommand("say 阵法已成，媒介齐聚，天时相顺，地脉未违．．．这四相转生之术，到底还缺了什么？");
	ccommand("consider");
}


int accept_object(object who, object ob)
{
	object me = this_player(), book;
	int i = REWARD_D->riddle_check(who,"无字天书");
	if (!i)
		return 0;
	if (i != 6)
		return 0;
	if (!ob->query("real"))
		return 0;

	if (ob->query("name")=="马空群的头")
	{
		// consider...annnnie
		ccommand("haha");
		ccommand("emote 捋着白须，点头道：好，好！");
		ccommand("say 老夫言当有信，这书你就拿去还给丁白云。");
		ccommand("say 窃书之事，等你了了且未完成的心愿，再来找我吧。");
		book=new(__DIR__"obj/necbook");
		if (!book->move(me))
			book->move(environment(me));
		REWARD_D->riddle_set(me,"无字天书",8);
		tell_object(me,HIY"你得到一本「"HIW"三清道宗"HIY"」！\n"NOR);
		kick_out(me);
		return 1;
	}
	else if (ob->query("name")=="傅红雪的头")
	{
		ccommand("emote 怫然变色，冷笑道：好，很好。");
		ccommand("emote 一扬手，将一本线装书丢给$n，恨声道：且让你去还了心愿，再滚来受死吧！");
		book=new(__DIR__"obj/necbook");
		if (!book->move(me))
			book->move(environment(me));
		REWARD_D->riddle_set(me,"无字天书",8);
		tell_object(me,HIY"你得到一本「"HIW"三清道宗"HIY"」！\n"NOR);
		kick_out(me);
		return 1;
	}
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

