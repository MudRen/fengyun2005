#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小桃红", ({ "xiao taohong","taohong" }) );
	set("title", HIR "吉祥镇第一美人"NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
    	set("long", 
    "一张无比秀丽，娇艳得象一朵待放的芍药花的脸孔，呈现在你的眼前，\n那大而分明的勾魂眸子流目四顾。看着她那灿若云霞的笑容，你不由得\n热血沸腾，真想撕开她的衣服，非礼(rape)她。\n"
);
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set ("no_arrest",1);
        set("chat_chance", 1);
        set("chat_msg", ({
		"小桃红害羞的向你说：听说最近总有人吃什么“阴阳和合散”，四处\n奸淫，我要小心了。\n",
		"小桃红向你笑了笑，一双会说话的大眼睛让你的心“扑通~扑通~”的跳。\n",
		"小桃红痴痴地望着自己光滑、晶莹的胴体，眼里忽然升起了一阵说不\n出的寂寞。\n",
        }) );

	setup();
	carry_object(__DIR__"obj/color_cloth")->wear();
}

int accept_fight(object me)
{
	command("say 小女子哪里是您的对手？");
	return 0;
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) +
"，您心真好！");
}

void init()
{
	add_action("do_rape","rape");
}

int do_rape()
{
	object me,gold;
	me = this_player();
	gold = present("gold_money", me);
	if( (string)me->query("gender") == "女性" )
		return notify_fail("你也是女人呀，怎么能干这种事情呢！！\n");
	if(!me->query_condition("hehe") && me->query("cps")>=16)
		return notify_fail("你突然觉得自己不能做那种猪狗不如的行为，急忙将伸出的手收了回来。\n");
	if (me->query_temp("inrape",1))
	{
		return notify_fail("咦，你不是正在进行中吗？\n");
	}
	me->set_temp("inrape",1);
	me->set("marks/crime","rape");
	if (me->query_condition("hehe"))
	{	
		message_vision(HIM"$N如野兽般的向$n扑过去，将$n的衣服撕烂．．．
药性使$N失去做人的理智！\n\n"NOR,me,this_object());
	}else
	{
		if (random(3) || me->query("marks/crime") == "rape")
		{
			message_vision(HIR"$N如野兽般的向$n扑过去，$n忽对$N柔媚一笑，娇声道：“不要这么性急嘛．．．”\n\n"NOR,me,this_object());
			message_vision(HIW"$N怔了怔，停下了手，喜道：“若姑娘也愿意，岂非更好。来，让我好好疼疼你。”
边说着，边凑身上前。\n\n"NOR,me);
			message_vision(HIY"$n笑得更加灿烂，悠悠道：“这位"+RANK_D->query_respect(me)+"真是有心人呢。你们还不出来吗？”\n\n"NOR,me,this_object());
			call_out("arresthim",4,me);
			return 1;

		}else
		{
			message_vision(HIM"$N如野兽般的向$n扑过去，将$n的衣服撕烂．．．\n"NOR,me,this_object());
		}
	}
	this_object()->set("chat_chance", 0);
	call_out("rapeit",20,me);
	return 1;
}

void arresthim(object me)
{
	object bukuai1,bukuai2,*inv;
	if (objectp(me) && present(me,environment()))
	{
		me->delete_temp("inrape");
		message_vision("突然从暗中跳出来几个捕快对$N冷笑道：“真是打扰了这位"+RANK_D->query_respect(me)+"的雅兴呢。”\n\n", me);
		tell_object(me,"你心中大呼不妙，可后悔已太迟。\n");
		message_vision("捕快对$N冷笑道：“我们在这里追捕着那个采花贼很久了，乖乖跟我们走吧！” \n",me,bukuai1);
		message_vision("捕快将$N押向大牢。 \n",me,bukuai1);
		me->set("vendetta/authority", 1);
		me->move("/d/jinan/laofang1");
		message_vision(HIY"$N被搜空所有的东西，一脚踢进了牢房！\n"NOR,me);
		inv = all_inventory(me);
		for(int i=0; i<sizeof(inv); i++) 
		{
			if (inv[i]->query("id")=="treasure box")	
				inv[i]->do_qqsave(me);
        	else if (!inv[i]->query("no_drop"))
        		destruct(inv[i]);
		}
	}
	return;
}


void rapeit(object me)
{
	if (living(this_object()) && objectp(me) && environment(me) == environment())
	{
		message_vision(HIR"小桃红高声呼救：救命呀！光天化日下强奸民女啦！,
$N不为所动，在$n在莹洁的胴体上喘息着，嘶咬着．．．\n\n"NOR,me,this_object());
		call_out("finishit",20,me);      
	}
	else
		remove_call_out("rapeit");
}	

void finishit(object me)
{
	object *inv;
	int i;
	if (living(this_object()) && objectp(me) && environment(me) == environment())
	{
		me->delete_temp("inrape");
		if (me->query_condition("hehe"))
		{
			message_vision(HIY"$N被药性催发的完全迷失自己．．．突然，
$N“啊~~！啊~~！”兴奋的尖叫起来，接着昏死过去．．．．\n"NOR,me);
			inv = all_inventory(me);
	        for(i=0; i<sizeof(inv); i++)
		    {
				destruct(inv[i]);
			}
			me->change_condition_duration("hehe",0);
     		me->unconcious();
     		
		}else
		{
			message_vision(YEL"$N心满意足地从$n身上爬了起来。\n\n"NOR,me,this_object());
			message_vision(HIC"$N忽然发现$n的眼光一直在死死地盯着你，那充满了愤怒与恨意不由令你打个寒战。\n\n"NOR,me,this_object());
			message_vision(HIC"$n从地上站起，冷冷地道：“你一定要为你所做的一切付出代价。”说毕，转身而去。\n"NOR,me,this_object());
		}
		me->set("vendetta/authority", 1);
		destruct(this_object());
	}		 	
    else
		remove_call_out("finishit");
}
