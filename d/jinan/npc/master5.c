// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <combat.h>

int nangong();
int leave();
int wuwu();

void create()
{
    	set_name("任慈", ({ "master renci", "master"}) );
    	set("nickname", HIR "前任帮主"NOR);
    	set("long", "任慈是丐帮的前任帮主，只因近来身体多病才让位于南宫。\n");
    	set("gender", "男性" );
    	set("class","beggar");
    
    	set("reward_npc", 1);
    	set("difficulty", 15);
    
    	set("age", 64);
    	set("per", 25);
    	    
    	set("attitude","friendly");
        	
    	create_family("丐帮", 6, "前任帮主");
    	set("rank_nogen",1);
    	
		set("ranks",({"堂外弟子","一袋弟子","两袋弟子","三袋弟子","四袋弟子","五袋弟子","六袋弟子",
			"七袋弟子","八袋弟子","九袋弟子","传功长老","传法长老",WHT"净衣堂首座"NOR,
			WHT"污衣堂首座"NOR,WHT"副帮主"NOR,HIW"龙头大哥"NOR}));
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));

    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.xianglongwuhui" :)
            }) );
   	
   		set("combat_exp", 4000000);
    
    	set_skill("unarmed",180);
    	set_skill("foreknowledge",200);
    	set_skill("advanced-unarmed",200);
    	set_skill("dodge",180);
    	set_skill("staff",300);
    	
    	set_skill("force", 160);
    	set_skill("move", 160);
    	set_skill("parry",160);
    	set_skill("literate", 100);
    	set_skill("perception",100);
    	set_skill("chanting",100);
    	
    	set_skill("begging",200);
    	set_skill("doggiesteps",200);
    	
    	set_skill("dragonstrike",170);
    	set_skill("huntunforce",150);
    	set_skill("dagou-stick",180);
    	    
    	set_temp("apply/dodge",200);
    	set("inquiry", ([
        	"南宫灵" : 		(: nangong :),
        	"nangong" : 	(: nangong :),
        	"悟"	:			(: wuwu :),
        	"叶淑贞":	"action任慈紧皱双眉说：你可有拙荆的消息？\n",
    	]));
    
    	map_skill("dodge", "doggiesteps");
    	map_skill("force", "huntunforce");
    	map_skill("unarmed", "dragonstrike");
    	map_skill("staff","dagou-stick");
    	map_skill("parry","dragonstrike");
    	map_skill("move","doggiesteps");
    	
    	setup();
    	carry_object(__DIR__"obj/9bagcloth")->wear();
	
	
}


void init(){
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
	    remove_call_out("greeting");
	    call_out("greeting", 2, ob);
	}
	add_action("do_killing", "kill");
	add_action("do_answer","answer");
}

void greeting(object ob){
	if( !ob || environment(ob) != environment() ) return;
	message_vision("\n$N颤巍巍地抬起头看了看$n，叹了口气。\n",	this_object(), ob); 
}

void attempt_apprentice(object me)
{
    	
    	if (REWARD_D->check_m_success(me,"局中局") && me->query("class")=="beggar"){
    		command("nod"); 
    		command("recruit " + me->query("id") );
    	} else {
			command("sigh");
        	command("say 我已经不再是帮主了，体力不行了，你还是去找南宫吧！\n");
    	}
}

void recruit_apprentice(object ob){
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "beggar");
}

int nangong(){
	
	object me=this_player();
	
	if (!REWARD_D->check_m_success(me,"送信丐帮")
		||me->query("class")!= "beggar"  
		|| !REWARD_D->check_m_success(me,"魂断鹊桥")
		|| REWARD_D->riddle_check(me,"局中局"))
	{
		command("say 南宫对我甚为孝顺，每天清粥一碗，从未间断！\n");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"局中局"))
	{
		command("say 南宫灵，嘿嘿，南宫灵！");
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"局中局"))
	{
		command("say 南宫灵只是一个小丑，光大丐帮才是你真正的重任！");
		return 1;
	}
		
		
	command("sigh");
	command("say 这帮中变故看来你已知晓，南宫野心勃勃，夺我帮主之位，囚我妻女，
更野心勃勃，意图与匪寇勾结，祸害武林，以你之见，该当如何处置？");
	me->set_temp("marks/a_renci",1);
	return 1;	
}	

