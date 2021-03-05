// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int yuefei();
int leave();

int jice();
int jice2();

void create()
{
    	set_name("殷正廉", ({ "master yin", "master","yin" }) );
    	set("long", "济南城中最高的官，有至高无上的权力\n");
    	set("nickname", RED"龙图阁大学士"NOR);
    	set("class","official");
    	set("attitude", "heroism");
    	set("reward_npc", 1);
		set("difficulty", 35);
        set("chat_chance", 1);
        set("chat_msg", ({
                "殷正廉道：皇上当年赐给我的尚方宝剑不见了。。。\n",
                "殷正廉摇摇头道：宝剑不见了，没有心情教学生。。。\n",
        }) );
    // Make this before create_family will prevent generation in title
    	set("rank_nogen",1);
    	create_family("朝廷命官",6,"太子太保 守济南府");
    	set("student_title","官员");
    	set("ranks",({ "准备将","副将","正将","副统领","统领","御营副统制",
                       "御营统制","御营都统制","龙神卫四厢都指挥使","捧日天武四厢都指挥使",
                       "侍卫亲军步军都虞候","侍卫亲军马军都虞候",RED"殿前都虞候"NOR,
                       CYN"侍卫亲军步军副指挥使"NOR,YEL"侍卫亲军马军副指挥使"NOR,BLU"殿前副指挥使"NOR,
                       CYN"侍卫亲军步军都指挥使"NOR,YEL"侍卫亲军马军都指挥使"NOR,RED"殿前都指挥使"NOR }));
    	set("rank_levels",({ 32000,64000,128000,256000,384000,
                             512000,800000,1024000,1556000,
                             2048000,3652000,5000000,
                             6258000,8848000,10800000,
                             14580000,20048000,26244000 }));

	set("inquiry", ([
		"zonghengtianxia" : (: yuefei :),
		"纵横天下" : (: yuefei :),
		"yuefei" : (: yuefei :),
		"岳飞" : (: yuefei :),
		"yue fei" : (: yuefei :),
		"计策" : (: jice :),
		"杀石雁" : (: jice2 :),

		"leave" : (: leave :),
	]));
    	set("vendetta_mark", "authority");
    	set("guard_msg",HIW"$N喝道：大胆草民，竟然敢在老夫面前撒野，欺朝廷无人么！\n"NOR);
    	 	
	set("age",55);
    	set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
        	(: perform_action, "unarmed.yuhuan" :),
        }) );
    	set("combat_exp", 90000000);
    	set_temp("apply/damage",500);
    	set_temp("apply/dodge",200);
    
    	set_skill("chanting",100);
    	set_skill("unarmed", 180);
    	set_skill("force",160);
    	set_skill("parry", 140);
    	set_skill("dodge", 140);
    	set_skill("changquan",220);
    	set_skill("yue-spear",120);
    	set_skill("manjianghong",130);
    	set_skill("move", 140);
    	set_skill("leadership",200);
    	set_skill("strategy",200);
    	set_skill("puti-steps",170);
    	set_skill("spear",200);
    	set_skill("perception", 100);
		set_skill("literate", 100);
		set_skill("foreknowledge",100);
		
    	map_skill("unarmed","changquan");
    	map_skill("dodge","puti-steps");
    	map_skill("parry","changquan");
    	map_skill("force","manjianghong");
    	map_skill("spear","yue-spear");

    	setup();
//    	if(random(4)==2) set("env/no_teach",1);
    	carry_object(__DIR__"obj/guanfu")->wear();
}

int yuefei(){
	object me;
	me = this_player();
	if (REWARD_D->check_m_success(me,"纵横天下")){
		message_vision("$N看着$n，许久许久，不发一语。\n", this_object(),me);
		return 1;
	}
		
	
	if (REWARD_D->riddle_check(me,"纵横天下")==2)	{
//	if(me->query("marks/操练岳家中平枪法")){
		message_vision("$N对$n说道：“既然你已经去过大明湖畔，不妨去书库看看我的手稿。”\n", this_object(), me);
		return 1;
	}
	message_vision(CYN"\n$N对着$n长叹了一口气：“岳武穆当年的成名绝技［纵横天下］我也不能全部领悟，\n"NOR,
			this_object(), this_player());
	if (me->query_skill("strategy",1)< 150)
		message_vision(CYN"相传此招是将行军用兵之法融于枪法之中。你需好好钻研兵法（150）才是。\n"NOR, this_player());
	else if (me->query_skill("yue-spear",1)<120)
		message_vision(CYN"你的岳家枪法火候尚浅，就更没有希望了。（需１２０级）\n"NOR,this_player());
	else
		{		
		message_vision(CYN"中间的奥秘。 听说大明湖畔是他当年大破金军之处，你不妨去看看。”\n"NOR, this_object());
		REWARD_D->riddle_set(this_player(),"纵横天下",1);
	//	this_player()->set("marks/大名湖畔纵横天下", 1);
	}
	return 1;
}


