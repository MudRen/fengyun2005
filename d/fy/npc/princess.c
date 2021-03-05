// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

inherit NPC;
// inherit F_ANNIE;
#include <ansi.h>

string quest();
int give_me_it_ling(object me);

void create()
{
	object weapon;
        set_name("年轻人", ({ "youngman" }) );
        set("gender", "男性" );
        set("long","
他长着张瓜子脸，一双丹凤眼柔美动人，却自有种不怒而威的气势。
"
	);

			set("title","白云深处");
			set("nickname",CYN"冰炭化作妙莲华"NOR);
	
      set("age", 21);
			set("per",40);
			set("str",1);
      set("attitude","friendly");
        
      set("combat_exp", 0);
        
      set("score", 20000);

			set("no_arrest",1);

				set("inquiry", ([
	       	"差使": 	(: quest :),
	       	"差事": 	(: quest :),
	       	"chashi": (: quest :),
	       	"chaishi": (: quest :),
	       	"cha shi": (: quest :),
	       	"chai shi": (: quest :),
         ]) );
		

        setup();
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("嫩黄凤袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->set("armor_worn","懒懒地披着件");
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name(HIY"云华金翎"NOR, ({ "feather" }) );
		weapon->set("value",0);
		weapon->set("armor_worn","发上斜簪着一根");
		weapon->wear();

}




void init(){
	::init();
	add_action("do_look", "apprentice");
}


string *cishi= ({
"淄","赵","德","滨","保","并","汾","泽","辽","宪","岚","石","虢","坊","丹",
"阶","乾","商","宁","原","庆","渭","仪","环","楚","泰","泗","濠","光","滁","通","黄","真",
"舒","江","池","饶","信","太平","吉","袁","抚","筠","岳","澧","峡","归","辰","衡","永","全",
"郴","邵","常","秀","温","台","衢","睦","处","南剑","汀","漳","绵","汉","彭","邛","蜀","嘉",
"简","黎","雅","维","茂","资","荣","昌","普","渠","合","戎","泸","兴","剑","文","集","壁",
"巴","蓬","龙","施","万","开","达","涪","渝","昭","循","潮","连","梅","英","贺","封","南雄",
"端","新","康","恩","春","惠","韶","梧","藤","龚","象","浔","贵","宾","横","融","化","窦",
"高","雷","南仪","钦","郁林","廉","琼","崖","儋","万安"
});

string *tuanlian= ({
"单","濮","潍","唐","祁",
"冀","隰","忻","成","凤","海","鼎"
});

string *fangyu= ({
"齐","济","沂","登","莱","郑",
"汝","蔡","颍","均","郢","怀","卫","博","磁","洺","棣","深","瀛","雄","霸","莫","代","绛",
"解","龙","和","蕲","舒","复","眉","象","陆","果"
});

string *guancha= ({
"青","兖","徐","曹","郓","襄","邓","随","金","房","许","郑","滑","孟","陈","汝","澶","沧",
"恩","镇","相","定","邢","浚","赵","晋","潞","麟","府","同","华","耀","延","鄜","庆","邠","宁","秦","渭","泾","熙","乐",
"西宁","杭","越","苏","润","湖","婺","明","严","扬","亳","宿","寿","庐","光","升","宣","洪","赣","荆",
"鄂","安","鼎","潭","福","建","泉","益","嘉","梓","遂","泸","梁","利","洋","阆","剑","夔","黔"
});

string *jiedu= ({
"泰宁","武宁","彰信","镇海","天平","安化","武成","忠武","镇海","河阳三城",
"山南东道","武胜","崇信","昭化","保康","天雄","成德","镇宁","彰德","永清","安国",
"威德","静难","彰化","雄武","保大","淮南","忠正","保信","保静","集庆","建康","宁国",
"镇南","昭信","荆南","宁海","武昌","安远","武安","镇东","平江","镇江","宣德","保宁",
"康国","威武","建宁","益州","安静","武信","山南西道","昭武","安德","武定","宁海","宁江",
"武康","清海","静江","宁远","建武","定南","静海","西河","归义","保顺","彰国","威城",
"昌化","丰州","天德","振武","大同"
});

int do_look(string arg)
{
	object me=this_player(),student;
	int exp;
	string g;
	student=me;
    exp = (int) student->query("combat_exp");
	if (!arg)
		return 0;
	if(present(arg,environment()) == this_object())
	{
		if (me->query("class") != "official")
		{
			ccommand("emote 瞅了"+me->name()+"一眼，轻笑道：你既非官家门下，何来求我？");
			return 1;
		}
		if (me->query("family/master_name") != "常胜将军")
		{
			ccommand("emote 瞅了"+me->name()+"一眼，挑挑眉毛微笑：你的资历还太浅哪．．．");
			return 1;
		}

		g=me->query("title");

		if (exp<= 1024000 && strsrch(g,"州刺史")!=-1)
		{
			ccommand("emote 瞅了"+me->name()+"一眼，摇头道：你的资格还不够加封的啊。");
			return 1;
		}
		else if (exp<= 2048000 && strsrch(g,"州团练使")!=-1)
		{
			ccommand("emote 瞅了"+me->name()+"一眼，摇头道：你的资格还不够加封的啊。");
			return 1;
		}

		else if (exp<= 3315000 && strsrch(g,"州防御使")!=-1)
		{
			ccommand("emote 瞅了"+me->name()+"一眼，摇头道：你的资格还不够加封的啊。");
			return 1;
		}

		else if (exp<= 5312000 && strsrch(g,"州观察使")!=-1)
		{
			ccommand("emote 瞅了"+me->name()+"一眼，摇头道：你的资格还不够加封的啊。");
			return 1;
		}

		else if (exp<= 8800000 && strsrch(g,"节度观察留后")!=-1)
		{
			ccommand("emote 瞅了"+me->name()+"一眼，摇头道：你的资格还不够加封的啊。");
			return 1;
		}
		else if (strsrch(g,"节度使")!=-1)
		{
			ccommand("emote 瞅了"+me->name()+"一眼，冷笑道：你如今已位极人臣，怎得还如此不知足？");
			return 1;
		}

		        if( exp <= 1024000 ) 
					g=cishi[random(sizeof(cishi))]+"州刺史";
				else if ( exp <= 2048000 ) 
					g=tuanlian[random(sizeof(tuanlian))]+"州团练使";
				else if ( exp <= 3315000 ) 
					g=fangyu[random(sizeof(fangyu))]+"州防御使";
				else if ( exp <= 5312000 )
					g=guancha[random(sizeof(guancha))]+"州观察使";
				else if ( exp <= 8800000 ) 
					g=jiedu[random(sizeof(jiedu))]+"节度观察留后";
				else               
					g=jiedu[random(sizeof(jiedu))]+"节度使";

			ccommand("emote 瞅了"+me->name()+"一眼，偏头道：那么．．．便封你做个．．．"+HIG+g+NOR+CYN+"罢。");
			g="朝廷命官 "+g;
			me->set("title",g);

		return 1;
	}
	return 0;
}


string quest()
{
	string arg, room_name, *files,orig_name;
	int i, n, m, size, reward, exp;
	object room, silver,room2;
	object me = this_player();
	string *list1=({
	"徘徊的怨魂",
	"慌张的怨魂",
	"愤恨的怨魂",
	"静默的怨魂",
	"错乱的怨魂",
	"迷失的怨魂",
	"游荡的怨魂",
	});

	if (me->query("quest/short") == "去白云行馆打听差事")
	{
		if (me->query("quest/duration") == 964)	// 雾影奇邪
		{
				n=2+random(3);
				me->set("annie_quest/name","相思岭除雾影奇邪");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到相思岭杀XXX"+WHT"个雾影奇邪"NOR);
				me->set("annie_quest/target","雾影奇邪");
				me->set("quest/short", WHT"到相思岭杀"+n+WHT"个雾影奇邪"NOR);
				me->set("quest/location", "相思岭");
				me->set("quest/difficulty",n*50);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多１分钟
				me->set("quest_time",time());

				arg="相思岭冰洞中据闻有怪物雾影奇邪出没，还请前去锄灭。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}


		if (me->query("quest/duration") == 963)	// 雪域阴魂
		{
				n=2+random(3);
				me->set("annie_quest/name","相思岭除雪域阴魂");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到相思岭杀XXX"+WHT"个雪域阴魂"NOR);
				me->set("annie_quest/target","雪域阴魂");
				me->set("quest/short", WHT"到相思岭杀"+n+WHT"个雪域阴魂"NOR);
				me->set("quest/location", "相思岭");
				me->set("quest/difficulty",n*50);	// 每多一个就多30% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多１分钟
				me->set("quest_time",time());

				arg="相思岭冰洞中据闻有怪物雪域阴魂出没，还请前去锄灭。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}
		if (me->query("quest/duration") == 962)	// 一穷二白
		{
				n=2+random(3);
				me->set("annie_quest/name","相思岭除一穷二白");
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到相思岭杀XXX"+WHT"个一穷二白"NOR);
				me->set("annie_quest/target","一穷二白");
				me->set("quest/short", WHT"到相思岭杀"+n+WHT"个一穷二白"NOR);
				me->set("quest/location", "相思岭");
				me->set("quest/difficulty",n*50);	// 每多一个就多50% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多１分钟
				me->set("quest_time",time());

				arg="相思岭冰洞中据闻有怪物一穷二白出没，还请前去锄灭。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}

		if (me->query("quest/duration") == 961)	// 万岳峰回
		{
				i = random(7);
				n=2+random(3);
				me->set("annie_quest/name","明霞山杀"+list1[i]);
				me->set("annie_quest/number", n);
				me->set("annie_quest/short", WHT"到明霞山超渡XXX"+WHT"个"+list1[i]+NOR);
				me->set("annie_quest/target",list1[i]);
				me->set("quest/short", WHT"到明霞山超渡"+n+WHT"个"+list1[i]+NOR);
				me->set("quest/location", "明霞山");
				me->set("quest/difficulty",n*50);	// 每多一个就多50% reward
				me->set("quest/duration",900+n*180);	// 每多一个就多１分钟
				me->set("quest_time",time());
				arg="明霞山阴近日不甚太平，还请前去高塔之中，渡化几个"+list1[i]+"。\n";
				tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
				return arg;
		}


		return "最近好象没什么事情，你不如趁机找巫师泡泡茶吧。\n";	// error mark.
	}
	else
		return "action年轻人轻笑摇头：近来天下太平，并无差使。";
	
	return " ";
}

int give_me_it_ling(object me)
{
	object x;
	x=new(__DIR__"obj/she_ling");
	if (!x->move(me))
		x->move(environment(me));
	message_vision("年轻人用洪亮的嗓音说道："CYN"“朕！深感其孝，特赦其父，你去吧。”"NOR"\n段公公随后将皇上御书递到$N的手中。\n",me);
	return 1;
}


int accept_object(object who, object ob)
{
	object me = who;
	if (ob->query("name") == HIW"奏折"NOR && REWARD_D->riddle_check(me,"孝感苍天") == 5)
	{
		if (ob->query("lore"))
		{
			message_vision("年轻人接过"+ ob->name() + "，因是子民的冤情，非常重视。”\n",me);
			message_vision("年轻人阅完奏折，十分同情这个小姑娘，又觉得她说的有道理。\n", ob, me);
			REWARD_D->riddle_set(me,"孝感苍天",6);
			give_me_it_ling(me);
			return 1;
		}
	}
	return 0;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

//2;clone /d/cyan/npc/maze_guard5;call mingyue->stop_busy();kill ghost;3;4;smash ghost


