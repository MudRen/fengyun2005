inherit SMART_NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();
int jice();

void create()
{
    	set_name("老刀把子", ({ "master lao dao", "master"}) );
    	set("gender", "男性" );
    	set("class","wudang");
    	set("long", "他身穿灰袍，头戴竹笠，就象个有形无质的鬼魂。\n" );
    	set("age", 45);

    	set("per", 30);
    	set("reward_npc", 1);
    	set("difficulty", 25);
    	set("fly_target",1);
    
    	create_family("幽灵山庄", 1, "庄主");
    	
    	set("inquiry", ([
        	"两仪心法":  "两仪心法乃我数十年闭关修炼所得，其[如封似闭]乃武林一绝。\n",
        	"如封似闭":  "此诀的妙处在于无论是空手或执刃，无论是用何种武功，都可以使用。\n",
        	"石雁":  "你不入我门下，叫我如何信你？\n",
        	"老掌门":  "你不入我门下，叫我如何信你？\n",
			"阿修罗王" : (: jice :),

        ]) );

    	set_temp("apply/haste",300);
    	set("combat_exp", 10000000);
    	set("score", random(90000));
    
    	set("skill_public", 1);

		set("perform_busy_w", "wudang/sword/three-sword/nianzijue");
//		set("perform_weapon_attack","wudang/sword/three-sword/sancai");
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    
    	set_skill("foreknowledge", 160);
    	set_skill("liangyi-force",180);
    	
    	
    	set_skill("changelaw",220);
    	set_skill("perception", 300);
    	set_skill("changelaw", 150);
    	set_skill("unarmed", 200);
    	set_skill("sword", 300);
    	set_skill("move", 200);
    	set_skill("force", 200);
    	set_skill("parry", 300);
    	set_skill("dodge", 250);
    	set_skill("three-sword", 220);
    	set_skill("taiji", 200);
    	set_skill("five-steps",200);
    	
    	map_skill("force","liangyi-force");
    	map_skill("unarmed", "taiji");
    	map_skill("sword", "three-sword");
    	map_skill("parry", "three-sword");
    	map_skill("dodge","five-steps");
	
    	setup();
    	carry_object(__DIR__"obj/cloth3")->wear();
    	carry_object(__DIR__"obj/hat")->wear();
    	carry_object(__DIR__"obj/swordd")->wield();
}


void attempt_apprentice(object ob)
{
       	call_out("do_recruit", 2, ob);
}

int recognize_apprentice(object ob)
{
    	return ( ob->query("free_learn/foreknowledge"));
}


int jice()
{
	object me;
	me = this_player();
	if(REWARD_D->riddle_check(me,"武当掌门") != 3)
		return 0;

	REWARD_D->riddle_set(me,"武当掌门",4);
	ccommand("hmm");
	ccommand("say 和我联系的明明不是阿修罗王，怎么现在换人了？");
	ccommand("emote 满面狐疑地打量着你：你该不是在骗我吧？");
	ccommand("hmm");
	ccommand("say 老夫已经不耐烦了，不管他们，我们自己动手！");
	ccommand("say 你，负责去"HIG"杀石雁"NOR CYN"，烤他的肉来见我！");
	ccommand("say 我会让人把你需要的东西藏到"MAG"武当山下一古松"NOR"里，你自己去拿吧。");
	ccommand("wave");
	tell_object(me,WHT"你想着杀石雁事关重大．．．还是先去和殷正廉说一说吧。\n"NOR);
	return 1;
}


void do_recruit(object ob)
{
    	if((int)ob->query_temp("marks/顾云飞")) {
        	command("stare " + ob->query("id"));
        	command("say 你不是来做奸细的吧？\n");
        	return;
    	}
    	else  if((int)ob->query_temp("marks/幽灵山庄")) {
        	say("\n");
			ccommand("hmm");

			if (REWARD_D->riddle_check(ob,"古井疑云") == 3)
			{ 

	        	command("say 此事容后再议。\n");
	        	command("say 你先去把武当山的镇山之宝七星剑拿来给我，如果那姓过的拦你．．．\n");
				ccommand("heihei");
	        	command("say 你就问他那「"HIG"穿颅钉"NOR CYN"」到底是什么。\n");
				REWARD_D->riddle_set(ob,"古井疑云",4);
			}

        	return;
    	}
    	else {
		command("sigh");
        	command("say 我早已不收徒弟了！");
    	return;
    }
}


