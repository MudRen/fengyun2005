#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int show_me();
int ask_tie();
int letter();
int analyze();
int gate();

void create()
{

		set_name("安子豪",({"an zihao","an"}));
    	set("long", "
太平镇驿站的驿丞，这儿远近八百里人烟稀少，这个驿站成了当地最高的官家
象征，驿丞就是八十三户百姓的父母官。\n");
		set("title", "太平镇驿丞");
		set("nickname", "万事通");
		set("age",40);
	
		set("combat_exp", 8000000);
        set("gender","男性");	
		set("reward_npc", 10);
		
		set("inquiry", ([
        	"韦七娘" : 	(: show_me :),
           	"wei qiniang" : (: show_me :),
           	"tie hen" : 	(: ask_tie :),
           	"铁恨" : 	(: ask_tie :),
   			"小潘": 	(: letter :),
   			"骆驼队":	(: letter :),
   			"分析":		(: analyze :),
   			"分析分析":		(: analyze :),
   			"回报":		(: gate :)
   		]));
		
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n安子豪喝道：反了反了，竟然敢杀官差！！！\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"安子豪说：“我姓安，安子豪。平安的安，子孙的子，豪杰的豪。”\n",
    	}) );  
	

		auto_npc_setup("wang",300,180,0,"/obj/weapon/","fighter_w","yue-spear2a",2);
		set_skill("changquan",220);
		delete("perform_busy_u");
		set("perform_busy_d","legend/dodge/fall-steps/qiufengluoye");
		set_skill("dormancy",300);
		set_skill("six-sense",300);
		set("smartnpc_busy",1);
		
		setup();
		carry_object(__DIR__"obj/o_cloth")->wear();
		carry_object(__DIR__"obj/sspear")->wield();
}


int show_me()	{
	if (REWARD_D->riddle_check(this_player(),"喋血鹦鹉")>=5) {
		command("say 原来是七娘叫你来的，铁恨与我提起过，我先给你介绍一下这里的情况吧。");
		call_out("event1",1,this_player(),0);
	}
	else {
		command("consider");
		command("say 韦七娘又叫神针韦七娘，在江湖上大大有名，专杀那些穷凶极恶之人。");
		command("say 不过这几年来她销声匿迹，听说已经隐退了。");
	}
	return 1;
}


int ask_tie()  {
	
	object who;
	who=this_player();
	if (REWARD_D->riddle_check(who,"喋血鹦鹉")>=5)
		ccommand("say 铁恨，韦七娘和我都在追查太平王府失窃珠宝的下落。");
	else
		ccommand("say 铁恨是天下闻名的四大名捕之铁手无情。");
	return 1;
}	

int analyze(){
	object me, ob;
	string *hint, msg;
	int i, num1, num2;
	mapping info = ([ 							
						"七杀手": "七杀手虽然在地方上名气不小，这次只不过是武三爷手里的一步棋罢了，
武三爷用这一千两黄金和七条人命，就是为了换出李大娘的底细。\n",							

						"老蛔虫之谜": "老蛔虫深藏不露，既然在此出现，必然与太平王府的珠宝有关，
没想到却被武三爷暗算而死。\n",

						"尸体的秘密": "谭氏兄弟贪财而来，竟落得如此下场，这七星绝命针竟会在这小小
的太平镇出现，看来这里藏龙卧虎，暗处的高手还真不少。\n",

						"红石的秘密": "这泷洲的红石竟然也会在这里出现，莫非，这太平镇上真有了邪魔鬼怪？\n",
						
						"甘老头":	"甘老头来镇上两年多了，整日打铁，似乎没什么可疑之处。\n",
							
						"宋妈妈的秘密": "宋妈妈虽然诡异，但只有些嘴上的功夫，不像是幕后之人。
她家竟然有暗孔通向鹦鹉楼，这倒是蹊跷之事，莫非，宋妈妈是受人差遣，
专门监视血奴的。那么这个血奴又扮演什么角色呢？\n",

						"老掌柜": "这老掌柜的鹦鹉据说是血奴送给他的礼物，据说他一生的积蓄都都花
在她身上，又据说他连碰也没碰过血奴，却已经得到了最大的满足。这鹦鹉
竟然会没来由的死去，邪门、邪门！不过，老掌柜本人我看没什么问题。\n",

						"常笑": "常笑到此，原来是为了追查太平王府一案，这么算来，除了武三爷、
李大娘，又多了个厉害角色，更别提那神秘莫测的血鹦鹉。\n",

						"血奴表演": "这血奴难道真的是血鹦鹉的奴才？那么这血鹦鹉的传说难道就要兑
现在这里，\n",	
						
						"遇刺":	"此次行刺失败，主谋之人一定不会甘心，不过，既然有人已经请了刺客
杀你，说明我们的调查已经触动了关键，离真相大白不会太远了。\n",
							
					]);
						
	me= this_player();
	ob = this_object();
	
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")>=7) {
		tell_object(me,CYN"安子豪说：这李大娘的山庄，应该就是这个谜题的关键，你速速想法潜入探个究竟。\n"NOR);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")!=6) {
		command("doubt");
		return 1;
	}
	
	num1 = sizeof (info);
	num2 = sizeof (me->query("marks/parrot"));
		
	tell_object(me,WHT"安子豪说：好，那就让我们看看现在有了哪些线索（"+ num2 +"/" + num1 +"）\n\n"NOR);
	
	hint = keys(info);
	
	msg = "";
	
	for (i=0;i<sizeof(info);i++) {
		if ( me->query("marks/parrot/"+hint[i]))
			msg += CYN+ info[hint[i]] + "\n"NOR;
	}
	
	tell_object(me,msg);	
	
	if (num2 < num1/2) 
		msg = "安子豪说：这太平镇里名堂很多，你需得细心多加打探才是。\n";
	else if (num2 < num1)
		msg = "安子豪点点头说：不错，这案情日益明朗，不过似乎还差一点什么。\n";
	else
		msg = "安子豪沉吟道：没想到小小一个太平镇，竟然引来了这么多难惹的人物，
