// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("引路人", ({ "shanliu yinluren","yinluren","ren" }) );
        set("title","山流");
        set("gender", "男性" );

		set("no_kill",1);

		set("age",31);

        set("combat_exp", 3000000);

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("泽字服", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

int hi(object who)
{
	object me = who;
	if (!who)
		return 0;
	if (REWARD_D->riddle_check(who,"探流追源") != 1)
		return 0;
	
	message_vision("一条人影突然如鬼魅一般地出现在你眼前。\n",me);
	message_vision(CYN"$N目光如刀，上上下下地打量着$n。\n",this_object(),me);
	message_vision("$N满意地点点头，道：好，很好。\n",this_object(),me);
	message_vision("$N说道：你确定你要加入山流？(Accept yes/no)\n"NOR,this_object(),me);
	me->set_temp("annie/shanliu",1);
	add_action("do_accept","accept");
	return 1;
}



int hi2(object who)
{
	object me = who;
	if (!who)
		return 0;
	if (REWARD_D->riddle_check(who,"探流追源") != 7)
		return 0;
	
	message_vision("一条人影突然如鬼魅一般地出现在你眼前。\n",me);
	message_vision(CYN"$N一见$n，气急败坏地顿脚：你杀了九月初九，这很好，但江湖上又风传你杀了
晦气大师，这到底是怎么回事？\n",this_object(),me);
	who->start_busy(30);
	call_out("do_ggyy",2,me,this_object(),0);
	return 1;
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"$N一肚子困惑压在心底，板起脸道：顾道人明明不是九月初九，你为何骗我？",
"$n跌足长叹：看样子你是中了人家的离间之计了．",
"$n道：告诉你罢，我们山流派往幽灵山庄的潜藏秘探都死在了回风剑法之下。",
"$n道：江湖中会这回风剑法的，除了顾老道和他的徒弟，还有谁人？",
"$N一楞，想起似乎曾在城中听到过这样的流言．．．",
"$n脸色凝重：看样子你是中了人家的离间之计了，竟还刺杀了晦气大师，这让我们怎么向殷大人交代？",
"$N想起晦气大师临死前的话，疑惑道：殷大人？",
"$n叹道：你不知道，殷大人乃是晦气大师年少时留下的私子，之所以瞒着大家，只是为了不阻碍他的仕途前程。",
"$N大惊失色，$n则在原地踏着步子，似有无限烦恼。",
"$n挥手道：罢了罢了，再容你在外只是徒添麻烦而已，早知如此，倒不如让你直入山流了。",
"$n附在$N耳边，嘀咕了几句。",
});
	if (!me || !target)
	{
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	message_vision(CYN+msg+"\n"NOR,me,target);

	if (count == sizeof(event_msg)-1)
	{
		tell_object(me,"引路人在你的耳边悄声说道：他们最近的联络点设在岱庙。\n");
		tell_object(me,"引路人在你的耳边悄声说道：你去那里，在照妖镜前说出暗号，就能进到\n");
		tell_object(me,"引路人在你的耳边悄声说道：山流迷宫中去，迷宫尽头就有人接引你。\n");
		tell_object(me,"引路人在你的耳边悄声说道：暗号是："HIC"众生云云难貌相，海水滔滔难斗量\n"NOR);
		tell_object(me,"引路人在你的耳边悄声说道：迷宫的走法是"HIY"以你上一步所踏的方向为前，\n"NOR);
		tell_object(me,"引路人在你的耳边悄声说道："HIY"左右右左左左左"NOR"，"HIR"切莫踏错一步"NOR"，否则就会\n");
		tell_object(me,"引路人在你的耳边悄声说道：有性命之虞。\n");
	}


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
	else
	{
		message_vision("$N叹了口气，随即转身离去。\n",this_object(),me);
		set("ggyying",0);
		me->start_busy(1);
		me->set_temp("annie/no_leave",0);
		REWARD_D->riddle_set(me,"探流追源",8);
		destruct(target);
		return;
	}
	return;
}



int do_accept(string arg)
{
	object me = this_player();
	object ob = me;
	if (me->query_temp("annie/shanliu")==1 && REWARD_D->riddle_check(me,"探流追源") == 1)
	{
		if (arg == "yes")
		{
			ccommand("ok");
			message("vision",name()+"在"+me->name()+"耳边小声地说了些话。\n",environment(me),ob);
			tell_object(ob,"引路人告诉你：山流不收只会吃饭的废物。你的资质尚可，只是武艺有待考验。\n");
			tell_object(ob,"引路人告诉你：巴山"MAG"顾道人"NOR"乃是幽灵山庄老刀把子心腹表哥的师傅，与老刀也有勾结。\n");
			tell_object(ob,"引路人告诉你：他不但是魔教余孽，还是青龙会的杀手「"WHT"九月初九"NOR"」。\n");
			tell_object(ob,"引路人告诉你：为彻底自江湖上消失，专心为虎作伥，他正要于两天后"CYN"封剑退隐"NOR"。\n");
			tell_object(ob,"引路人告诉你：只要你能够除去巴山顾道人，证明自己的本事，我就保举你入山流。\n");
			ccommand("pat "+me->query("id"));
			REWARD_D->riddle_set(me,"探流追源",2);
			message_vision("$N对$n说道：加油，好好干！\n$N随即转身离去。\n",this_object(),me);
			destruct(this_object());
			return 1;
		}
		else if (arg == "no")
		{
			ccommand("hmm "+me->query("id"));
			message_vision("$N一语不发，转身离去。\n",this_object(),me);
			destruct(this_object());
			return 1;
		}
	}

	return 0;
}