int accept_object(object who, object ob)
{


	if (ob->query("name")=="烤石雁肉" 
		&& ob->query("id") == "fried meat" 
		&& REWARD_D->riddle_check(who,"武当掌门") == 6)
	{
	// 好吧，就算你养个pet叫石雁，好坏你已经完成过杀他的任务了……

		command("haha");
		command("laugh master");

		command("say 好，好！石雁啊石雁，你终于落得如此下场！\n");
		command("say 不错不错，你可得老夫真传！\n");
		REWARD_D->riddle_done(who,"武当掌门",50,1);
		return 1;
	}

    	if((string)ob->name() != "七星剑") return 0;
    	if(REWARD_D->riddle_check(who,"古井疑云") < 7) return 0;
    	if(REWARD_D->riddle_check(who,"古井疑云") == 7)
		{
			tell_object(who,HIG"你突然觉得还是先把宝剑拿去给殷正廉看看为上。\n"NOR);
			return notify_fail(" ");
		}

    	if(ob->query("real") && (object)ob->query_temp("marks/owner") == who)
    	{

			REWARD_D->riddle_set(who,"武当掌门",2);

        	command("spank " + who->query("id"));

			REWARD_D->riddle_done(who,"古井疑云",50,1);

	    	who->set("free_learn/foreknowledge", 1);
        	command("say 你想要武功秘籍，还是向我学武？"HIY"(accept book/teach?)"NOR);
        	say("\n");
        	command("sigh");
        	command("say 如今证物在手，要揭穿石雁，登上武当大位易如反掌；");
        	command("say 只是约定期限将至，怎么那边还没有消息？");
        	say("\n");
        	command("consider");
        	command("say 你如有空，不如帮我去巴山问问他们，下一步怎么打算。");
        	say("\n");
			who->set_temp("marks/拿到七星宝剑", 1);
        	add_action("do_accept", "accept");
    	}
    	else
    	{
        	say("老刀把子接过七星剑，仔细地看了看。\n");
        	command("sigh");
        	command("say 这一柄又是假的！");
    	}
    	return 1;
}

int do_accept(string arg)
{
    	object me, book;
    
    	if(!arg || (arg != "book" && arg != "teach")) 
        	return notify_fail("你想要什么？\n");
    	me = this_player();
    	if(!me->query_temp("marks/拿到七星宝剑")) return 0;
    	me->delete_temp("marks/拿到七星宝剑", 0);
    	if(arg == "book")
    	{
        	book = new(BOOKS"skill/wudang_40");
        	book->move(this_object());
        	book->move( me);
       		message_vision("老刀把子递给$N一本薄薄的小册子。\n", me); 	
     //   	command("give book to " + me->get_id());
        	command("say 你功劳不小，所以你还可以向我学武（两仪心法和占卜学）");
    	}
    	else 
        	command("say 从今天开始，你可以同我学武了（两仪心法和占卜学）");
    	return 1;
}


smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	for(i=0; i<sizeof(enemy); i++) {
	if (!enemy[i]->is_zombie() && enemy[i]->query("id")!="guard") 
		if (random(2)) who->perform_action("sword.nianzijue"); 
			else who->perform_action("dodge.bazhentu");
	}
	return;
}  

	
int prevent_learn(object me, string skill)
{
	if (!REWARD_D->check_m_success(me,"古井疑云"))
  	{
      		command("heihei");
      		command("say 不入我门下，就想学武，天底下哪里有这么好的事情？");
      		return 1;
  	}
	

  	if (skill != "foreknowledge" && skill != "liangyi-force")
  	{
      		command("shake");
      		command("say 我可只答应教你两仪心法和占卜术啊。");
      		return 1;
  	}


	if (me->query_skill("foreknowledge",1) >= 150 && skill != "liangyi-force" && !REWARD_D->check_m_success(me,"武当掌门"))
	{
      		command("sigh");
      		command("say 老夫今天没有心情，你改天再来吧。");
			return 1;
	}

	if (me->query_skill("liangyi-force",1) >= 150 && skill != "foreknowledge" && !REWARD_D->check_m_success(me,"武当掌门"))
	{
      		command("sigh");
      		command("say 老夫今天没有心情，你改天再来吧。");
			return 1;
	}

  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/foreknowledge") 
		&& (skill == "liangyi-force" || skill == "foreknowledge"))
		return 0;
	
	return 1;
}