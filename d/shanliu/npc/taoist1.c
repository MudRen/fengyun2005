// yangfan.c

inherit NPC;

#include <ansi.h>
void create()
{
	set_name("穷道士", ({ "poor taoist","taoist" }) );
	set("gender", "男性" );
	set("age", 68);
	set("title", CYN"无聊道人"NOR);
	set("long",
"这是位衣着很是破烂的老道士,身上看上去全是老泥，眉毛胡子都脏兮兮的粘到了一块,
尽管如此,但乍一看去,却叫人莫名中生出股景仰的感觉。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "穷道士合十道：红花绿叶青莲藕，三教本来是一家，芸芸众生，谁不是我山流之友？\n",
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
          call_out("greeting", 2, ob);
     }
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query("入山流/取回盟册"))
	{
		return;
	}
	if (ob->query("入山流/治愈麻风"))
	{
		if (ob->query_temp("入山流/取盟册"))
		{
			message_vision(
"\n$N微微笑道：这位"+RANK_D->query_respect(ob)+"拿到天宗盟册了么？\n",this_object());
		}else
		{
			message_vision(
HIY"$N捻了捻长髯，对$n笑道：入了山流，就得完全牺牲自己，就得要有下地狱
的精神，赴汤蹈火也万死不辞！\n"NOR,this_object(),ob);
			message_vision(
HIY"$N接着一字字对$n道：好，那就要考验阁下的「胆识」了！ \n"NOR,this_object(),ob);
			call_out("test_danshi",3,ob);
		}
	}
	return;
}

void test_danshi(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision(
HIY"$N沉吟片刻后,对$n道：据传天宗的神秘宗主却是当今武林盟主连城璧，有一
卷【天宗盟册】记录了天宗在江湖中的盟友，似乎藏在无垢山庄。请阁下帮山流
取回，若能取回，这「胆识」一关，自然就过了。 \n"NOR,this_object(),ob);
	ob->set_temp("入山流/取盟册",1);
}

int accept_object(object who, object obj)
{
	object xiucai;
	if (obj->query("name")==HIR"天宗盟册"NOR)
	{
		if (who->query_temp("入山流/取盟册"))
		{
			who->delete_temp("入山流/取盟册");
		}
		message_vision(
HIC"\n$N哈哈笑道：好，好，好！有了天宗盟册，天宗有望一举破之！\n"NOR,this_object());
		message_vision(
HIC"\n$N拍了拍$n，颔首笑道：那就再请秀才老兄考验考验你吧！\n\n"NOR,this_object(),who);
		who->set("入山流/取回盟册",1);
		if (xiucai = present("xiucai",environment()))
		{
			xiucai ->greeting(who);
		}
		return 1;
	}
	return 0;
}

int do_kill(string arg)
{
	object xiucai,me,monk;

	me=this_player();	
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
	{
		me->set("山流/失败",time());
		if(xiucai=present("xiucai",environment()))
			xiucai->kill_ob(me);
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
		killer->set_temp("山流/killtaoist",1);
	::die();
}
