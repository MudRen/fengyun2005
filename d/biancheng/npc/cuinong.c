#include <ansi.h>
inherit SMART_NPC;

int fu();
int do_answer(string arg);

void create()
{
    	set_name("翠浓",({"cuinong"}));
	   	set("long","
她长得也许并不算太美，但却有双会说话的眼睛，灵巧的嘴。她虽然只是静静
地坐在那里，但却自然地有种醉人的风姿和气质。一个这样的女人，无论对任
何男人来说都已足够。\n");
     	set("gender","女性");
    	set("age",22);
    	 	
    	set("per",4);
    	    	
    	set("inquiry", ([
        	"傅红雪" :		(: fu() :),
        	"fu hongxue" :	(: fu() :),	
        	"等待"	: 	"等。。他会回来么？\n",
        	"等"	: 	"等。。他会回来么？\n",
        	"他":		"action翠浓咬着嘴唇说，他、他就是傅红雪。\n",
        	"很远的地方":	"我也不是很清楚，只知道他在新疆的什么地方。\n",
    	         	
   		]));
    	
    	set("combat_exp",400000);  
    	set("attitude", "friendly");
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"翠浓怔怔地望着窗外，似乎在等待着什么人的来到。\n",
			"翠浓垂下头，道：“你……你几时要我等过你？”\n", 
    	}) );    	    	
    		
		setup();
    	carry_object("/obj/armor/cloth",([	
    						"name":  HIR"红线袄"NOR,
    						"long": "一件大红丝绸的棉袄，俗气的很。\n",
    						 ]))->wear();    
    
}


void init(){
	::init();
	add_action("do_answer","answer");
}

int fu (){
	object me, ob;
	string msg, gender;
	int stage;
	
	me = this_player();
	ob = this_object();
	stage = REWARD_D->riddle_check(me,"情深似海");
	
	if (!stage)
	{
		message_vision(CYN"翠浓眼睛里又有了泪光：他走了，去了很远的地方。。。\n"NOR, me);
		gender = (me->query("gender")== "男性")?"爷":"娘";
		message_vision(CYN"翠浓咬着嘴唇说：大"+ gender +"来是找乐子的，问那么多干嘛呢。\n"NOR, me);
		command("say 你又没见过他，哪儿能帮得了我呢？");
		return 1;
	}
	
	if (stage == 1 || stage == 2) {
		message_vision(CYN"
一连串晶莹如珠的眼泪，从翠浓美丽的眼睛里滚下来，她身子开始颤抖，
似已连站都站不住。

那时我以为他讨厌我，看不起我，我以为他根本不想要我。但现在我才知道，
他是真心喜欢我的，以前他对我那种样子，只不过因为他天生的怪脾气。
何况……这些天来他过的是什么日子，我也知道。

翠浓流着泪道：现在我也明白，只要他是真心喜欢我，我也真心喜欢他，其
他的事全不重要，你，请你去告诉他，"YEL"他若因我而死了，我也不会活下去。\n"NOR,ob);
		me->set_temp("marks/fuhong_ask",1);		// put this here, in case player relogin after this.
		REWARD_D->riddle_set(me,"情深似海",2);
		return 1;
	}
	if (stage == 3) {
		message_vision("翠浓流着泪说：他、他说什么了么？\n",me);
		return 1;
	}
	return 0;
}


int do_answer(string arg){
	int stage;
	object me;
	
	me = this_player();
	stage = REWARD_D->riddle_check(me,"情深似海");
	
	if(stage == 3)
	if ( arg == "将过去的事情忘记！"|| arg== "将过去的事情忘记") {
			message_vision(CYN"
翠浓说：他、他真的这么说？我会等他的，无论要多久，无论他在哪里。
翠浓的泪珠又一连串流下来，但这已是幸福快乐的泪珠，这种泪珠比珍珠还珍贵。\n"NOR,me);
					
			REWARD_D->riddle_done(me, "情深似海",20, 1);	
			
			if (!me->query("marks/e_wanma/情深似海")){
				me->set("marks/e_wanma/情深似海",1);
				tell_object(me,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
			}
			
			QUESTS_D->special_reward(me,"情深似海");
			
			return 1;
	}
	return 0;
}