不过，有一点是肯定的，这看似千丝万缕的关系，都牵在太平王府的珠宝上。
谁是盗宝的，谁是夺宝的，谁又是护宝的呢？

安子豪说：还有那谜一般的血鹦鹉，恐怕并不如常笑所说的只是一个障眼法儿，
否则四大名捕中的铁恨，怎么又会无缘无故地死去？

安子豪说：当前镇里局势一触即发，武三爷杀了老蛔虫，下一步便是向李大娘
动手了，咱们且来个坐山观虎斗。你速去潜入李大娘的庄中，探一探其底细，
若有风吹草动，速速"YEL"回报"NOR"于我再做计较。\n";

	tell_object(me,msg);
	
	if (num2>=num1)
		REWARD_D->riddle_set(me,"喋血鹦鹉",7);	
	
	return 1;
		
}		

int gate(){
	object me= this_player();
	
	if (REWARD_D->riddle_check(me,"喋血鹦鹉")>=7) {
		tell_object(me,CYN"安子豪挫着手走来走去，似乎也没有什么良策。\n"NOR);
		return 1;
	}
	
	command("hehe");
	return 1;	
}

string *event1_msg=	({
	
	GRN"\n  安子豪道：“方圆八百里，太平镇是唯一有人烟的地方。地方虽然不小，可是附
近有沼泽和密林，山上听说还有猛虎，所以能让人生存的地方并不多。据我们上次
调查，镇上一共只有八十三户人家。”\n"NOR,
	
	GRN"  “天高皇帝远，这驿站是唯一官家的象征，我也算是这里的父母官。”安子豪笑
笑说：“不过，这也只是在三爷不管事的时候。。三爷姓武，文武的武，叫"+HIG"武镇山"NOR+GRN"，
这地方有一半是他的。”\n"NOR,
	
	GRN"  “如果没有"+HIG"李大娘"NOR+GRN"，他也许早就把另一半也买了下来。没有人知道大娘真名叫什
么，也没人知道她的来历，只知道她三年前在镇旁买下了座庄园。”\n"NOR,

	GRN"  “一山容不得二虎，"+HIG"李大娘"NOR+GRN"和"+HIG"武三爷"NOR+GRN"一直在明争暗斗，到现在为止，似乎谁都没
能占上风。”\n"NOR,

    	GRN"  “两年前铁捕头在审问一些江湖大盗时，发现他们手中曾有一批太平王府失窃的
珠宝，而这些珠宝的来源都归结到这个小镇周围。韦七娘和我在此明查暗访，还是
一无所获。直到数月前铁恨擒住满天飞，满天飞在临死前供出又有一笔珠宝将在此
地易手，我想这就是他请你来协助的原因。”\n"NOR,
    	
});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) 
		|| this_object()->is_fighting()) 	return;
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		tell_object(me,GRN"  除了武三爷和李大娘外，这镇上还有"+HIG"老蛔虫，谭氏兄弟，宋妈妈，甘老头，老掌柜"NOR+GRN"
等人值得一查。前几日京城四大名捕之一的毒手"+HIG"常笑"NOR+GRN"也突然来到这里，此人心狠手
辣，你需小心。若有空，也可去鹦鹉楼转转，说不定还能见到"+HIG"血奴"NOR+GRN"姑娘。

你需小心谨慎，将这些人物都一一查清，若有线索，与我一起来"YEL"分析分析。\n\n"NOR);
		if (REWARD_D->riddle_check(me,"喋血鹦鹉")==5)
			REWARD_D->riddle_set(me,"喋血鹦鹉",6);
		command("addoil "+me->get_id());
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


int letter() {
	object room;
	object me;
	me = this_player();
	room = find_object(AREA_QUICKSAND"yizhan");
	if (room && room->query("route_clear")) {
		message_vision(CYN"
安子豪呵呵一笑说：“小潘这家伙，他的骆驼队和我的驿站正在联手做买卖，
朝廷俸禄太少，这也是不得已，不过，咱们虽然是官商，一样童叟无欺。”\n"NOR,this_object());
		return 1;
	}
	message_vision(CYN"
安子豪发愁地说：“小潘的骆驼队和我的驿站正在联手做买卖，朝廷俸禄太
少，这也是不得已。但是这几个月来道上出了强盗，据说是"+room->query("bandit_name")+"的土匪们
干的，我这里人单力薄，无能为力，"+RANK_D->query_respect(me)+"如果能去把他们剿灭就好了。”
\n"NOR,this_object());
	me->set_temp("quicksand/route_bandit",room->query("bandit_name"));
	return 1;
}