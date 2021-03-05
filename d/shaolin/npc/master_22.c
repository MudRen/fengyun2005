inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int kill_him();
int jian();

void create()
{
    	set_name("圆灭", ({ "master yuan", "master"}) );
    	set("nickname", HIG "茫为" NOR);
    	set("vendetta_mark","shaolin");
    	set("gender", "男性" );
    	set("reward_npc", 1);
    	set("difficulty", 1);
    	
    	set("class","shaolin");
    
    	set("age", 64);
    	
    	set("attitude","friendly");
        set("long","少林第二十二代的师傅，他专门传授少林俗家弟子武功。\n想要"YEL"见方丈"NOR"，先得他同意才行。");
    	set("guard_msg","$N对$n喝道：阿弥陀佛,佛门清静之地,岂可妄起杀心?施主请恕老衲得罪了！\n"NOR);
    	create_family("少林寺", 22, "长老");
    	    	set("rank_nogen",1);
    	set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({"沙弥","僧人","罗汉","金刚","上人","高僧","大师",
		"长老","法堂长老","戒律院长老","法堂首座","戒律院首座",
		YEL"长老院首座"NOR,YEL"副主持"NOR,YEL"禅宗传人"NOR,HIY"禅宗宗主"NOR}));
		
    	set("combat_exp", 500000);
    
    	set("chat_chance_combat", 30);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.qianshouqianbian" :)
    	}) );
    	
    	set_skill("move", 90);
    	set_skill("dodge", 90);
    	set_skill("force", 90);
    	set_skill("literate", 100);
    	set_skill("unarmed",90);
    	set_skill("puti-steps",90);
    	set_skill("dabei-strike",90);
    	set_skill("zen",60);
    	set_skill("chanting",90);
    	set_skill("xiaochengforce",90);
    	set_skill("parry",90);
    	set_skill("foreknowledge",90);
		set_skill("perception",90);
		set_skill("hammer",100);    	
    	set_skill("liuxing-hammer",100);
    	set_skill("lianxin-blade",130);
    	set_skill("blade", 130);
    	set_skill("staff", 100);
    	set_skill("fumostaff",100);
    	    	
    	map_skill("blade", "lianxin-blade");
    	map_skill("staff","fumostaff");
    	map_skill("parry","fumostaff");
    	map_skill("dodge", "puti-steps");
    	map_skill("force", "xiaochengforce");
    	map_skill("unarmed", "dabei-strike");
    
    	set("inquiry", ([
        	"见方丈": (: jian()  :),
        	"master": (: jian()  :),
        ]) );
    	setup();
    	carry_object(__DIR__"obj/monk22_cloth")->wear();
    	carry_object(__DIR__"obj/staff")->wield();

}

void attempt_apprentice(object me)
{
    	if(me->query_temp("won_master_kong"))
    	{
		command("smile");
        	command("recruit " + me->query("id") );
        	return;
    	}
    	else
    	{
		command("shake");
    	}
}

int accept_fight(object me)
{
        if( is_fighting() )
		command("say 想倚多为胜？去找寺内的棍僧较量吧！\n");
		
        if(me->query("family/family_name") == query("family/family_name") &&
	   	me->query("family/master_id") == query("id"))
        {
        	if( query("gin") * 100 / query("max_gin") >= 90
			&& query("kee") * 100 / query("max_kee") >= 90
			&& query("sen") * 100 / query("max_sen") >= 90 )
		{
              	if (me->query_skill("zen",1) >= 60) {
        			command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
           			me->set_temp("marks/fi_m_22",1);
           			return 1;
        		
        		}
        		command("say 徒儿，你的禅道修为太浅，光练武可不行啊！\n");	
        		tell_object(me,"（需60级禅道）\n");	// 148k
        			
        } else
        		command("say 好，不过，让老衲喘口气再来。\n");
        }	
        else
        {
        	command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        	return 0;
        }
}

void win_enemy(object loser)
{
    	if (loser->query_temp("marks/fi_m_22")) {
    		command("say 阿弥陀佛！徒儿还要努力呀！\n");
    		loser->delete_temp("marks/fi_m_22");
    	}
}

void lose_enemy(object winner)
{
    	if (winner->query_temp("marks/fi_m_22")) {
    		command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
    		winner->set_temp("won_master_yuan",1);
    		winner->delete_temp("marks/fi_m_22");
    	}
}

void init() {
    	::init();
	add_action("do_killing", "kill");
    	add_action("do_answer","answer");
}


int jian() {
	object me;
	me=this_player();
	command("say 想见方丈....嗯....你有什么事吗？（answer）");
	me->set_temp("shaolin/ask_yuan",1);
	return 1;
}

int do_answer(string arg)
{
	object me = this_player();
	if (!this_player()->query_temp("shaolin/ask_yuan"))
	{
		command("say "+arg+"？施主是在跟贫僧说话么？");
		return 1;
	}
	if (!REWARD_D->riddle_check(me,"多事之秋") && !REWARD_D->check_m_success(me,"多事之秋")) 
	{
		command("say "+arg+"？施主是在跟贫僧说话么？");
		return 1;
	}
	if(arg == "重要事" || arg =="emergency")
	{
		command("consider");
		command("say 什么重要事？山下的天机施主又派人来造孽不成？");
		return 1;
	}
	if(arg == "经书被盗")
	{
		command("say 好，方丈南院向北，你去吧！");
		this_player()->delete_temp("shaolin/ask_yuan");        	
		this_player()->set_temp("see_fangzhang",1);
		return 1;
	}
	command("dunno");
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


