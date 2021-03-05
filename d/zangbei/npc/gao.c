#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();
int fail();

void create()
{
    	set_name("高老大",({"gao laoda","gao"}));
	set("title",HIR"快活林"NOR);
   	set("long","
高老大并不是大哥是大姬，她有一双极美丽的手，只不过略嫌太大了些，
正显示出这双手的主人那种倔强的性格。在战乱饥灾最严重的时候，十
三岁的她一个人带大了四个孩子，她几乎做过任何事，她偷，她抢，她
骗，她甚至出卖过自已。那时无论谁只要给她一套衣服，就可以在她身
上得到一切。现在她却几乎拥有一切。\n");
     	
     	set("gender","女性");
     	set("group","khlr");
     	
    	set("age",32); 	 	

    	set("combat_exp",9500000);  
    	set("attitude", "friendly");
    	
		set("reward_npc",5);
	    	
    	set("inquiry", ([
 		"创伤":		(: estate() :),
 		"快活林":	(: estate() :),
 		"疤":		(: estate() :),
 		"地契":		(: estate() :),
 		"孟星魂":	"孟星魂，石群，小何，叶翔都是我一手带大的。\n",
 		"石群":		"孟星魂，石群，小何，叶翔都是我一手带大的。\n",
 		"叶翔":		"孟星魂，石群，小何，叶翔都是我一手带大的。\n",
 		"小何":		"孟星魂，石群，小何，叶翔都是我一手带大的。\n",
 		"陆漫天":	"陆漫天这老狐狸，你在我这快活林多呆一阵就知道他是什么样的人了。\n",
 		"无名老人":	"这老狐狸，你仔细看看就知道他是什么样的人了。\n",
 		"失败":		(: fail() :),
 		"fail":		(: fail() :),
 		"msg":		"yes",
   		]));
    	
    	set("death_msg",CYN"\n$N狂笑着道“你们全都去死吧，死光了最好。”\n"NOR);  	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"\n高老大把紫红色的窗帘放下，一个人静静的坐在昏暗的屋内，她并不是厌恶光
亮，面是畏惧—也并不是怕她脸上的皱纹会被照出来，而是怕照出她心里的那
些创伤。这些创伤久已结成了疤，永远抹不去的疤。。\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_u","nine-moon-claw",1);
	
	setup();
    	carry_object("/obj/armor/cloth",([	"name": BLU"宝蓝色缎裙"NOR,
					"long": "一条宝蓝色缎裙。\n",					
					 ]))->wear();   
 
}

int fail(){
	object me=this_player();
	
	if (me->query("timer/菊园失败") + 1440 > time()) {
		command("sigh");
		command("say 孙玉伯果真是老奸巨滑，你能活着回来，已是万幸。");
		command("say 你且暂避一日再来找我，我们再做尝试！");
		return 1;
	}
	
	message_vision(CYN"高老大把紫红色的窗帘放下，一个人静静的坐在昏暗的屋内，她并不是厌恶光
亮，面是畏惧—也并不是怕她脸上的皱纹会被照出来，而是怕照出她心里的那
些创伤。这些创伤久已结成了疤，永远抹不去的疤。。\n",me);
	return 1;

}
int estate() {
	object ob,me;
	ob=this_object();
	me=this_player();
	
	
	if (REWARD_D->check_m_success(me,"菊园传奇")==1
		|| REWARD_D->riddle_check(me,"菊园传奇")==14) {
		message_vision("
高老大冷冷地说：你既然跟了孙玉伯，还有什么好说的？\n",me);
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"菊园传奇")==2) {
		message_vision("
高老大说：有了地契，我要重建快活林。\n",me);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"菊园传奇")==13) {
		message_vision("
高老大说：孙玉伯已经死了，不过，我们的交易是要用他的地契来结算的。\n",me);
		return 1;
	}
	
	if (me->query("timer/菊园失败") + 1440 > time()) {
		command("sigh");
		command("say 孙玉伯果真是老奸巨滑，你能活着回来，已是万幸。");
		command("say 你且暂避一日再来找我，我们再做尝试！");
		return 1;
	}
			
	if (REWARD_D->riddle_check(me,"菊园传奇")) {
		switch (random(3)) {
		case 0:	message_vision("
高老大的手慢慢地伸过去握着了$N的手，缓缓接着道：我知道你也累得很，
但生活就是这样子的，我们要活下去，就不能停下来。\n",me);
				break;
		case 1: message_vision("
高老大说：孙玉伯是一个很可怕的对手，你要做的第一步，就是取得他彻
彻底底的信任，你可以为他杀人，甚至杀快活林的人，但是你一定要让他
没有疑心才可能得手。\n",me);
				break;
		case 2: message_vision("
高老大说：孙玉伯的手下人才济济，其子孙剑性烈如火，其副手律香川老
谋深算，更有陆漫天等武林中人相助，万万不可轻敌。\n",me);
		}		
		return 1;
	}
	
	if (me->query("combat_exp")<5100000) {
		message_vision("高老大看了看$N说，你这点能耐，恐怕帮不了我的忙。\n",me);
		tell_object(me,"（需等级90）\n");
		return 1;
	}
	
	message_vision("\n
高老大环顾四周，慢慢地说：“这是我的屋子，屋子里所有的一切，全都是我
的。而这屋子，只不过是我财产中极小极小的部分。到这儿来的，不是家财万
贯的富商巨贸，就是名声显赫的武林豪杰，只要我开口他们就会去为我做任何
事，因为他们也同样有求于我。

不过，这快活林的地却不是我的，很多年前，租下这快活林时我还很穷，现在
我的财产已足以买下五百座这样的园子，但是我却仍然得不到这快活林的地契。
因为这块地是孙玉伯的。

我唯一的愿望就是这张地契，如果你能替我拿到它，我的一半财产就是你的，
我也会助你在江湖上扬名利万。你若是诚心助我。。。。

我已经替你准备了新的身份，你可速去菊园投靠律香川，待机而动，入到菊园，
就说是我高老大推荐的。\n\n",me);
	me->delete("marks/kuaihuo/被识破");
	REWARD_D->riddle_set(me,"菊园传奇", 1);
//	me->set("marks/kuaihuo/接刺杀任务",1);
	return 1;
}

int accept_object (object who, object item) {
	
	object /*paper,*/ me;
	mapping data;
	
	me = who;	
	
	if (REWARD_D->check_m_success(me,"菊园传奇")==2) {
		message_vision("高老大说，你不是已经把地契给我了么？\n",me);
		return 0;
	}
	
	if (REWARD_D->check_m_success(me,"菊园传奇")==1) {
		message_vision("
高老大冷冷地说：你既然跟了孙玉伯，还有什么好说的？\n",me);
		return 0;
	}
	
				
	if (item->query("kuaihuo") 
		&& item->query("item_owner") == who
		&& item->query("name")=="地契") {
			message_vision(CYN"
高老大拿着快活林的地契，许久许久，眼中似有泪花闪动。。。。\n"NOR,who);

			me->delete_temp("marks/kuaihuo");
			REWARD_D->riddle_done(me,"菊园传奇",100,2);
		
			data = ([
				"name":		"菊园传奇",
				"target":	me,
				"att_1":	"con",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);	
		
			me->add("deposit",2000000);
			tell_object(me,YEL"\n高老大说：这二百两黄金，我已经汇入你的账号。\n"NOR);
			return 1;
	}
	
	return 0;
}
	