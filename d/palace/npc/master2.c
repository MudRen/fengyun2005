#include <ansi.h>
#include <combat.h>

inherit NPC;
inherit F_MASTER;

int testing(object me);
void check_answer(object me);
void check_accept(object me);

void create()
{
    	set_name("蓝天锤", ({ "master lan", "lan","master" }) );
    	set("gender", "男性" );
    	set("nickname",HIB "蓝大先生" NOR);
    
    	set("reward_npc", 1);
    	set("difficulty", 2);
    
    	set("age", 45);

    	set("class","yinshi");
    	set("skill_public",1);
    
    	set("combat_exp", 2000000);
    	set("score", 90000);
    	
    	set("apprentice_available", 50);
/*    	create_family("天锤山庄", 1, "庄主");
    	set("rank_nogen",1);
    	set("ranks",({"弟子","小侠","少侠","大侠","奇侠","狂侠","侠圣","隐侠"})); */
    	
    	create_family("帝王谷", 1, "谷主");
    	set("rank_nogen",1);
    	set("ranks",({ "弟子","领班","小管家","管家","大管家",
                        CYN"隐者"NOR,CYN"隐士"NOR,HIC"侠隐"NOR }));;
		set("title", "天锤山庄　庄主");
    
    	set("long", "
蓝天锤的一柄大锤用的出神入化，每年都和帝王谷主绝顶大战，至今胜负不分。 
蓝天锤的脾气爆如烈火，经常无缘无故的将弟子打成死伤或逐出墙门。\n");  	
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"蓝天锤笑骂道：这个箫老儿，又和他不分胜负。\n",
         }) );
        	
    	set_skill("unarmed", 160);
    	set_skill("hammer", 200);
    	set_skill("force", 160);
    	set_skill("parry", 160);
        set_skill("dodge", 160);
		set_skill("pangu-hammer", 150);
    	set_skill("flying-dragon", 200);
    	set_skill("zuixian-steps", 200);
    	set_skill("magic",150);
    	set_skill("iceheart", 150);
    	set_skill("qiankunwuxing",200);
    	set_skill("move",200);
    
    	map_skill("unarmed", "flying-dragon");
    	map_skill("hammer", "pangu-hammer");
    	map_skill("force", "iceheart");
    	map_skill("parry", "pangu-hammer");
    	map_skill("dodge", "zuixian-steps");
    	map_skill("magic","qiankunwuxing");
    
    
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        	(: perform_action, "hammer.kaitianpidi" :),
		}) );

    	setup();
    	carry_object(__DIR__"obj/bluecloth")->wear();
    	carry_object(__DIR__"obj/jumbohammer")->wield();
}


void init()
{
	add_action("do_challenge","challenge");
	add_action("do_challenge","tiaozhan");
	add_action("do_answer","answer");
	::init();
}

int prevent_learn(object me, string skill)
{
  	if (skill != "magic" && skill!="qiankunwuxing")
  	{
      		command("shake");
      		command("say 我只是体萧老儿指点你几手罢了，又没真收你当徒弟。");
      		return 1;
  	}
  	return 0;
}

int prevent_shown(object me, string skill)
{
	if (skill == "magic" || skill == "qiankunwuxing")
		return 0;
	
	return 1;
}

void attempt_apprentice(object ob)
{

	if (ob->query("class")=="yinshi")
	{
	 	if (REWARD_D->riddle_check(ob,"天锤之战"))
	 	{
	 		command("say 要打就打，打不过就滚，罗嗦什么！");
	 		return;
	 	}
		if (REWARD_D->check_m_success(ob,"天锤之战"))
		{
			command("say 好徒儿，你已经证明你自己了。");
			return;
		}
		call_out("do_recruit",2,ob);
	}
	else
		message_vision(WHT"$N摇了摇头，说道：“我没有心思收徒呢。”\n"NOR,this_object());
   
}


