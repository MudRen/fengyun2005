inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_challenge();
int leave();

void create()
{
    	set_name("箫王孙", ({ "master xiao", "xiao","master" }) );
    	set("gender", "男性" );
    	set("nickname",HIY "黄衣客" NOR);
    	set("reward_npc", 1);
    	set("difficulty", 15);
    
    	set("age", 45);
    	set("per", 30);
    	set("attitude","friendly");
    	set("class","yinshi");
    	set("apprentice_available", 50);
    	create_family("帝王谷", 1, "谷主");
    	set("rank_nogen",1);
		set("ranks",({ "书童","箫童","酒童","书生","箫客","酒痴",
			"隐士","儒侠","箫侠","醉侠","隐侠","侠隐",CYN"儒帝"NOR,
			CYN"箫帝"NOR,CYN"酒帝"NOR,HIC"布衣帝王"NOR}));
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
					
    	set("long","箫王孙的来历没有任何人知道，也没有人敢打听。\n" );
    
    	set("combat_exp", 20000000);
    	set("score", 90000);
    	set("guard_msg","$N喝道：帝王谷的人，容不得阁下来管教！\n");
    	set_temp("apply/haste",400);
    	
    	set_skill("move",200);
    	set_skill("perception", 190);
    	set_skill("foreknowledge", 180);
    	
    	set_skill("flying-dragon", 200);
    	set_skill("unarmed",160);
    	set_skill("thunderwhip", 200);
    	set_skill("whip", 200);
    	set_skill("force", 160);
    	set_skill("parry", 160);
    	set_skill("literate", 100);
    	set_skill("zuixian-steps", 200);
    	set_skill("dodge", 160);
    	set_skill("chanting",100);
    	set_skill("cursism",200);
    	set_skill("celecurse",200);
    	set_skill("iceheart", 150);
    	
    
    	map_skill("cursism","celecurse");
    	map_skill("unarmed", "flying-dragon");
    	map_skill("whip", "thunderwhip");
    	map_skill("force", "iceheart");
    	map_skill("parry", "thunderwhip");
    	map_skill("dodge", "zuixian-steps");
	
	set("inquiry",([
        	"challenge" : 	(: ask_challenge :),
        	"挑战": 	(: ask_challenge :),
			"tiaozhan": 	(: ask_challenge :),
			"蓝天锤" : 	(: ask_challenge :),
			"master lan" : 	(: ask_challenge :),
			"leave" : 	(: leave :),
    	]) );
    	
    	set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
        		(: perform_action, "whip.yunlongjiuxian" :),
        }) );
    
    	setup();
    	carry_object(__DIR__"obj/shenxue")->wear();
    	carry_object(__DIR__"obj/baojia")->wear();
    	carry_object(__DIR__"obj/zhiai")->wear();
    	carry_object(__DIR__"obj/sidai")->wield();
}


void reset()
{
    	delete_temp("learned");
}

void attempt_apprentice(object ob)
{
	if((int) ob->query_temp("wait_time") < 360)    {
        	command("think");
        	command("say 你心不诚．．．\n");
        	ob->set_temp("xiao_failed",1);
	return;
    }
    else {
		command("smile");
       	command("say 你日后必有大成！");
       	command("smile");
       	command("recruit " + ob->query("id") );
    }
}

int ask_challenge()
{
	object me;
	me = this_player();
	if ( me->query("class") == "yinshi" 
		&& REWARD_D->riddle_check(me,"天锤之战") == 1)
	{	
		command("say 蓝老儿还不死心吗？"NOR);
		if (me->query("level")>= 50)
		{
			REWARD_D->riddle_set(me,"天锤之战",2);
			message_vision(CYN"$N淡淡的对$n说：“你学业有成，那么就替为师走一遭吧。用天雷破试试蓝天锤
的盘古九式(challenge master lan).”\n"NOR,this_object(),me);
		}else
		{
			message_vision(CYN"$N笑道：“蓝老儿的锤法不堪一击，只可惜你火候未到，不能代为师教训他。。。”\n "NOR,this_object());
			tell_object( me,WHT"（需等级50）\n"NOR);
		}
		return 1;
	}
	if (REWARD_D->check_m_success(me,"天锤之战"))	{
		command("say 好徒儿，为师也脸上有光！");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"天锤之战")==2) {
		command("say 徒儿，还不快去挑战那蓝大！");
		return 1;
	}
	
	return 0;
}

void init()
{	
	::init();
	add_action("do_killing", "kill");

}

int leave() {
	if (this_player()->query("class")!="yinshi") return 0;
	message_vision(CYN"$N道，“我不勉强你留下。“\n"NOR, this_object());
	message_vision(CYN"$N说：只是这通天降太为险恶，不能落在外人手里。\n"NOR,this_object());
	return 1;
}