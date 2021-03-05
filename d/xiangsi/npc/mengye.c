// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();
int look_stone2();
int look_stone3();

void create()
{
	set_name("简繁星", ({ "jian fanxing", "fanxing","jian" }) );
	set("class","moon");
	set("gender", "女性" );
	set("age", 25);

	set("nickname",HIW"萼似寒山雪，枝如烈士弓"NOR);
	set("title","皓月宫"NOR);

	set("per",80);

	set("attitude", "friendly");

	set("long","她一身白衣如雪、脑後挽起的发髻间还簪着一朵小白花。\n");

	set("inquiry",([
		"李坏": (: look_stone :),
		"月神": (: look_stone :),
		"指望": (: look_stone2 :),
		"药": (: look_stone3 :),
		"失了踪影":	"失踪的那天晚上，根本就没有一个人进过药房。\n不是人偷的，莫非还会是猫狗之流？\n",
       	"失踪": 	"失踪的那天晚上，根本就没有一个人进过"WHT"药房"CYN"。\n不是人偷的，莫非还会是猫狗之流？\n",
       	"清明桃花瓣": 	"桃花瓣需得"WHT"清明"CYN"那天新采，且不可沾了刀兵之气，才能入得药方。\n",
       	"龟山茉莉花": 	WHT"龟山"CYN"几年前着了祝融，满山都烧得焦了，我们寻寻觅觅好久才找到一些干花，如今又哪里寻去？\n",
       	"白山千鸟": 	"这花相思岭上就有，喜欢长在"WHT"雷打石"CYN"后冰镜崖上。\n",
       	"三九寒泉水": 	"泉水就是宫中那口，只是需要"WHT"三九天"CYN"的才行。\n",
       	"百年冰棱": 	"冰棱倒也好办，"WHT"雪洞"CYN"中多得是。\n",
       	"玉颈金羽": 	"唉，这是大家当时从一个"WHT"古董商人"CYN"手里买得，不知他现在人在何方……\n",
       	"钜铸真录": 	"那本书还在"WHT"书库"CYN"之中，你只须寻得前六味药材，随时可以再造。\n",
		"清明":			"清明是二十四节之一，隶属春部。\n",
		"龟山":			"此处东渡海外，行船十多天，便可以到龟山了。\n",
		"雷打石":		"莫非你上山时不曾路过？\n",
		"雪洞":			"壶仙岩那边过去那个便是了。\n",
		"古董商人":		"那古董商人身穿一件元宝大褂，头上戴了顶五花金绣冠，自称是西域人士。\n",
		"书库":			"便是无歌哥哥所掌的书库了。\n",
		"药房":			"便是忘机书馆的旁边了，自从丢了药后，无歌哥哥就把里面改作了藏书的地方。\n",
		"花语":			"同心而离居，忧伤以终老．．．\n",
		"世界之颠":		"那便是这世上离天河最近的地方了。\n",
		"三九天":		"三九寒冬，如果你连这都不知道，也就不必再白费心思了。\n",
		"小姐":			(: look_stone :),
		"薛青碧":		"一剑飞雪薛青碧是我们小姐的父亲。\n",
		]) );

	set("death_msg",CYN"\n简繁星挣扎道：小姐．．繁星往后．．不能．．跟着妳了．．．．要．．多保重．．
简繁星的嘴边渗出缕缕鲜血，慢慢倒了下去。\n"NOR);

	set("chat_chance", 1);
	set("chat_msg", ({
		"简繁星向你笑道：知道雪原鸢尾的花语是什么吗？\n",
		"简繁星望着远方山峦，悠悠道：若是在世界之颠与人相依相伴，应是何等的温暖？\n",
		"简繁星说道：传说在七夕的晚上，到这世上离天河最近的地方去，就会收集到织女的泪水。\n",
	}) );

	set("combat_exp", 400000);

	set_skill("blade", 1);
	set_skill("chillblade", 100);
	map_skill("blade","chillblade");

	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("stormdance", 100);
	map_skill("dodge","stormdance");
	map_skill("move","stormdance");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.shuangtianxuewu" :),
	}) );

	setup();

	carry_object(__DIR__"obj/iceblade")->wield();
	carry_object(__DIR__"obj/wcloth2")->wear();
	carry_object(__DIR__"obj/flower")->wear();

}

int kill_ob(object who)
{
    command("loveme "+who->query("id"));
	ccommand("perform dodge.shuangtianxuewu");
	::kill_ob(who);
	return 1;
}

void killed_enemy(object who)
{
    command("admire2 "+who->query("id"));
}


