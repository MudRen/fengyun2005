inherit SMART_NPC;
#include <ansi.h>

int do_help();
int do_cont();

void create()
{
    	set_name("武三爷",({"wu sanye","wu","sanye"}));
    	set("title",HIR"铁掌"NOR);
    	set("long","
三爷姓武，名镇山，不过这儿没人敢叫他的名字，敢叫的人第二天就什么名
字都叫不出声了。武三爷什么都不干，只不过太平镇这地方有一半是他的。。\n");
    	set("gender","男性");
    	set("age",52);
		set("combat_exp", 9000000);
        set("attitude", "friendly");	
	
		set("reward_npc",20);
	
		set("inquiry", ([
        	"老大":		"action武三爷向你意味深长地笑了笑。\n",
        	"帮助":		(: do_help :),
        	"大事":		(: do_help :),
        	"job":		(: do_help :),
        	"回报":		(: do_cont :),	
   		]));
   		
    	set("chat_chance",1);
    	set("chat_msg",({
			"武三爷微笑道：“你有鉴赏力，你是个聪明人。不过，聪明人都不长命。”\n",
			"武三爷点点头叹息着道：女人总是比较多疑的，尤其是李大娘这个女人，她一直都\n认为我要杀了她。”\n",
    	}) );
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		 (: auto_smart_fight(40) :),
        }) );
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","dragonstrike",1);
		setup(); 
    	set_skill("yijinjing",200);
    	set_skill("iron-cloth",200);
    	map_skill("iron-cloth","yijinjing");
    	carry_object(__DIR__"obj/bluecloth2")->wear();  
}


void init() {
	
	object ob;
	::init();
	add_action("do_answer","answer");
	if( interactive(ob = this_player()) && REWARD_D->riddle_check(ob,"喋血鹦鹉")==8) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment()) return;
	
	tell_object(ob,CYN"
武三爷手中捏着酒杯，满满的一杯酒，碧绿芬芳，已在唇边。

武三爷的目光落在你的面上，淡淡地说：很好，我正在等你，

因为你需要我的"YEL"帮助"CYN"，

除了我谁也帮不了你，常笑不能，安子豪也不能。\n\n"NOR);
	if (REWARD_D->riddle_check(ob,"喋血鹦鹉")==8)
		REWARD_D->riddle_set(ob,"喋血鹦鹉",9);
	return;
}
		
	
int do_cont(){
	
	object me;
	
	me = this_player();
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")!=12 && !me->query("marks/quest/李家庄"))
		return 0;
	
	if (me->query("marks/quest/李家庄")==1){
		command("say 还不快去，事成后速来"YEL"回报"CYN"!");
		return 1;
	}
	
	if (me->query("marks/quest/李家庄")==2) {
		QUESTS_D->special_reward(me,"攻打李家庄");
		me->delete("marks/quest/李家庄");
	}
	
	
	tell_object(me,CYN"武三爷眯起眼睛说：很好、很好。
武三爷说：攻打庄门其实是个幌子，目的是引开李家庄的注意力，这也足以看出
你是个守信之人。如今李三娘大势已去，你可从趁其左右逢敌之时，从庄后潜入，
杀她个措手不及！左三右五左七，可开李家庄后铁门，切记切记。\n"NOR);

	if (REWARD_D->riddle_check(me,"喋血鹦鹉")==12) 
		REWARD_D->riddle_set(me,"喋血鹦鹉",13);
	
	REWARD_D->riddle_done(me,"喋血李家庄",20,1);		// 从此可进入
	
	return 1;
}


	
	
	

	
		

int do_help() {
	
	int pass;
	object me;
	
	me = this_player();
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")==10 || REWARD_D->riddle_check(me,"喋血鹦鹉")==11
		|| me->query("quest/quest")== "攻打李家庄") {
		tell_object(me,CYN"
武三爷说：今日便是攻打李家庄的大好时机，我已尽遣高手将李大娘团团围住。
只是李家庄墙高壁严，正门更是防范森严，我需要像你这样的高手前去助阵。
记住，只需将守卫扫除干净，便可"YEL"回报"CYN"于我，剩下的让我手下去清理！\n"NOR);
		if (REWARD_D->riddle_check(me,"喋血鹦鹉")==10)
			REWARD_D->riddle_set(me,"喋血鹦鹉",11);
		if (me->query("quest/quest")=="攻打李家庄")
		{
			if (me->query("marks/quest/李家庄")!=1)
				me->set("marks/quest/李家庄",1);
			else
				command("say 还不快去，事成后速来"YEL"回报"CYN"!");
		}
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")==9) {
		tell_object(me,CYN"
武三爷用他那似乎能洞察一切的目光看着你：这太平镇上每一个人的行踪，我
不知道的还不多，安子豪的那些计划，也都在我的掌握之中，他所图的是什么
难道你还看不出来？

武三爷捧起金杯又浅浅抿了一口道：你到这里来才半天，已有多少人要杀你？
若是你破获了此案，你还能活着离开这个镇子么。

武三爷笑笑说：据我所知，这案子的关键，就着落在李大娘身上，她才是你真
正的对手。我要的，只是这个镇子，所以你我没有冲突，只有共同的敌人。既
然她要杀你我，杀了她，岂非本就是天经地义的事？

武三爷慢慢的接着道：我可以把她住所的环境，埋伏的暗卡，她的起居时刻，
生活习惯尽都告诉你，你是否要我帮这个忙？\n"NOR,this_object());
		me->set_temp("marks/parrot/answer_sanye",1);
		return 1;
	}
	
	
	command("say 什么？我若有事，自然会去找你。");
	return 1;
}



int do_answer(string arg)
{
	object me,key;
	int i, gotit;
	
	me=this_player();
	if(!me->query_temp("marks/parrot/answer_sanye")) return 0;
		
	if(arg=="yes" || arg == "要" || arg == "sure" || arg == "好" ){
		tell_object(me, CYN"武三爷呵呵一笑，俯身在你耳边说：果然是个明白人！
既是如此，你我协力对付李大娘，这眼前就有一件"YEL"大事"CYN"。\n"NOR);
		me->delete_temp("marks/parrot/answer_sanye");
		me->delete_temp("marks/parrot/reject_sanye");
		REWARD_D->riddle_set(me,"喋血鹦鹉",10);
		return 1;	
	}
	
	if(arg=="no" || arg == "不要"){
		tell_object(me,CYN"武三爷迟疑一下道：我仍希望你好好的再考虑一下。\n"NOR);
		me->set_temp("marks/parrot/reject_sanye",1);
		me->delete_temp("marks/parrot/answer_sanye");
		return 1;
    }
    
	return 0;
	
}