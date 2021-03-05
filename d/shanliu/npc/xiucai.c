// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("酸秀才", ({ "xiucai" }) );
	set("gender", "男性" );
	set("age", 68);
	set("title", GRN"落魄书生"NOR );
	set("long",
"这是个不拘小节的穷酸秀才,似乎已经醉得有些摇摇欲坠,也没什么出众的地方,但偶尔
微张双眸,那眼光却犀利如电。手里捧着本破书,嘴里不停地嘟囔着什么。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "酸秀才看书看得眉飞色舞，突然重重的一拍桌子，大声笑道：好一个张子房，好一
个朱亥，这一椎虽然不中，亦足以惊天地而泣鬼神……痛快呀痛快，当浮仰一大白。\n",
    }) );
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 30);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);
	set("ALWAYS_ACTIVE",1);
	set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
	setup();
        carry_object("obj/armor/cloth")->wear();

}


void init()
{
	object ob;
	::init();
	add_action("do_answer","answer");
	add_action("do_kill","kill");
	if( interactive(ob = this_player()) && !is_fighting() )
	{
          remove_call_out("greeting");
          call_out("greeting", 1, ob);
     }
}

int do_answer(string arg)
{
	object letter, box,me;
	me=this_player();
	if (!me->query_temp("xiucai_ask"))
	{
		return 0;
	}
	if (arg !="yes" && arg!="no")
	{
		return notify_fail("你只可以回答yes或no\n");
	}
	me->delete_temp("xiucai_ask");
	if (arg = "yes")
	{
		message_vision(
HIR"$N沉思了片刻，郑重地道：我辈中人，有所为而有所不为，我，愿入山流！ \n"NOR,me);
		message_vision(
HIC"\n$N击案笑道：痛快啊痛快！这里是一封举荐信，你须将之尽快平安送交给
去梵音寺的山道中的牛肉铺子老板。切勿私自拆看，切记。 \n"NOR,this_object());
		letter = new(__DIR__"obj/letter");
		letter->set("送东西人",me);
		letter->move(me);
		message_vision("$N递给$n一封信\n\n",this_object(),me);
		message_vision(
HIC"$N拧开酒葫芦，咕嘟咕嘟喝了几大口又道：且慢，这个檀木盒有我山流各处弟
子在江湖各处辛苦经营募集而来的银票百万两，你且一并送至七个半那老鬼处。\n"NOR,this_object());
		box = new(__DIR__"obj/tanmubox");
		box->set("送东西人",me);
		box->move(me);
		message_vision("$N递给$n一个檀木盒。\n\n",this_object(),me);
		me->set_temp("入山流/送东西",1);
	}
	else
	{
		message_vision("$N沉吟许久，踌躇道：这。。。还是容我再仔细思虑一番。 \n",me);
		me->delete("入山流/取回盟册");
		me->delete("入山流/治愈麻风");
	}
	return 1;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("入山流/治愈麻风") && ob->query("入山流/取回盟册"))
	{
		if (ob->query_temp("入山流/送东西"))
		{
			message_vision("$N问$n道：东西送到了没有？\n",this_object(),ob);
		}else
		{
			message_vision(
HIC"$N眉飞色舞对$n道：你再考虑考虑，一入山流，便永无安宁之日了，很多事
情，无论多困难，多危险，你都得不在乎，连死也不在乎。而山流中人，更要谨记「诚信」二字。 \n"NOR,this_object(),ob);
			message_vision(
HIC"稍倾，$N冷冷地盯着$n，一字一字道：“你做的到么？你确定要加入[山流]么？
(answer yes or no)\n"NOR,this_object(),ob);
			add_action("do_answer","answer");
			ob->set_temp("xiucai_ask",1);
		}
	}
}

int do_kill(string arg)
{
	object taoist,me,monk;

	me=this_player();	
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
	{
		me->set("山流/失败",time());
		if(taoist=present("poor taoist",environment()))
			taoist->kill_ob(me);
		if(monk=present("old monk",environment()))
			monk->kill_ob(me);
	}
	return 0;
}


void die()
{
	object killer;
	
	killer=query_temp("last_damage_from");
	if(killer)
	killer->set_temp("山流/killxiucai",1);
	::die();
}
