#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("铁恨",({"tie hen","tie"}));
    	set("nickname","铁手无情");
    	set("title",WHT"四大名捕"NOR);
    	set("long", "
一个身子标枪般笔挺的黑衣人，冷漠的脸，残酷的眼神。他就是六扇门里，四大名
捕中的“铁手无情”，他恨的是乱臣贼子，盗匪小人。这七年来，被他侦破的巨案，
已不知有多少。。\n");
		set("age",47);
		set("combat_exp", 7000000);
        set("attitude", "friendly");	
	
		set("inquiry", ([
        		"海龙王" : 	"海龙王是东海一霸，几天前忽然被人杀了。\n",
             	"郭易" :	"郭易是七年前太平王府的珠宝失窃一案主嫌的兄弟，我正在追踪他。\n",
             	"long wang" : 	"海龙王是东海一霸，几天前忽然被人杀了。\n",
             	"guo yi" :	"郭易是七年前富贵王的珠宝失窃一案主嫌的兄弟，我正在追踪他。\n",
             	"太平镇" :	"太平镇是西疆的一个小镇。\n",
             	"韦七娘":	"神针韦三娘是我的好友，听说她已经到了太平镇。\n",
             	"血鹦鹉":	"action铁恨浓眉深锁：这血鹦鹉，听说与太平王府一案有关。\n",
             	"坟地":		"我追踪郭易到此便失了踪影，却有无名杀手出现。\n",
             	"坟场":		"我追踪郭易到此便失了踪影，却有无名杀手出现。\n",
             	"无名杀手":		"我追踪郭易到此便失了踪影，却有无名杀手出现。\n",
             	
   		]));
	
    	set("reward_npc",1);
    	set("difficulty",10);
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
		
		auto_npc_setup("xuebin",250,190,0,"/obj/weapon/","fighter_w","dragonstrike",1);
		setup();
		carry_object(__DIR__"obj/blackcloth")->wear();
		carry_object(__DIR__"obj/jade");
}


void init() {
	
		object ob;
		::init();
		add_action("do_answer","answer");
		if( interactive(ob = this_player()) && !is_fighting()) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	call_out("ask_question_1",1,ob);

}

