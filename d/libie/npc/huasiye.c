
#include <ansi.h>

inherit NPC;

int answer_self();
int answer_qinglong();
int answer_di();

void create()
{
        set_name("花四爷", ({ "hua siye","hua","siye" }) );
        set("long","
花四爷生前是洛阳首富，生得高大、肥壮。胖嘟嘟的一张脸上透着诚恳、
热心，似乎连一点机诈都没有。但此刻，他的鬼魂的脸上却布满了戾气，
令人感到不寒而栗。\n");

        set("attitude", "friendly");
        set("title", "花开富贵");
	set("age",53);
        set("agi", 60);
	set("class","wudang");
	
        set("combat_exp", 4000000+random(500000));
	
	set_skill("unarmed",200);
	set_skill("taiji",200);
	set_skill("parry",400);
	set_skill("dodge",400);
	set_skill("five-steps",150);
	map_skill("unarmed","taiji");
	map_skill("dodge","five-steps");
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"花四爷凄惨的声音在你耳边回荡：....我花四死的好惨啊....\n"
	}) );

        set("inquiry", ([
                "杨铮" : 	"杨铮是这儿的捕头，据说他监守自盗，偷了一百八十万两镖银。\n",
                "yang" :  	"杨铮是这儿的捕头，据说他监守自盗，偷了一百八十万两镖银。\n",
                "yang zheng" : 	"杨铮是这儿的捕头，据说他监守自盗，偷了一百八十万两镖银。\n",
                "狄青麟" : 	(: answer_di :),
                "di qinglin" :  (: answer_di :),
                "青龙会":	"青龙会是一个极庞大的秘密组织，四百年来，江湖中从来未有过比
青龙会更庞大严密的组织。 \n",
		"天青如水":	(:answer_qinglong:), 
		"飞龙在天":	(:answer_qinglong:),
		"正月初三":	(: answer_self :),
		"天青如水，飞龙在天":	(:answer_qinglong:),
		"四月堂":	"看来你还是下了一番功夫，但冒冒失失，老子岂能信你？\n",
		"三月堂":	"看来你还是下了一番功夫，但冒冒失失，老子岂能信你？\n",
        ]));

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: perform_action("unarmed.nianzijue") :),
        }) );


        setup();

        carry_object("/obj/armor/cloth")->wear();
}

int is_ghost() { return 1; }


int answer_qinglong(){
	object me= this_player();
	
	if (!me->query_temp("libie/friend_hua"))
		message_vision("花四爷脸色大变道：天青如水，飞龙在天，你、你是总舵的什么人？\n",me);
	else
		message_vision("花四爷恨恨地说：一定要替我报了这血海深仇！\n",me);
	me->set_temp("libie/qinglong_hua",1);
	return 1;
}


int answer_self(){
	
	object me = this_player();
	
	if (!me->query_temp("libie/qinglong_hua") || !me->query("libie/huzi"))
	{
		command("say 正月初三？还十五呢，老子现在过的是没月份的日子！\n");
		return 1;
	}
	
	tell_object(me, "花四爷道：好，既然你知我代号，应是总舵之人！\n");
	tell_object(me,"花四爷恨恨地说：狄青麟，狄青麟这个叛逆，千万不能放过他。\n");
	me->set_temp("libie/friend_hua",1);
	return 1;
}
		
	
	
int answer_di()
{
	object me;
	string msg;
	
	me=this_player();
    	if (!me->query_temp("libie/friend_hua"))
    	{
    		msg= "花四爷怨毒地说：狄青麟为人阴狠，切不可轻信于他，切记切记。\n";
    		tell_object(me, msg);
    		return 1;
    	}
    	msg = "
花四爷恨恨地说：此事说来话长，狄青麟、我和老裘奉龙头之命，夺了镖银再让
杨铮背上个大黑锅，总舵的小青传命要我俩再做了狄青麟，没想到狄青麟这小子
心狠手辣又诡计多端，不仅杀了小青，连我也死于非命，我攒了一辈子的钱，这
么走了不甘心呀！！！\n";
	tell_object(me,msg);
    	me->set_temp("libie/di_2",1);
	return 1;
}
