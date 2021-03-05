#include <ansi.h>
inherit SMART_NPC;

int do_answer(string arg);

void create()
{
    	set_name("马空群",({"ma kongqun","ma"}));
	set("title",HIR"万马堂 堂主"NOR);
   	set("long","
他端端正正地坐在那里。就算屋子里没有别人的时候，他还是坐得规规矩矩，
椅子后虽然有靠背，他腰干还是挺得笔直笔直。他一个人孤孤单单地坐在那
里，距离每个人都那么遥远。他仿佛已将自己完全隔绝红尘外，没有欢乐，
没有享受。\n");

     	set("gender","男性");
    	set("age",62);
    	 	
    	set("combat_exp",10000000);  
    	set("attitude", "friendly");

    	set("reward_npc",1);
    	set("difficulty",30);
    	    	
  		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    
        
       	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        set("smartnpc_busy",1);
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );    	    	
    	
    	
		auto_npc_setup("wang",350,200,0,"/obj/weapon/","fighter_w","shenji-blade",2);
	
		setup();
    	carry_object("/obj/armor/cloth",([	"name": HIC"天蓝长袍"NOR,
    						"long": "一件天蓝长袍。\n",
    						 ]))->wear();     
    	carry_object("/obj/weapon/blade/blade_ma")->wield();
}

/*
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer","answer");
}*/


