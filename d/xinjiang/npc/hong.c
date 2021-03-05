inherit NPC;
#include <ansi.h>

int startit();
int do_answer(string arg);

void create()
{
        set_name("傅红雪", ({ "hongxue", "fu hongxue", "fu hong xue" }) );
        set("gender", "男性" );
        set("age", 24);
        set("title","带黑刀的人");
		set("attitude","friendly");
        
        set("reward_npc", 1);
		set("difficulty", 5);
        
        set("long","傅红雪的手里握着刀，一柄形状很奇特的刀，刀鞘漆黑，刀柄漆黑。
无论他在作什么的时候都没有放过这柄刀。\n");

        set("combat_exp",4000000);
        set("score", 1000);
	
	
		set("inquiry", ([
        	"翠浓" :	(: startit() :),	
        	"cuinong" :	(: startit() :),	
        	"cui nong" :	(: startit() :),	
        	"*":		(: message_vision("傅红雪一杯一杯地喝着酒，似乎没有听到你的话。\n",this_object()) :),
   		]));
   		
        set("chat_chance", 1);
        set("chat_msg", ({
                "傅红雪再喝，再醉。醉了又醒，醒了又醉。尊严、勇气、力量，全部已倾入樽中。\n",
                "傅红雪握刀的苍白的手，却似已有些颤抖！\n",
        }) );
        
        set_skill("move", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("blade", 300);
        set_skill("shortsong-blade",160);
        set_skill("fengyu-piaoxiang",200);
        set_skill("meihua-shou",200);
        set_skill("unarmed",200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","shortsong-blade");
        map_skill("blade","shortsong-blade");
        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
		if (!random(10)) carry_object(__DIR__"obj/fbblade")->wield();
		else carry_object(__DIR__"obj/bblade")->wield();
}

void init(){
	::init();
	add_action("do_answer","answer");
}


int startit() {
	object me = this_player();
	int stage;
	
	stage = REWARD_D->riddle_check(me,"情深似海");
	
	if (!stage || stage == 1)	{
		command("say 你……你……你知道她……她的下落吗？");
		tell_object(me,"（answer 某内容）：这是风云中解谜中常用的命令\n");
		if (!REWARD_D->riddle_check(me,"情深似海"))
			REWARD_D->riddle_set(me,"情深似海",1);
		me->set_temp("marks/fuhong_ask",1);
		return 1;
	}
	
	if (stage == 2)
		command("say 翠浓、翠浓说了些什么？");
	else if (stage == 3)
		command("say 快去，快去找翠浓。");
	
	return 1;
		
}


int do_answer(string arg){
	int stage;
	object me;
	
	me = this_player();
	stage = REWARD_D->riddle_check(me,"情深似海");
	
	if (!me->query_temp("marks/fuhong_ask")) {
		message_vision("傅红雪疯狂般瞪着$N，紧紧握着他的刀。刀并没有拔出来，泪却已流下。\n",me);
		command("say 你……不用说了，我知道……她走了，是跟别人一起走的。");
		if (!REWARD_D->riddle_check(me,"情深似海"))
			REWARD_D->riddle_set(me,"情深似海",1);
//		me->delete_temp("marks/fuhong_ask");
		return 1;
	}
	
	switch (stage) {
		case 0:
		case 1:		tell_object(me,"傅红雪一杯一杯地喝着酒，似乎没有听到你的话。\n");
					break;
		case 2:		
		case 3:		if ( arg == "他若因我而死了，我也不会活下去。" 
						|| arg == "他若因我而死了，我也不会活下去") {
						message_vision(CYN"
一瞬间，傅红雪的人完全变了。他的心本是紧紧收缩着的，就像是一团被
人揉在掌心的纸。现在他的心已开展。他的态度忽然又变得充满了自信，
因为他已知道他所爱的人并没有背叛他，他握刀的手又变得出奇的镇定。"CYN"

傅红雪说：请你去告诉她，不管你怎么样，都已经是过去的事了，让我们
"YEL"将过去的事情忘记！\n"NOR,me);
						REWARD_D->riddle_set(me,"情深似海",3);
					} else
						tell_object(me,"傅红雪用一种奇怪的眼神看着你，似乎在看一个疯子。\n");
					break;
	}
	return 1;
}