int ask_question_1(object who)
{
	
	if (REWARD_D->check_m_success(who,"喋血鹦鹉"))	return 1;
	
	if (REWARD_D->riddle_check(who,"喋血鹦鹉")>4 ||who->query_temp("marks/parrot/赴太平镇"))	{
		message_vision(CYN"$N对$n说：“怎么样，可有线索了么？”\n"NOR,this_object(),who);
		return 1;
	}
	
	// This one is just a temp mark.. to prove players' value.	
	if (!who->query_temp("marks/parrot/t_question_1") 
			&& REWARD_D->riddle_check(who,"喋血鹦鹉")<3) {
		tell_object(who, CYN"铁恨看了你一眼说：听说东海海龙王一家十人，忽然在一夜之间死得干干净净。
这事和你有没有关系？\n"NOR);
    	who->set_temp("marks/parrot/t_answer_person",1);
		return 1;
	}
	
	if (REWARD_D->riddle_check(who,"喋血鹦鹉")<=1)	{
		tell_object(who, YEL"铁恨浓眉深锁，望着远处的坟地，一语不发。\n"NOR);
		return 1;
	}
	
	if ( REWARD_D->riddle_check(who,"喋血鹦鹉")==2 && who->query_temp("marks/parrot/t_question_1")) {
		tell_object(who, CYN"铁恨看了你一眼说：我正在调查七年前富贵王的珠宝失窃一案，主嫌的兄弟郭易
据说潜逃于此坟地之间，你是否见过？\n"NOR);
		who->set_temp("marks/parrot/t_answer_person",2);
		return 1;
	}
	
	if ( (REWARD_D->riddle_check(who,"喋血鹦鹉")== 3 
			|| REWARD_D->riddle_check(who,"喋血鹦鹉")==4)
			&& !who->query_temp("marks/parrot/赴太平镇") ) {
		tell_object(who,CYN"\n铁恨拱手道：阁下真乃义士，在下有一事冒昧相求，不知可否？\n"NOR);
		who->set_temp("marks/parrot/t_answer_person",3);
		return 1;
	}
}

int do_answer(string arg)
{
	object who,*inv,jade;
	int i, gotit;
	
	who=this_player();
	
	if(!who->query_temp("marks/parrot/t_answer_person")) return 0;
		
	if (who->query_temp("marks/parrot/t_answer_person")==1) {
		if(arg=="yes" || arg == "有" || arg == "是" || arg == "是我杀的")
		{
			who->ccommand("nod");
			if (!who->query("m_killer/海龙王")) {
				tell_object(who, CYN"铁恨冷笑道：既然如此，你还是自己去投案吧。\n"NOR);
				who->delete_temp("marks/parrot/t_answer_person");
				return 1;
			}
			tell_object(who,CYN"铁恨击掌道：杀该杀的人，杀后不取分文，佩服！\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			who->set_temp("marks/parrot/t_question_1",1);
			call_out("ask_question_1",1,who);
			return 1;	
		}
		if(arg=="no" || arg == "没有"){
			message_vision(CYN"$N赶紧摇了摇头。\n"NOR,who);
			tell_object(who,CYN"铁恨说：我正在追拿凶犯，不是你就好。\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			return 1;
	        }
	}
	
	if (who->query_temp("marks/parrot/t_answer_person")==2) {
		if(arg=="yes" || arg == "有" || arg == "是" || arg == "见过")
		{
			who->ccommand("nod");
			tell_object(who,CYN"铁恨道：好，他果然在这里，他逃不了了！\n");
			who->delete_temp("marks/parrot/t_answer_person");
			REWARD_D->riddle_set(who, "喋血鹦鹉", 3);
			call_out("ask_question_1",1,who);
			return 1;	
		}	
		if(arg=="no" || arg == "没有"){
			message_vision(CYN"\n$N赶紧摇了摇头。\n\n"NOR,who);
			tell_object(who,CYN"铁恨喝道：大胆！竟然敢哄骗于我，跟我到衙门里去说话！\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			this_object()->kill_ob(who);
			who->kill_ob(this_object());
			return 1;
	    }
	}
	
	
	if (who->query_temp("marks/parrot/t_answer_person")==3) {
		if(arg=="yes" || arg == "sure" || arg == "当然" || arg == "是" || arg == "可")
		{
			message_vision(CYN"$N道：在下对铁捕头侠义心肠心仪已久，敢不从命！\n"NOR,who);
			command("spank "+this_player()->get_id());
			tell_object(who,CYN"
铁恨道：很好，我追查太平王府一案已有三年，数月前大盗满天飞在暗中兜售失窃
的珠宝，费尽心机缉拿入狱，审问时他却突然毒发身亡，仅供出“鹦鹉“二字。满
天飞赃物据闻源自陕西一个叫做太平镇的地方。我沿着蛛丝马迹追查至此，却发现
处处有人监视截杀。我看见你杀入七海山庄，诛除海龙王这个恶贼之时，已经知道
你是一个正义的剑客，所以想请你助我一臂之力，先到太平镇勘查，待我打发掉跟
踪之人再与你会合。太平镇虽小，敌友难分，你需处处小心，慎重行事。\n"NOR);
			
			jade=new(__DIR__"obj/jade");
			if (!jade->move(this_player()))
				jade->move(environment(who));
			tell_object(who,"铁恨递给你一物道：你可凭此碧玉去找一个叫韦七娘的女子，
她已于数月前化名潜入太平镇打探情况。\n");
			
			who->delete_temp("marks/parrot/t_answer_person");
			REWARD_D->riddle_set(who, "喋血鹦鹉", 4);
			
//	finish with 坟场 riddle, 
//	If the player loses the jade, relogin can get another one
			who->set_temp("marks/parrot/赴太平镇",1);
			return 1;	
		}
		if(arg=="no" || arg == "不" ){
			message_vision(CYN"$N犹豫不决地摇了摇头。\n"NOR,who);
			tell_object(who, CYN"铁恨失望地叹了口气说：人各有志，我不勉强。\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			return 1;
	     }
	}
	return 0;
}