void greeting(object me)
{
	object ob;
	ob= this_object();
	if( !me || environment(me) != environment() ) return;
	
//	this happens in 书房 only
	
	
	if (environment(ob)->query("wanma_discussion") && !me->query("marks/wanma/杀场主_ma")) {
		message_vision(YEL"$N拿起桌上的酒杯，喝了一口又放下，然后缓缓地说：\n"NOR,ob);	
		call_out("event1",1,me,0);
		return;
	}
	
	if (environment(ob)->query("wanma_discussion") && me->query("marks/wanma/杀场主_ma")
		&& me->query_temp("marks/wanma/杀花满天_ma") && me->query_temp("marks/wanma/杀云在天_ma")
		&& !me->query("marks/wanma/准备杀同伙_ma")) {
		message_vision(CYN"
过了许久，马空群缓缓地说：“朋友，兄弟，一转眼就成了想害你的人，
我不怪他们，如果我是他们，我也会这么做。不过，若是事情败露，我也
死而无怨。。。。这事你办得很好，从此，这万马堂，一半就是你的了。”\n\n"NOR,ob);	
		message_vision(CYN"
马空群闭上眼睛，一字字道：“白天羽的孤儿，我们还不知道是谁，这样
的仇恨，本就是非报不可的，他也一定会来。无论什么样的秘密，迟早总
有人知道，不过，他现在一定还没有抓住真实的证据，能证明是我们下的
手。所以，凡是知道这个秘密的人，都不应该再活着，你看过那张纸片，
你知道该怎么办。。。。”\n\n"NOR,ob);	
	message_vision(CYN"
马空群沉声道：“我就在这里等他，等他先错！”他神情又渐渐冷静，一
字字慢慢地接着道，“只有等，是永远不会错的！一个人只要能忍耐，能
等，迟早总会等得到机会的！”\n\n"NOR,ob);	
		me->set("marks/wanma/准备杀同伙_ma",1);
		return;
	}
	
	if (environment(ob)->query("wanma_discussion") && me->query("wanma/准备杀同伙_ma")
		&& me->query_temp("marks/wanma/易大经_ma") && me->query_temp("marks/wanma/薛斌_ma")
		&& me->query_temp("marks/wanma/桃花娘子_ma") && me->query_temp("marks/wanma/柳东来_ma")
		&& me->query_temp("marks/wanma/郭威_ma") 
		&& !me->query("marks/wanma/准备杀主脑_ma")) {
		call_out("event2",1,me,0);
		return;
	}

	if (environment(ob)->query("wanma_discussion") && me->query("marks/wanma/准备杀主脑_ma")
		&& me->query_temp("marks/wanma/花白凤_ma") && me->query_temp("marks/wanma/傅红雪_ma")
		&& me->query_temp("marks/wanma/叶开_ma"))	{
		message_vision(YEL"马空群一跃而起，大笑道：“经此一役，万马堂永垂武林。”\n"NOR,ob);
		message_vision(CYN"给你什么我还没想好，sorry。\n"NOR,ob);
		me->set("marks/wanma/终局马空群",1);
		return;
	}
		
	if (!me->query("marks/wanma/迎宾")) return;
	
	if (me->query("marks/wanma/上楼")) return;
	
	if (me->query("marks/wanma/杀客人") && me->query_temp("marks/wanma/杀客人a")
		&& me->query_temp("marks/wanma/杀客人b") && me->query_temp("marks/wanma/杀客人c")
		&& !me->query("marks/wanma/上楼")) {
		message_vision(CYN"
马空群说：“好，你很有前途，万马堂就需要你这样的人才，如果你愿意，
以后你就是我马空群的朋友。不过，有一个问题要问你，如果你的朋友独
断独行，专横跋扈，逼着你做不愿意做的事，你会不会背弃他？\n",ob);
		tell_object(me,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
		me->set_temp("marks/wanma/answer_ma",2);
		return;
	} 	
	
	if (me->query("marks/wanma/准备杀刺客_ma") && me->query_temp("marks/wanma/江湖五毒a")
		&& me->query_temp("marks/wanma/江湖五毒b") && me->query_temp("marks/wanma/江湖五毒c")
		&& me->query_temp("marks/wanma/江湖五毒d") && me->query_temp("marks/wanma/江湖五毒e")
		&& !me->query("marks/wanma/杀客人")) {
		message_vision(CYN"
马空群看着你赞赏地说：“果然没看错你，这事办得很好，江湖五毒恶贯
满盈，的确该死。你若在他们身上找到什么重要的东西，可给我一看。”\n"NOR,ob);
		me->set_temp("marks/wanma/give_paper",1);
		return;
	}
	
	if (me->query("marks/wanma/准备杀刺客_ma")) {
		command("say 我要你追查的事有线索了么？");
		return;
	}
	
	message_vision(YEL"$N的目光凝视着远处，在每个人面前都停留了很久，最后才凝视着$n。\n"NOR,ob,me);
	message_vision(CYN"$N缓缓地说：“真正的勇气，并不是从刀剑上得来的！勇气这种东西很奇
怪，你非但看不到，感觉不到，也根本没有法子证明的，所以一个真正有勇气
的人，有时在别人眼中看来，反而像是个儒夫。你在镇上的所为我已经听说了，
你是否愿意替万马堂办一件事，一件需要真正勇气的事？\n"NOR,ob);
	tell_object(me,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
	me->set_temp("marks/wanma/answer_ma",1);
	return;
}



int do_answer(string arg)
{
	object me,ob;
	
	me=this_player();
	ob=this_object();	
	
	if(me->query_temp("marks/wanma/answer_ma")==1) {
		if(arg=="yes") {
			message_vision("\n$N坚定地点了点头说：“三堂主的事，就是在下的事。”\n"NOR,me);
			message_vision(CYN"$N说：“好，你一路前来，可曾听到鸡啼大吠之声？”\n",ob);
			message_vision(CYN"不待你回答，$N接下去说：“既有人家，必有鸡犬，边城马场之中，怎么
会没有牧大和猎狗？只因此间的三十八条猛犬，三百九十三只鸡，都已在一夜
之间，死得干干净净----被人一刀砍断了脖子，身首异处而死。鸡犬不留，赶
尽杀绝，永绝后患。。。好毒的手段。\n"NOR,ob);
			message_vision(CYN"    镇上新近来了许多生人，我想请你去察看，找出可疑之处，拿到证据后来
告诉我。你不是万马堂的人，不容易引起凶手的疑心，不过，也需小心谨慎。”\n\n"NOR,ob);
			message_vision(YEL"说完，马空群不再看你，又一动不动地陷入了沉思。\n\n"NOR,ob);
			me->delete_temp("marks/wanma/answer_ma");
			me->set("marks/wanma/准备杀刺客_ma",1);
			return 1;	
		}
		if(arg=="no"){
			message_vision("\n$N赶紧摇了摇头说：“在下武艺低微，你还是另请高明吧。”\n"NOR,me);
			message_vision(CYN"$N微微一笑说：“看来你是徒得虚名！送客！”\n"NOR,ob);
			me->delete_temp("marks/wanma/answer_ma");
			return 1;
		}
		tell_object(me,"你只能回答ｙｅｓ或ｎｏ。\n");
		return 1;
	}
	if(me->query_temp("marks/wanma/answer_ma")==2) {
		if (arg=="yes" || arg =="no") {
			if(arg=="yes") {
				message_vision("\n$N谨慎地说：“这样的人自然就不是我的朋友了。”\n"NOR,me);
			}else if (arg=="no") {
				message_vision("\n$N摇了摇头说：“无论你的朋友是好还是坏，只要他是你的朋友，你
就不能在背后给他一刀。”\n"NOR,me);
			}
			me->delete_temp("marks/wanma/answer_ma");
			me->set("marks/wanma/上楼",1);
			message_vision(YEL"\n$N不置可否地一笑：“此处耳目众多，你可在午时到我书房，我自有安排。”\n"NOR,ob);
			message_vision(YEL"$N转过身去，不再说话。\n"NOR,ob);
			return 1;
		}	
		tell_object(me,"你只能回答ｙｅｓ或ｎｏ。\n");
		return 1;
	}
	
	return 0;
}


int accept_object(object who, object ob)
{
	if (ob->query("name")=="纸片"){
		if (!who->query_temp("marks/wanma/give_paper")) {
			message_vision(CYN"$N说：“这种捕风捉影的东西也可当真？”\n"NOR,this_object());
			return 0;
		} else {
			message_vision(CYN"
马空群拿过纸看了看，意味深长地扫了你一眼。正色道：“此事真伪莫辨，
大有蹊跷。昨夜十八位马师又遭人暗算，身首异处，万马堂戒备森严，外
人极难进入。凶手必然就是新请来的几位客人之一，很可能就是他们和镇
上的江湖五毒内外勾结，所以我想请你把他们也一并除去。”\n\n"NOR,this_object());
			tell_object(who,WHT"虽然屋子里暖洋洋的，一股寒意禁不住从你心底升起。\n\n"NOR);
			message_vision("$N迟疑了一下，犹犹豫豫地说：“如果杀错了，怎么办？”\n\n"NOR,who);
			message_vision(CYN"$N微微一笑：“杀错了，可以再杀。”\n"NOR,this_object());
			message_vision(YEL"\n$N转过身去，不再说话。\n"NOR,this_object());
			who->set("marks/wanma/杀客人",1);
		}
		return 1;
	}	
	return 0;
} 

string *event1_msg=	({
	CYN"
明人不说暗话，十九年前我刺杀白天羽的那件事，的确做得不够光明磊落，
但若让我再回到十九年前，我还是会将同样的事再做一次，因为白天羽实
已将我逼得无路可走，他非但要我加入他的神刀堂，还要我将家财全部贡
献给神刀堂，他保证一定能让我名扬天下。但我到时侯只不过是他手下的
一个傀儡而已，虽然名扬天下又有什么用。白天羽并不是个卑鄙小人，他
的确是个英雄，他艺才绝艳，雄姿英发，武功之高，已绝不在昔年的上官
金虹之下。但是接近了他之后，就要完全被他指挥支配，就得完全服从他，
想我马空群又岂是寄人篱下之辈，若想恢复自由，就非杀了他不可！”\n"NOR,
		
CYN"十九年了，没想到今天他的后人，也就是白天羽和魔教公主的私生子竟然
还活着，此人身份尚不明，但总是心头一患。。。。。。"NOR,

	CYN"
马空群话锋一转道：“不过，现在对最大的威胁不是这个，而是来自万马
堂内部。你所杀的江湖五毒，以及心怀叵测的慕容明珠等人，都不是白天
羽的后人所雇，而是我最信任的兄弟，云在天和花满楼请来的。他们想借
此机会将我赶出万马堂取而代之。”\n"NOR,

CYN"马空群长叹一声：“我的根已在这里，若有人要我走，我也会死。所以，
无论谁出卖我，都得死。”\n"NOR,

CYN"“你若是能够替我除去他们，以后你就是万马堂的副堂主。”\n"NOR,

CYN"“不过，万马堂的声名不能受损，所以除你之外，我不想让任何人知道是
谁下的手，切记。”\n"NOR,

YEL"马空群挥挥手：“我累了，你走吧。办完此事后再来找我。”\n"NOR,	
	
});


void event1(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		message_vision(YEL"马空群转过身不再看你。\n\n"NOR,this_object(),me);
		me->set("marks/wanma/杀场主_ma",1);
		return;
	}
	else call_out("event1",1,me,count);
	return ;
}


string *event2_msg=	({
	YEL"
马空群望着窗外，没有说一句话，许久，许久。。。。\n"NOR,

YEL"窗外，山坡前一片大草原，接连着碧天。风吹长草，正如海洋中的波浪。\n"NOR,

CYN"过了很久，马空群才缓缓道：“现在你看见的是什么？”\n"NOR,

CYN"你回答道：“草原、大地。”\n"NOR,

CYN"马空群道：“看不看得见这块地的边？”\n"NOR,

CYN"你道：“看不见。”\n"NOR,

CYN"马空群道：“这一块看不见边际的大地，就是我的！”他神色忽然激动，
大声接着道：“大地上所有的生命，所有的财产，也全都属于我！我的根
已长在这块地里。”\n"NOR,

CYN"又过了很久，马空群的激动才渐渐平息，长叹道：“无论谁要拥有这一片
大地，都不是件容易事。你知道不知道，这一切我是怎么样得来的？”\n"NOR,

CYN"马空群突然撕开了衣襟，露出钢铁般的胸膛，道：“你再看看这是什么？”\n"NOR,

WHT"你看着他的胸膛，呼吸都似已停顿。从未看过一个人的胸膛上，有如此多
刀伤，如此多剑痕！\n"NOR,

CYN"马空群神情突又激动，眼睛里发着光，大声道：“这就是我付出的代价，
这一切都是用我的血，我的汗，还有我无数兄弟的性命换来的！所以无论
什么人，都休想将这一切从我手里抢走——无论什么人都不行！”\n"NOR,

CYN"“所以，十九年前，白天羽必须得死，现在，他的孤儿必须得死，他的外
室必须得死，该流的血，一定要流。我已经把这些人的下落打听确实，那
个孤儿是李寻欢的弟子，他就在这镇上，那个魔教公主花白凤，隐藏在万
马堂周围，你仔细搜索一定能找到。至于傅红雪，是花白凤用仇恨抚养长
大，他也不能再活下去。”\n"NOR,

CYN"马空群紧紧地盯着你说：“只有这些人都不存在了，万马堂才能永远不倒，
你我才能永远不倒。如果你能完成这最后一个使命，从此，我的就是你的，
我的一身武艺也将传授于你。”\n"NOR,
	
});


void event2(object me, int count)
{
	if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
	tell_object(me,event2_msg[count]+"\n");
	if(++count==sizeof(event2_msg))
	{
		message_vision(YEL"“你已经没有任何其他选择了，我希望你明白这个道理。”说完，马空群
便不再看你。。\n\n"NOR,this_object(),me);
		me->set("marks/wanma/准备杀主脑_ma",1);
		return;
	}
	else call_out("event2",1,me,count);
	return ;
}