int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();
	me->add_temp("annie/riddle/moonmaster",1);
	i=me->query_temp("annie/riddle/moonmaster");

	if (me->query("combat_exp") < 2600000)	// 过1.2M不怕死就可以去leh
	{
		ccommand("emote 摇头道：你还小．．便说与你听，也是没有用的．．（需60级）");
		return 1;
	}


	if (REWARD_D->riddle_check(me,"两世恩怨") == 3)
	{
		ccommand("say 什么？");
		ccommand("say 小姐……小姐她怎么这么说？");
		ccommand("say 这下糟了、这下糟了，这可怎么办才好……");
		ccommand("emote 容色惨变，咬著下唇苦思。");
		REWARD_D->riddle_set(me,"两世恩怨",4);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"两世恩怨") == 2)
	{
		ccommand("say 快把药拿去给小姐吧。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 99 || REWARD_D->check_m_success(me,"两世恩怨") >0)
	{
		ccommand("say ……。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 4)
	{
		ccommand("emote 突地一拍手道：对了，不如你去问问苏萝姐罢。");
		return 1;
	}

	if (i >= 6)
		me->set_temp("annie/riddle/moonmaster",5);
	msg="罢了，罢了，原本还有些"WHT"指望"CYN"，如今却只能听天由命。";
	switch (i)
	{
	case 1:
		msg="李家杀了小姐的先辈，父债子偿，小姐找他报仇本是天经地义。";
		break;
	case 2:
		msg="只是，只是……唉……";
		break;
	case 3:
		msg="……小姐和他原本是一对璧人，如今却走到了这个地步。真是世事难料，天意弄人。";
		break;
	case 4:
		msg="冤孽，冤孽，明明是前生的恩怨，却留下这世的纠缠。";
		break;
	}
	message_vision(CYN"$N说道："+msg+"\n"+NOR,this_object(),this_player());
    return 1;
}

int look_stone2()
{
	object me;
	int i;
	string msg;
	me=this_player();
	if (REWARD_D->riddle_check(me,"两世恩怨") == 2)
	{
		ccommand("say 快把药拿去给小姐吧。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 99 || REWARD_D->check_m_success(me,"两世恩怨") >0)
	{
		ccommand("say ……。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 4)
	{
		ccommand("emote 突地一拍手道：对了，不如你去问问苏萝姐罢。");
		return 1;
	}
	i=me->query_temp("annie/riddle/moonmaster");
	if (i < 5)
		return 0;

	me->set_temp("annie/riddle/moonmaster",6);
	REWARD_D->riddle_set(me,"两世恩怨",1);
	msg="大家辛辛苦苦调出了"WHT"药"CYN"，还没交给小姐，就莫名奇妙的"WHT"失了踪影"CYN"。";
	message_vision(CYN"$N说道："+msg+"\n"+NOR,this_object(),this_player());
    return 1;
}

int look_stone3()
{
	object me;
	int i;
	string msg;
	me=this_player();

	if (REWARD_D->riddle_check(me,"两世恩怨") == 2)
	{
		ccommand("say 快把药拿去给小姐吧。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 99 || REWARD_D->check_m_success(me,"两世恩怨") >0)
	{
		ccommand("say ……。");
		return 1;
	}
	if (REWARD_D->riddle_check(me,"两世恩怨") == 4)
	{
		ccommand("emote 突地一拍手道：对了，不如你去问问苏萝姐罢。");
		return 1;
	}

	i=me->query_temp("annie/riddle/moonmaster");
	if (i < 6)
		return 0;

	me->set_temp("annie/riddle/moonmaster",7);
	msg="那是用"WHT"清明桃花瓣"CYN"、"WHT"龟山茉莉花"CYN"、"WHT"白山千鸟"CYN"配以"WHT"三九寒泉水"CYN"、\n"WHT"百年冰棱"CYN"，再用"WHT"玉颈金羽"CYN"为引、"WHT"钜铸真录"CYN"为方而制成的一种奇药，服用后一\n刻钟内气息全无，与死人一般无异。";
	message_vision(CYN"$N说道："+msg+"\n"+NOR,this_object(),this_player());
    return 1;
}


int accept_object(object me, object obj)
{
	if (obj->query("name") == "小纸袋" && obj->query("real") == 3)
	{
		if (REWARD_D->riddle_check(me,"两世恩怨") == 1 && me->query_temp("annie/xiangsi_master") == 4)
		{
			ccommand("say 咦？这……这……这就是我们辛苦制出的逃情奇药，你是在哪里寻得？");
			ccommand("say 快，快拿去给小姐。");
			ccommand("say 苍天有眼，这下可有救了。");
			REWARD_D->riddle_set(me,"两世恩怨",2);
			return 0;
		}
		return 0;
	}
	command("smile");
	command("say 多谢，多谢！");
	return 1;
}

