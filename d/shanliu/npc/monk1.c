// yangfan.c

inherit NPC;

#include <ansi.h>
int answer_shanliu();

void create()
{
	set_name("无名", ({ "old monk","monk" }) );
	set("gender", "男性" );
	set("age", 78);
	set("title", YEL"多事和尚"NOR);
	set("long",
"这是个看上去很老的和尚，长得胖胖的，笑起来简直就活脱脱一个弥勒佛，面前还
摆了个木鱼。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "无名自言自语道：定要将天下举凡正义之士接引到我山流之中，为天下苍生谋福！\n",
            "无名吁了口长气，摇摇头道：可惜啊可惜，难道就没有一个可以通过山流的考验么？\n",
            "无名敲着木鱼，喃喃道：我不入地狱，谁入地狱？和尚不糊涂，谁糊涂？\n",
            "无名笑道：山流无处不在，因为她原本就在每个正义之士的心中。\n",
    }) );
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 30);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);

	set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        
        set("inquiry",	([
        	"shanliu" : (: answer_shanliu:),
        	"山流"	: (: answer_shanliu:),
		"入山流": (: answer_shanliu:),
        	]) );
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
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	//if shanliu dizi already, do nothing
	if(mapp(ob->query("organization")) && (string)ob->query("organization/org_name")=="山流" )
		return;
	if (ob->query("入山流/治愈麻风") && !ob->query_temp("入山流/取盟册") && !ob->query("入山流/取回盟册"))
	{
		message_vision(HIY"$N微微对$n笑道：不错不错，接下来让道兄考验考验施主吧！\n"NOR,this_object(),ob);
	}
}
int do_answer(string arg)
{
	object me,letter,taoist,xiucai;
	
	me=this_player();
	if(me!=query("answering_person"))
		return 0;
	if(arg=="no")
	{
		message_vision(CYN"$N对$n说道：既然如此，贫僧也不强求，你去吧。\n"NOR,this_object(),me);
		delete("answering_person");
		return 1;
	}
	if(arg=="yes")
	{
		this_object()->heart_beat();
		if(taoist=present("poor taoist",environment()))
			taoist->heart_beat();
		if(xiucai=present("xiucai",environment()))
			xiucai->heart_beat();
		message_vision(HIW"$N神色凝重地对$n说：“这里有封举荐信，你须将之尽快平安送交给
去梵音寺的山道中的牛肉铺子老板。切勿私自拆看，切记。”\n"NOR,this_object(),me);
		letter=new(__DIR__"obj/letter");
		letter->move(me);
		letter->set("送信人",me);
		me->set_temp("山流/送信",1);
		delete("answering_person");
		return 1;
	}
	return 0;
}

int answer_shanliu()
{
	object me;
	
	me=this_player();	
	if(mapp(me->query("organization")) && (string)me->query("organization/org_name")=="山流" )
	{
		say("无名道了声诺，恭敬道：请代老衲向杨施主问候。\n");
		return 1;
	}
	if (me->query("入山流/治愈麻风"))
	{
		command("pat "+me->query("id"));
		message_vision("$N微微对$n笑道：不错不错,你已过了我这一关了.\n",this_object(),me);
		return 1;
	}
	if (!me->query_temp("山流/偏厅"))
	{
		return 0;
	}
	if(me->query("combat_exp")<1000000||me->query("score")<20000)
	{
		message_vision(CYN"$N叹了口气，对$n摇了摇头。\n"NOR,this_object(),me);
		return 1;
	}
	if(me->query("山流/失败")&&(me->query("山流/失败")+86400>time()) || me->query("天宗/once"))
	{
		message_vision(HIG"$N说：“你心术不正，山流是不会收你的。”\n"NOR,this_object());
		return 1;
	}
	if (me->query_temp("入山流/治麻风",1))
	{
		message_vision("$N脸色一沉道：施主可曾救了那可怜乞丐？\n",this_object());
		return 1;
	}
	if(random(5))
		this_object()->ccommand("hmm");
	else
	{
		message_vision(HIW"$N神色凝重地注视着$n，似乎要把$n看穿。\n"NOR,this_object(),me);
		call_out("verifyJoin",2,me);
		//this_object()->set("answer_ask",me);
	}
	return 1;
}

void verifyJoin(object me)
{
	//object xiucai,taoist;
	if( !me || environment(me) != environment() ) return;
	message_vision(
HIW"$N沉默了很久才缓缓道：山流是一群人， 准确的说是一群朋友，他们的兴趣
只有一个“下地狱”。 \n"NOR,this_object());
	message_vision(
HIW"$N冷冷对$n道：要想入山流，首先要有「仁义」，这样吧，穷街路上有个患了
癫痫麻风的病人，请施主慈悲为怀，舍身救助吧！去吧！ \n"NOR,this_object(),me);
		me->set_temp("入山流/治麻风",1);
	return;
}


int do_kill(string arg)
{
	object xiucai,me,taoist;

	me=this_player();
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
	{
		me->set("山流/失败",time());
		if(xiucai=present("xiucai",environment()))
			xiucai->kill_ob(me);
		if(taoist=present("poor taoist",environment()))
			taoist->kill_ob(me);
	}
	return 0;
}

void die()
{
	object killer;
	
	killer=query_temp("last_damage_from");
	if(killer)
		killer->set_temp("山流/killmonk",1);
	::die();
}