void do_recruit(object ob)
{
	 if (ob && present(ob,environment()))
	 {
	 	message_vision(WHT"$N上上下下看了看$n，忽然哈哈大笑起来：“你不是箫老儿的徒弟吗？ 
怎么，你师父的道行你看不上眼了吗？”(answer no/yes) \n"NOR,this_object(),ob);
			//add_action("do_answer","answer");
		ob->set_temp("answering_lan",1);
		call_out("check_answer",40,ob);
	 }
}

void check_answer(object me)
{
	if (me)
	{
		me->delete_temp("answering_lan");
		if (present(me,environment()))
		{
			message_vision("$N对$n不耐烦道：“大丈夫，有一说一，有二说二，婆婆妈妈做什么。”\n",this_object(),me);
			message_vision("$N扭过头不再理$n。\n",this_object(),me);
		}

	}
}

int do_answer(string arg)
{
	object me;
	me=this_player();
	
	if(!me->query_temp("answering_lan"))
		return 0;
	if (arg !="yes" && arg !="no")
	{
		return notify_fail("你只可答yes/no");
	}

	remove_call_out("check_answer");
	me->delete_temp("answering_lan");
	if (arg == "yes")
	{
		message_vision(WHT"$N笑得更得意了：“那你就拜我为师吧！再见到箫老儿，我得好好羞羞他，
连徒弟都拢不住了！” \n"NOR,this_object());
	}
	if (arg == "no")
	{
		message_vision( WHT"$N双目炯炯盯着$n：“箫老儿的徒弟也有这份骨气？嗯。。。 
你代我约战(challenge)你师傅，我就教你两手！”(accept yes/no) \n"NOR,this_object(),me );
		add_action("do_accept","accept");
		me->set_temp("accepting_lan",1);
		call_out("check_accept",40,me);
	}
	return 1;
}

void check_accept(object me)
{
	if (me)
	{
		delete_temp("accepting_lan");
		if (present(me,environment()))
		{
			message_vision("$N对$n挥挥手，道：“不愿意就算了。”\n",this_object(),me);
		}
	}
}

int do_accept(string arg)
{
	object me;
	me = this_player();
	if(!me->query_temp("accepting_lan"))
		return 0;
	if (arg !="yes" && arg !="no")
	{
		return notify_fail("你只可接受yes/no");
	}
	remove_call_out("check_accept");
	me->delete_temp("accepting_lan");
	if (arg == "yes")
	{
		message_vision(WHT"$N点点头，说到：“好，我就在这里等他” \n"NOR,this_object());
		REWARD_D->riddle_set(me,"天锤之战", 1);		
	}
	if (arg == "no")
	{
		message_vision(HIW"$N正色道：“以为师之尊，如何能与你这等山野村民交战。这事我万万不能答应。”\n"NOR,me);
	}
	return 1;
}


int recognize_apprentice(object ob)
{
    if( (string) ob->query("class") == "yinshi" 
    	&& REWARD_D->check_m_success( ob,"天锤之战"))	
   // 	&& ob->query("marks/master_lan"))
	        return 1;
	return 0;
}

int do_challenge(string arg)
{
	object me;
	me = this_player();

	if (arg != "master" && arg != "master lan" && arg != "蓝天锤" && arg != "lan")
	{
		return 0;
	}
	
	if (REWARD_D->check_m_success(me,"天锤之战"))
	{
		command("say 好徒儿，你已经证明你自己了。");
		return 1;
	}
	
	if ( REWARD_D->riddle_check( me,"天锤之战") != 2
		|| (string) me->query("class") != "yinshi")
	{
		message_vision(WHT"$N不屑一顾对$n说道：“你是什么东西，要老夫出手？” \n"NOR,this_object(),me);
		return 1;
	}
	
	message_vision(HIG"$n对$N朗声道："+RANK_D->query_self(me) + me->name() + "愿代师出战。\n"NOR,this_object(),me);
	
	
	if((int)me->query("marks/failed_lan") + 10800 > time())
    	{
        	command("say 你不久前才输给我！过两天再比吧！");
        	return 1;
    	}
	
	if (this_object()->is_fighting() || this_object()->is_busy())
		command("say 我现在正忙，等会吧。。。");
		
	if (!me->query_temp("marks/fight_lan"))
	{
		message_vision(HIW"$N惊异的对$n说道：“怎么是你。。。也好，接招吧！” \n"NOR,this_object(),me);
	}else
	{
		message_vision(HIW"$N对$n大喝一声：“好，招到！” \n"NOR,this_object(),me);
	}
	testing(me);	
	return 1;	
}


int testing(object me)
{
 	object weapon/*,skl*/;
    	if (this_object()->is_fighting() || this_object()->is_busy())
		command("say 我现在正忙，等会吧。。。");

    me->set_temp("marks/fight_lan",1);
	delete_temp("last_damage_from");
    full_me();
	weapon =me->query_temp("weapon");  

	COMBAT_D->do_attack(me,this_object(),TYPE_PERFORM);
	say(HIR"\n蓝大先生说道：第一招．．．．\n"NOR);
    if(query_temp("last_damage_from") == me)
    {
		if(!weapon 
			||weapon->query("skill_type")!="whip"
			||me->query_skill_mapped("whip")!="thunderwhip")
		{
			say("\n蓝大先生喃喃道：“原来这世上还有这么厉害的武功。。。” \n");
			say("\n蓝大先生心灰意冷的叹了口气。 \n");
		}else
		{
			command("say 天雷破果然名不虚传，不过我的武功却恰恰能克制它，想学的话，我就教你。");
	        me->delete("marks/failed_lan");
			REWARD_D->riddle_done( me,"天锤之战",50,1);	
		}
		return 1;
    }
	
    	
    COMBAT_D->do_attack(me,this_object(),TYPE_PERFORM);
	say(HIR"\n蓝大先生说道：第二招．．．．\n"NOR);
	if(query_temp("last_damage_from") == me)
	{
		if(!weapon ||weapon->query("skill_type")!="whip"||
			me->query_skill_mapped("whip")!="thunderwhip")
		{
			say("\n蓝大先生喃喃道：“原来这世上还有这么厉害的武功。。。” \n");
			say("\n蓝大先生心灰意冷的叹了口气。 \n");
		}else
		{
			command("say 天雷破果然名不虚传，不过我的武功却恰恰能克制它，想学的话，我就教你。");
	        me->delete("marks/failed_lan");
	        REWARD_D->riddle_done( me,"天锤之战",50,1);
			
		}
		return 1;
	}


    COMBAT_D->do_attack(me,this_object(),TYPE_PERFORM);
	say(HIR"\n蓝大先生说道：第三招．．．．\n"NOR);
	if(query_temp("last_damage_from") == me)
	{
		if(!weapon ||weapon->query("skill_type")!="whip"||me->query_skill_mapped("whip")!="thunderwhip")
		{
			say("\n蓝大先生喃喃道：“原来这世上还有这么厉害的武功。。。” \n");
			say("\n蓝大先生心灰意冷的叹了口气。 \n");
		}else
		{
			command("say 天雷破果然名不虚传，不过我的武功却恰恰能克制它，想学的话，我就教你。");
	        me->delete("marks/failed_lan");
	        REWARD_D->riddle_done( me,"天锤之战",50,1);
			
		}
		return 1;
	}
	
	me->set("marks/failed_lan",time());
	if(!weapon ||weapon->query("skill_type")!="whip"
		||me->query_skill_mapped("whip")!="thunderwhip")
	{
		say("\n蓝大先生摇了摇头，说道：“普天下只有天雷破可以和我的锤法抗衡。” \n");			
	}else
	{
		command("shake");
		command("say 你的武功太差，不要来自讨苦吃了。等练好了再来吧。");
	}
	return 1;
}

