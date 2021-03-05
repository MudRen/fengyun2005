// silencer@fy4.
// last modified by annie 6.28.03, added a part of demon riddle.
// a cool man? *snicker

#include <ansi.h>
inherit SMART_NPC;

string ask_for_help();

void create()
{
        seteuid(getuid());
    	set_name("丁云鹤",({"ding yunhe","ding","yunhe"}));
	set("title","丁家庄 大少爷");
   	set("long","
道装高冠，神采飞扬，丁云鹤是丁乘风的长子，无论是武功还是三清道术都
已得其父真传，近年来闯荡江湖，已有青出于蓝而胜于蓝之势。\n");
     	set("gender","男性");
    	set("age",42);
    	set("class","taoist");
    	 	   	
    	set("combat_exp",8000000);  
    	set("attitude", "friendly");
    	    	
    	set("death_msg",CYN"\n丁云鹤身子突然倒飞而出，凌空两个翻身，“砰”的一声撞在屋檐上
再跌下来，脸上已看不见血色，胸膛前却已多了条血口。\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
        
        set("inquiry",	([
        	
        	"无字天书":	"action丁云鹤默默地看着你，一语不发。\n",
        	"大姑":		"我大姑你都不知道？我姓什么？\n",
        	"不知道":	"不知道的事就别多问。\n",
        ]));
        	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );
		set("chat_chance",1);
		set("chat_msg", ({
			(: ask_for_help :),
		}) );

		auto_npc_setup("wang",200,220,0,"/obj/weapon/","fighter_w","necromancy",1);
		
		setup();
    	carry_object(__DIR__"obj/c_cloth")->wear();    
    	carry_object(__DIR__"obj/y_sword")->wield();
    
}

string ask_for_help()
{
	object me;
	me = this_object();
	// callout 20秒,没有耐心的人..对不起啦>"<
	message_vision(CYN"丁云鹤在院中踱来踱去，紧皱眉头。\n"NOR,me);
	remove_call_out("ask_help");
	call_out("ask_help",20);
	return CYN""NOR;
}

void ask_help()
{
	object me,room,*olist,target;
	int i;

	me = this_object();
	room = environment(me);
	olist = all_inventory(room);
	if (me->is_fighting())	// 战斗中不分心.
		return;
	message_vision(CYN"$N叹了一口气，又叹一口气，似有无限困扰。\n"NOR,me);
	for(i=0; i<sizeof(olist); i++)
	{
		target = olist[i];
		if (!REWARD_D->check_m_success(target,"无字天书") 
			&& !REWARD_D->riddle_check(target,"无字天书"))
		{
			tell_object(target,CYN"你向丁云鹤作了个揖，好奇的打听：这位公子可是有什么烦恼？\n"NOR);
			tell_object(target,CYN"丁云鹤说道：我历年来一直游侠在外，这次在道术上遇到难题，不得已回山询教。\n"NOR);
			tell_object(target,CYN"丁云鹤说道：让我百思不解的那个四相转生术记载在本教镇教秘籍之上，我记得清清楚楚。\n"NOR);
			tell_object(target,CYN"丁云鹤说道：可是大姑偏生说我记错，硬是不肯将书借我。\n"NOR);
			tell_object(target,CYN"丁云鹤说道：唉．．．\n"NOR);
			REWARD_D->riddle_set(target,"无字天书",1);
		}
	}
	return;
}



int accept_object(object who, object ob)
{
	int i = REWARD_D->riddle_check(who,"无字天书");

	if (ob->query("is_xbook"))
	{
		ccommand("ack");
		ccommand("say 找到了？");
		ccommand("say 快拿去还给我大姑吧，我随后再问她借好了。");
		return 0;
	}

	if (ob->query("is_fake_necbookx"))
	{
		ccommand("emote 怒道：你竟敢擅毁本教秘籍！");
	//	kill_ob(ob);		杀书啊
	//	ob->perform_busy(4);
		return 1;
	}

    if (!ob->query("is_fake_necbook"))
	{
		ccommand("heng2 "+who->query("id"));
		return 0;
	}
	if (!i)
	{
		ccommand("emote 喝道：居然敢偷我教秘籍，你好大的胆子！");
		ccommand("kill "+who->query("id"));
		return 1;
	}
	if (i != 1)
	{
		ccommand("shake");
		ccommand("say 书既然是假的，我要来还有什么用呢？");
		ccommand("sigh");
		return 0;
	}
	ccommand("ah");
	if (who->query("gender") != "女性")
		ccommand("thank "+who->query("id"));
	else
		ccommand("ppp "+who->query("id"));
	ccommand("emote 接过书，飞快的翻过一页，飞快地又翻过一页。");
	ccommand("faint");
	ccommand("say 这．．这．．这本书中怎么一个字都没有？莫非．．这本书是假的？");
	ccommand("say 这．．．你快去问问大姑！");
	REWARD_D->riddle_set(who,"无字天书",2);
	return 1;
}
 
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

