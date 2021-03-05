// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void create()
{
	object weapon;
	set_name("郝中平", ({ "hao zhongping","hao","zhongping","haozhongping" }) );
	set("class","beggar");
	set("gender", "男性" );
	set("age", 16);

	set("nickname",MAG"小乞儿"NOR);
	set("title","丐帮门下"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("long","看起来又脏又臭的小乞儿，一双乌溜溜的大眼却无端灵动。\n");

	set("inquiry",([
		"饮血平寇": (: look_stone :),
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"郝中平坐在地上偏头看你：这位大爷何不施舍一些？\n",
		"郝中平唱道：小小姑娘做好事，施舍化子一碗饭～\n",
	}) );

	set("combat_exp", 6000000);

	set_skill("staff", 200);
	set_skill("dagou-stick", 220);
	map_skill("staff","dagou-stick");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "staff.banzijue" :),
	}) );

	setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name(YEL"戳狗棍"NOR, ({ "stick" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("破布衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();
}



int accept_object(object who, object ob)
{
	message_vision(CYN"郝中平欠欠身子道：大爷好心定当会有好报。\n"NOR,who);
	return 1;
}

int do_ans(string arg)
{
	object me = this_player();
	if (arg != "yes" && arg != "no")
		return notify_fail("你要回答什么？\n");
	if (me->query("annie/b") || REWARD_D->riddle_check(me,"韶光虚掷") != 5)
		return notify_fail("甚么？\n");

	if (arg == "no")
	{
		ccommand("duh");
		me->set("annie/b",1);
		return 1;
	}
	if (REWARD_D->riddle_check(me,"韶光虚掷") == 5) 
		REWARD_D->riddle_set(me,"韶光虚掷",6);
	ccommand("ok");

	
	tell_object(me,HIY"你的任务改变了！\n"NOR);

	me->set("quest/short", WHT"去"CYN"凌云顶"WHT"参加饮血平寇大会"NOR);
	me->set("quest/location", "somewhere");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());


	return 1;
}

int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();

	if (me->query("annie/b") || REWARD_D->check_m_success(me,"相会"))
	{
		message_vision(CYN"郝中平对$N霎霎眼睛：我听说那会上可危险的很，你．．．\n"NOR,me);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"韶光虚掷") == 6) 
	{
		if (me->query("annie/a") && !REWARD_D->check_m_success(me,"溜过去"))
		{
			message_vision(CYN"郝中平奇道：疑？你怎会没有请柬？\n"NOR,me);
			message_vision(CYN"郝中平拍了拍脑门：其实没有请柬也并无所谓，那两个和尚可粗枝大叶得很，\n只消低下身子，从他们身边"WHT"溜过去"CYN"就好。"NOR,me);
			REWARD_D->riddle_done(me,"溜过去",0,1);


			return 1;
		}
		message_vision(CYN"郝中平眨眼道：那我们便在饮血平寇大会上见了。\n"NOR,me);
		return 1;
	}


	if (REWARD_D->riddle_check(me,"韶光虚掷") == 4 || REWARD_D->riddle_check(me,"韶光虚掷") == 5) 
	{
		message_vision(CYN"郝中平偏过头上下打量$N，露齿一笑：这位大哥可有兴致与小乞儿一同在大会上．．．？\n"HIW"("HIY"Answer "HIY"yes"HIW"/"HIY"no"HIW")\n"NOR,me);
		add_action("do_ans","answer");
		REWARD_D->riddle_set(me,"韶光虚掷",5);
		return 1;
	}

	message_vision(CYN"郝中平说道：诶，你还在这里做什么？快动身啊。\n"NOR,me);
	return 1;

}

