
#include <login.h>
#include <ansi.h>

//function definition
int start_test();

inherit NPC;


mapping *question_list=({
	([	"question": "Q1: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",10,}),
				({"B: woman",10}),	
				({"C: Both",10,}),
				({"D: Neither",10,})
		}),
	]),
	([	"question": "Q2: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",20,}),
				({"B: woman",20}),	
				({"C: Both",20,}),
				({"D: Neither",20,})
		}),
	]),
	([	"question": "Q3: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",30,}),
				({"B: woman",30}),	
				({"C: Both",30,}),
				({"D: Neither",30,})
		}),
	]),
	([	"question": "Q4: Are you a man or woman?(Pick one from the following)",
		"answer": ({
				({"A: man",40,}),
				({"B: woman",40}),	
				({"C: Both",40,}),
				({"D: Neither",40,})
		}),
	]),
});


string get_question(int i)
{
	int j;
	string temp = question_list[i]["question"] + "\n";
	for (j=0;j<4;j++)
	{
		temp = temp + question_list[i]["answer"][j][0] + "\n";
	}
	return temp;
}


void create()
{
	set_name("包打听", ({ "news man","man"}) );
	set("title",YEL "无所不知"NOR);
	set("long", "只要你可以最先答对他的问题，就有铜版拿呀。\n");
	set("gender", "男性");
	set("age", 70);
	set("no_fight",1);
	set("combat_exp", 9000);
	set("score", 0);
	set("inquiry",([
    //	"测试" : (: start_test :),
    //	"test" : (: start_test :),
    ]) );
	set ("no_arrest",1);
	set("in_test",0);
	setup();
}


void init()
{
	::init();
	//if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_killing", "kill");
}

start_test()
{

	if(query("in_test")) 
	{
		message_vision("有人在做题，你必须等下一轮。\n", this_player());
		return 1;
	}
	set("in_test", 1);
	command("say 测试开始。。。");
	this_player()->set_temp("score", 0);
	this_player()->set_temp("answer_questions", 0);
	this_player()->set_temp("num_question", random(sizeof(question_list)));
	this_player()->set_temp("in_ask", 1);
	ask_question();
	add_action("do_answer", "answer");
	return 1;
}

void clear_temp(object me)
{
	me->delete_temp("score");
	me->delete_temp("answer_questions");
	me->delete_temp("num_question");
	me->delete_temp("in_ask");
}

void ask_question()
{
	message_vision( get_question(this_player()->query_temp("num_question")) + "\n",this_object());
	this_player()->set_temp("in_ask", 1);
	call_out("check_status", 60, this_player());
}

void give_result()
{
	object me = this_player();
	set("in_test", 0);
	message_vision("You have finished your test and your score is " + me->query_temp("score") + "\n", this_player());
	clear_temp(me);
}

int do_answer(string arg)
{

	object me = this_player();
	
	int	score = me->query_temp("score");
	int	num_question = me->query_temp("num_question");
	int answer_questions = me->query_temp("answer_questions");
	if (!me->query_temp("in_ask"))
	{
		return 0;
	}

	remove_call_out("check_status");
	switch (arg)
	{
	case "a" :
		score = score + question_list[num_question]["answer"][0][1];
		break;
	case "b":
		score = score + question_list[num_question]["answer"][1][1];
		break;
	case "c":
		score = score + question_list[num_question]["answer"][2][1];
		break;
	case "d":
		score = score + question_list[num_question]["answer"][3][1];
		break;
	default:
		return notify_fail("You have to answer a,b,c,d \n");
		break;
	}
	
	num_question = (num_question+1) % sizeof(question_list);
	answer_questions++;
	me->set_temp("score", score);
	me->set_temp("answer_questions", answer_questions);
	me->set_temp("num_question",num_question);
	me->set_temp("in_ask", 0);
	if ( answer_questions >= 3 )
	{
		give_result();
		
	}
	else
	{
		ask_question();
	}

	return 1;
}

void check_status(object ob)
{
	if ( !ob )
	{
		set("in_test", 0);
	}
	else if( ob->query_temp("in_ask") && environment(ob) == environment() )
	{
		message_vision ("您考虑的时间也太长了吧？ \n", ob);
		message_vision ("包打听把$N轰了出去。 \n", ob);
		ob->move("/d/fy/ecloud5");
		//clear_temp(ob);
	}
}

void remove_frozen(object me)
{
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
	message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR, me);
}

int do_killing(string arg)
{
	object target = select_opponent();
	if ((arg == "news man") && query("in_test") )
	if (query("in_test"))
	{
		command("say 我最讨厌给别人捣乱的人\n");
		message_vision(HIC "包打听一挥手，空气中星星点点闪烁这着点点冰晶。。。\n",target);
		message_vision(HIW "奇冷的寒气包围了$N的全身，将$N凝聚成冰块！", target);			
		target->set_temp("disable_inputs",1);
		target->set("disable_type",HIW "<冻僵中>"NOR);
		target->set_temp("is_unconcious",1);
		seteuid(ROOT_UID);
		target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :), 10);
		message_vision("$N被冻成一个冰块 \n", target);
		message_vision(HIY "包打听一脚把冻成大冰块的$N踢到大街上。\n"NOR,target);
		target->move("/d/fy/ecloud5");
		message_vision(HIY "砰的一声，被冻成大冰块的$N被人踢了出来。\n"NOR, target);
		return 1;
	}
	else
	{
		return 0;
	}
}
