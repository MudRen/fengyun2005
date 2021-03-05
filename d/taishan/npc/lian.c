/*
　连城壁道：“我用尽了一切方法，先让你的声名、财富、地位，都达到巅峰，然后再让你掉下来，利用你作工具，
替我除去了那些叛徒，这两点你现在一定已经想通了。”

这一切计划大功告成之后，冰冰和逍遥侯就可以真的死了，这世上也就不会再有人知道我的秘密，更不会有人怀疑
到我就是天宗的主人，所以我还是跟以前一样，是白壁无瑕，侠义无双的连城壁。” 

至少，他证明了一件事，拥有绝世武功并不一定就是强者，而高超的智慧，精密的算计，才是争雄武林的真正本钱。 

从今后，无垢山庄将永远成为人们心目中“仁义”的像征，连城壁三个字，也将永远流传不朽，成为侠中之侠，英雄中的英雄。 


*/

inherit SMART_NPC;
#include <ansi.h>

int time_period(int timep, object me);
int give_hint();
string sysmsg;

void create()
{
	set_name(HIG"连城璧"NOR, ({ "lian chengbi", "chengbi","lian" }) );
	set("gender", "男性");
	set("title", "无垢山庄 少庄主");
   	set("nickname", HIR"侠义无双"NOR);
	set("age", 29);
	set("long", "
一个文雅的世家公子，在文雅中却又带着种令人觉得高不可攀的清华之气。
竟然便是当代武林年青一代中的领袖，无垢山庄的少主，万人仰慕的绝世
奇才。\n");
	
	set("attitude", "peaceful");
	set("reward_npc", 1);
	set("difficulty", 10);
   	set("combat_exp", 10000000);
        
    set("chat_chance", 1);
    set("chat_msg", ({
                "连城璧向你拱了拱手道：＂这位英雄，今朝相遇，我连某深感荣幸！＂\n",
        }) );
        set("inquiry", ([
                "天宗" : 	(: give_hint:),
                "tianzong" : 	(: give_hint:)
        ]));

	set("fly_target",1);

	set_temp("apply/damage",100);
	set_temp("apply/haste",300);
	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","taiji",1);
   	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/hat",([	"name": "儒巾",
    						"long": "一顶读书人常戴的布帽。\n",
    						 ]))->wear();  
}

int accept_fight(object me)
{
        command("say 想切磋武功！好！我连某理应奉陪，但拳脚无情，你小心了！");
        return 1;
}

void init()
{
	::init();
//      add_action("give_quest", "quest");
//		add_action("join_in","join");
}

int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
//	string test;
	string quest;
// Let's see if this player is one of us
        if((string)who->query("guild") != "天宗")
                return 0;
	val = ob->value();
        if(!(quest =  who->query("quest")))
	{
        tell_object(who,"连城璧说道：这不是天孙要的。\n");
	return 0;
	}
        if( (string)ob->query("unit")+(string)ob->query("name") != quest)
        {
        tell_object(who,"连城璧说道：这不是天孙要的。\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"连城璧说道：这不是天孙要的。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"连城璧说道：真可惜！你没有在指定的时间内完成！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"连城璧说道：好！做得好！天宗就需要你这样的人才！\n");
	exp = random(150) + 10;
// put a cap
	exp = exp * (int) who->query_temp("quest_number")/3;
	exp += 1;
	pot = exp / 5 + 1;
	score = 1;
	who->add("potential",pot);
	who->add("score",-score);
        tell_object(who,HIW"你被〔天孙〕奖励了：\n" +
	chinese_number(pot) + "点潜能\n"NOR);
//	chinese_number(score)+"点综合评价\n"NOR);
	who->set("quest", 0 );
	who->add("QUEST",1);
                        return 1;
        }
                return 1;
}

int give_quest(string arg)
{
	string quest ;
	object me;
	int /*j,combatexp,*/ timep/*, lvl=0*/;
//      mixed *local;
	string *npcs,*objs,file;
//      int  t;
	me = this_player();
// Let's see if this player is one of us
	if((string)me->query("guild") != "天宗")
		return 0;
	if((int)me->query("last_good_kill") < ((int)me->query("mud_age") - 24*3600))
	{
		tell_object(me,"连城璧对你阴笑着说：
＂我看你对〔天宗〕并不很忠心，除非你去杀一个和你武功相当的「人」物＂\n");
		return 1;
	}

// Let's see if this player is a ghost
	if((int) me->is_ghost())
	{
		write("鬼魂不可要任务．\n");
		return 1;
	}
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return 0;
	else
		me->set("kee", me->query("kee")/2+1);
		me->delete_temp("quest_number");
	}
	file = read_file("/quest/NPC");
	npcs = explode(file,"\n");
	file = read_file("/quest/OBJ");
	objs = explode(file,"\n");
	timep = random(300)+60;   //  big random factor
// A factor here to make time random
	timep = random(timep/2)+timep/2;
	time_period(timep, me);
	if(random(2))
	{
	quest = npcs[random(sizeof(npcs))];
        tell_object(me,"替天宗杀了"+quest+"。\n"NOR);
        sysmsg +="杀了"+quest+"。";
	}
	else
	{
	quest = objs[random(sizeof(objs))];
        tell_object(me,"去抢"+quest+"给天宗。\n"NOR);
        sysmsg +="去抢"+quest+"。";
	}
 	me->set("quest", quest);
	me->add("vendetta/authority",1);
	me->set("task_time", (int) time()+(int) timep);
	if((int)me->query_temp("quest_number") < 5)
	me->add_temp("quest_number",1);
	CHANNEL_D->do_sys_channel("qst", sprintf("%s(%s)：%s",
	me->query("name"),me->query("id"),sysmsg));

return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n在" + time + "内");
	sysmsg = "在" + time + "内";
        return 1;
}

int give_hint()
{
	object me,obj;
	me = this_player();
	obj = this_object();
//	if(me->query_temp("num_of_ask") < random(4)+5)
//	{
//		me->add_temp("num_of_ask",1);
		tell_object(me,"连城璧道：＂〔天宗〕是当今武林中最神秘，邪恶的帮会，它笼络天下各
派高手，以暗杀方式来铲除异己。〔天宗〕的主人－－天孙的身份也是个天大的迷。
〔天宗〕经常无故残杀天下老少英雄，以巩固自己在武林中的地位！\n");
		return 1;
//	}
//	else{
//	tell_object(me,"连城璧道：＂你似乎对〔天宗〕很感兴趣，是否想加入呢（join yes/no）？＂\n");
//	return 1;
//	}

}
int join_in(string arg)
{
	object me;
	me = this_player();
	if((int)me->query_temp("num_of_ask") < 5) return 0;
	if(!arg || arg != "yes" || me->query("combat_exp") < 800000)
	{
	me->delete_temp("num_of_ask");
        me->set_temp("in_doubt",1);
	return notify_fail("连城璧道：＂〔天宗〕极邪，极毒，如果你加入〔天宗〕，
我决不放过你！＂\n");
	}
	tell_object(me,"连城璧在你耳边悄声道：
＂其实我就是〔天宗〕的少主，从今以后，你就为〔天宗〕出力吧！我绝对不会亏待你的！
你可以向我要任务（quest），但你一定要证明你是强者！＂\n");
	me->set("guild","天宗");
        me->delete_temp("num_of_ask");

	return 1;

}