int jice()
{
	object me;
	me = this_player();
	if(REWARD_D->riddle_check(me,"武当掌门") != 2 && REWARD_D->riddle_check(me,"武当掌门") != 3 )
		return 0;

	REWARD_D->riddle_set(me,"武当掌门",3);
	ccommand("say 巴山．．．巴山．．．");
	ccommand("consider");
	ccommand("say 莫非是魔教中人？");
	ccommand("hmm");
	ccommand("say 你且去告诉老刀把子，就说．．．嗯，"HIG"阿修罗王"NOR CYN"要他暂缓动手。"NOR);
	ccommand("say 先把幽灵山庄拖住，再来思考应变之策。");
	return 1;
}


int jice2()
{
	object me;
	me = this_player();
	if(REWARD_D->riddle_check(me,"武当掌门") != 4)
		return 0;

	REWARD_D->riddle_set(me,"武当掌门",5);
	ccommand("bite");
	ccommand("say 这老刀把子果然狡猾。");
	ccommand("say 只安排你一个人去杀石雁，这其中必定有诈……");
	ccommand("consider");
	ccommand("say 你且去武当山，将石雁打晕，不要杀，带到我这里来，我亲自来问他。");
	return 1;
}


void attempt_apprentice(object me)
{
    	if( !me->query("class")||me->query("class")=="official")
    	{
			if (!REWARD_D->check_m_success( me,"失剑风波"))
			{
				command("hmm");
				command("say 本官的尚方宝剑为人所窃，你且先破了此案再说。");
			} else if( me->query_skill("strategy",1) >= 80 ) {
				command("smile");
				command("say 很好！朝廷正在用人之时，努力吧！\n");
        		command("recruit " + me->query("id") );
			} else 
				command("say 你的兵法太差了（需80级），怎么给朝廷效力？\n");
    	}
    	else 
    			command("say 朝廷不需要你这种不三不四，来历不明之人！\n");
}

void recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) ) {
        	ob->set("class", "official");
    		ob->set("vendetta_mark", "authority");
    	}

}


int accept_object(object who, object ob)
{
    if( ob->query("shangfang") ){
		this_object()->delete("env/no_teach");
		if (REWARD_D->riddle_check(who,"失剑风波")==5) {
			REWARD_D->riddle_done(who, "失剑风波",10,1);
			command("nod");
			command("say 后生可畏，看不出你还有那么两下子，既然这样。。。。");
			command("say 近日数名桃源村民前来报案，说村里井中有鬼火憧憧。");
			command("say 无知小民，想来必是捕风捉影之说，你且去走一趟，勘明此事真伪。");
		       REWARD_D->riddle_set(who,"古井疑云",1);
		} else 
		{
			command("ah");
			command("say 大胆！偷了老夫的宝剑竟然还敢当面欺诈！\n");
			kill_ob(who);
		}
		return 1;
	}
	
	if (ob->query("name")=="头颅骨" && ob->query("id")=="skull" 
		&& REWARD_D->riddle_check(who,"古井疑云") == 2)	{
		if (!ob->query("recovered"))
		{
			command("consider");
			command("say 桃源井里竟然会出现这么一个奇怪的头颅骨，此事大有蹊跷！");
			message_vision(CYN"
殷正廉拿着头颅骨反复看了又看，摇摇头说：当务之急，便是探访出死者是
为何人！若有线索，快快再来回报！\n"NOR, who);
			return 0;
		}
		command("ack");
		command("say 这、这、这、七星子原来死于非命，看来武当派里蹊跷不少！");
		command("say 现任掌门石雁城府很深，要解开这个谜需从他的弟子下手。
特别是那个姓过的，当时老掌门病重时，就是他伺候的。
不过你还是先去幽灵山庄一趟，我怀疑此事与他们也有牵连。\n\n");
		REWARD_D->riddle_set(who,"古井疑云",3);
		return 1;
	}

	if (ob->query("name")=="七星剑" && ob->query("real") 
		&& REWARD_D->riddle_check(who,"古井疑云") == 7)	{
		command("consider");
		REWARD_D->riddle_set(who,"武当掌门",1);
		REWARD_D->riddle_set(who,"古井疑云",8);

		command("say 你先去把剑拿给老刀把子，听听他怎么说，");
		command("say 然后再来见我，我们再商讨商讨下一步的"HIG"计策"NOR"。\n\n");
		return 0;
	}



        return 0;
}


void init()
{
	object ob;
	::init();
	add_action("do_killing", "kill");
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) return;
	if (this_object()->query("env/no_teach")==1 && ob->query("family/master_id")=="master yin")
	message_vision("$N烦躁地说：丢了尚方宝剑，老夫这会儿没心思教你。\n",this_object());
}


int leave() {
	if (this_player()->query("class")!="official") return 0;
	message_vision(CYN"$N正色道，“报效朝廷乃忠君爱民之事，怎么能半途而废呢。“\n"NOR, this_object());
	message_vision(CYN"$N说：若执意要走我也不勉强，只是从此就是一介平民，朝廷之事再也无权过问。\n"NOR,this_object());
	message_vision(CYN"$N说：玉环鸳鸯拳也不能再使，慎思，慎思。\n"NOR,this_object());
	return 1;
}