int accept_object(object me, object ob)
{
		if(ob->name() == "云素密函")
		{
			
			REWARD_D->riddle_done(me,"送信丐帮",5,1);
			
			if ( me->query("class")!= "beggar"  
				|| !REWARD_D->check_m_success(me,"魂断鹊桥"))
			{
				command("sigh");
				command("say 此事我早已知晓，你且去吧。");
				return 1;
			}
			
			if (REWARD_D->check_m_success(me,"魂断鹊桥")==1){
				command("sigh");
				command("say 这帮中变故看来你已知晓，南宫野心勃勃，夺我帮主之位，囚我妻女，
更野心勃勃，意图与匪寇勾结，祸害武林，以你之见，该当如何处置？");
				me->set_temp("marks/a_renci",1);
				return 1;					
			}
		}
		return 0;
}		
			

int do_answer(string arg){
	
	object me= this_player();
	object room;
	if (!me->query_temp("marks/a_renci"))	return 0;
		
	if (me->query_temp("marks/a_renci")==1) {
		if (arg == "forgive" || arg == "宽恕")
		{
			message_vision(CYN"$N摇摇头说：如此可对得起九泉下的冤魂！\n"NOR,this_object());
			return 1;
		}
		
		if (arg != "杀" && arg!="杀了" && arg !="kill") {
			command("sigh");
			command("shake");
			return 1;
		}
		
		message_vision(CYN"任慈的双目忽然一亮，转瞬又黯淡下去。\n"NOR, me);
		command("say 南宫羽翼已丰，贸然动手恐怕只有白白牺牲。\n");
		command("say 这天下之事，岂是一个“杀”字可以包容？人生如棋局，世人
如棋卒，你徒有血气之勇，经历尚欠，入帮数年，可有后悔之事？");
		me->set_temp("marks/a_renci",2);
		return 1;
	}
	
	if (me->query_temp("marks/a_renci")==2)	{
		if (arg == "有")
		{
			command("say 是哪一件哪一人，说来我听。");
			return 1;
		}
		
		if (arg == "没有")
		{
			command("say 好自傲的后生，好一个南宫灵的徒弟！");
			message_vision(CYN"任慈低头不再言语。\n", me);
			return 1;
		}
						
		if (arg != "清波" && arg!="袁姬" && arg!="qingbo" && arg!="yuanji"
			&& arg!="魂断鹊桥" 
			|| !REWARD_D->check_m_success(me,"魂断鹊桥")) {
			command("sigh");
			command("say 可还有其他？");
			return 1;
		}
		
		command("nod");
		command("say 我已知此事，清波袁姬，竟遭此大难。");
		command("say 然而这亦是一个局，你能勘破其中的关窍么？");
		me->set_temp("marks/a_renci",3);
		return 1;
	}
	
	if (me->query_temp("marks/a_renci")==3)	{
		if (arg != "能" && arg!="不能") {
			tell_object(me,"\n你只能回答“能”或者“不能”\n");
			return 1;
		}
		if (arg == "能") {
			command("say 说来听听。");
			me->set_temp("marks/a_renci",4);
			return 1;
		}
		if (arg =="不能") {
			command("consider");
			command("say 好，就让老夫助你一臂之力！");
			message_vision("任慈一声大喝，双掌合计，排山倒海的掌力向$N袭来。
			
$N胸中气息一窒，眼前一阵黑。\n"NOR, me);					
			
			tell_object(me, WHT"
你觉得自己好像在云里雾里飞行，许多熟悉的面孔，许多熟悉的声音，
许多熟悉的景象，却恍恍惚惚什么也抓不住，什么也听不真切。。。。\n"NOR);

			REWARD_D->riddle_set(me,"局中局",1);
			me->delete("m_success/魂断鹊桥");
			REWARD_D->riddle_set(me,"魂断鹊桥",1);
			
			if (!room = find_object("/d/chenxiang/gaij"))
				room = load_object("/d/chenxiang/gaij");
			me->unconcious();
			me->move(room);
			return 1;
		}
	}
	
	message_vision(CYN"$N缓缓地摇了摇头，坐回榻上，不再言语。\n"NOR, this_object());
	me->delete_temp("marks/a_renci");
	return 1;
	
}	

int wuwu(){
	
	object me = this_player();
	
	if (REWARD_D->riddle_check(me,"局中局")!=2)	return 0;
	
	command("smile");
	
	
	command("say 凡世间的事情, 缘来缘去， 缘生缘灭，");
	command("say 不明了的，继续追寻...");
	command("say 看透的, 一个点头, 一个微笑, 已经更胜千言万语。");
	command("say 正如有人记起，有人遗忘。有人离开，有人返回。\n");
	command("say 南宫灵资质上乘，本是人中龙凤，便是看不破这生死名利之关。");
	command("say 其实大丈夫在世，死就死了，做也做了，但求无愧于心便是。");
		
	REWARD_D->riddle_done(me,"局中局", 50, 1);
	return 1;

}

