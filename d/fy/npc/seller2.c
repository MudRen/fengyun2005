// annie 07.2003
// dancing_faery@hotmail.com

#include <combat.h>
inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("卖面的老板娘", ({ "silent wrinkly","wrinkly" }) );
	set("long","一个愁苦的女人，整天为了生计而奔波，岁月催人老。\n");
	set("gender", "女性" );
	set("age", 35);
	set("no_curse",1);
	set("no_kill",1);
	set("no_arrest",1);
	set("long",
		" ");
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();


        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("vendor_goods", ([  
                "obj/specials/food/noodle1"					 : 10,
                "obj/specials/food/spiced1"					 : 10,
        ]) );
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
//        add_action("do_say", "say");
        add_action("do_answer", "answer");
}
/*
int do_say(string arg)
{
	object me = this_object();
	object ob = this_player();
	string a1;
	int a2;
	
	if (!arg)
		return 0;

	// annie; 防more程式解读演示
	a1 = arg[0..3];
	if (crypt(a1,"m/ZNhkGgSUjmo") != "m/ZNhkGgSUjmo")
		a2=0;
	else
		a2=4;
	if (crypt(arg[a2..a2+7],"ERALFDGn3JqKM") != "ERALFDGn3JqKM")
		return 0;
	a2+=10;
	if (crypt(arg[a2..a2+7],"pF6DHQq2KAFp6") != "pF6DHQq2KAFp6")
		return 0;
	a2+=10;
	if (crypt(arg[a2..],"SMi3blOT3v18Y") != "SMi3blOT3v18Y")
		return 0;


	if (REWARD_D->riddle_check(ob,"吃面") || REWARD_D->check_m_success(ob,"吃面"))
		return 0;
	"/cmds/std/say"->main(ob,arg);
	ccommand("emote 突然皱了皱眉头。");
	ccommand("emote 问道：你有本事吃得下去?");
	tell_object(ob,HIY"(answer "HIW"yes"HIY"/"HIW"no"HIY")\n"NOR);
    REWARD_D->riddle_set(ob,"吃面",1);
	return 1;
}
*/

int do_answer(string arg)
{
	object me = this_object();
	object ob = this_player();
	object who;
	object o1,o2,o3;
	string msg;
	int i;
	
	string a1;
	int a2;
	
	if (!arg)
		return notify_fail("你要回答什么？\n");

	
	if (REWARD_D->riddle_check(ob,"吃面")!= 1) {

		if (arg[0..1] != "一碗")
			a2=0;
		else
	
		if (arg[0..3] != "一碗金花")
		{
			command("say 好说、好说。");
			return 1;
		}
		a2+=10;
	
		if (arg[5..8] != "一碗银花")
		{
			command("say 好说、好说。");
			return 1;
		}
		a2+=10;
	
		if (arg[10..] != "一碗珠花")
		{
			command("say 好说、好说。");
			return 1;
		}

		if (REWARD_D->check_m_success(ob,"吃面")
			|| REWARD_D->riddle_check(ob,"吃面")== 2
			|| REWARD_D->riddle_check(ob,"吃面")== 3)
		{
			command("say 你已经吃过这面了。");
			return 1;
		}
		ccommand("emote 突然皱了皱眉头。");
		ccommand("emote 问道：你有本事吃得下去?");
		tell_object(ob,HIY"(answer "HIW"yes"HIY"/"HIW"no"HIY")\n"NOR);
    	REWARD_D->riddle_set(ob,"吃面",1);
		return 1;
	}
		
	who = present("carotic wrinkly",environment());
	if (ob->is_busy())
		return notify_fail("你现在正忙。\n");
	
	if (!who)
	{
		command("say 好说、好说。");
		return 1;
	}
	
	if (REWARD_D->riddle_check(ob,"吃面")!= 1) 
	{
		command("say 好说、好说。");
		return 1;
	}
		
	if (arg == "no")
	{
	    REWARD_D->riddle_clear(ob,"吃面");
		ccommand("hmm");
		return 1;
	}
	else if (arg == "yes")
	{
		ob->ccommand("say 我试试，我试试看。");
		who->add_temp("combat_no_report",1);
		who->add_temp("no_check_pfm_win",1);

	msg = HIW "\n忽然间寒光一闪，$N已经毒蛇般出手，毒蛇般向这个神情木讷的面摊老板心口击去。\n$N的出手甚至比毒蛇更快，更毒！\n\n" NOR;
	message_vision(msg,ob,who);
	COMBAT_D->do_attack(ob,who, TYPE_PERFORM);
		who->add_temp("combat_no_report",-1);
		who->add_temp("no_check_pfm_win",-1);
		if (who->query_temp("damaged_during_attack"))
		{
			msg = HIC "$n身子平转，将一根挑面的大竹筷当作了点穴撅，斜点$N的肩井穴。\n" NOR;
			message_vision(msg,ob,who);
			msg = HIY "$N的手腕一抖，寒光已刺在$n的心口上，却发出了“叮”的一声响，
就好像刺在一块铁板上。\n\n" NOR;
			message_vision(msg,ob,who);
			ccommand("emote 笑了，一张本来很平凡丑陋的脸上，一笑起来居然就露出很动人的媚态。");
			msg = CYN "  “好，好本事。”$N搬开了风灯里一张椅子，在$n面前摆上一个大碗：
“请坐，吃面。”\n\n" NOR;
			message_vision(msg,me,ob);
		    REWARD_D->riddle_set(ob,"吃面",2);

			o1=new(__DIR__"obj/dawan");
			o2=new(__DIR__"obj/paper");
			o3=new(__DIR__"obj/pearl");
			o3->move(o1);
			o2->move(o1);
			o1->move(ob);
			// ya..

		who->receive_fulling("kee",99999);
		who->receive_fulling("gin",99999);
		who->receive_fulling("sen",99999);

		}
		else
		{
			msg = HIC "$n手里一双竹筷忽然刺出，以双龙夺珠之势抢向$N的双眼。" NOR;
			message_vision(msg,ob,who);
			msg = HIY "\n$N的攻势尚未到$n的心口前，$n的竹筷已戳到了$N的眉睫间！\n" NOR;
			message_vision(msg,ob,who);
			i = ob->query("max_kee");
			i = i*9/10+random(i/10)+10;
			ob->receive_wound("kee",i,who);
			COMBAT_D->report_status(ob);
			ccommand("heng");
			ccommand("say 这么点本事也来吃面？");
		    REWARD_D->riddle_clear(ob,"吃面");
		}
		ob->perform_busy(1);
		return 1;
	}
	
	command("say 好说、好说。");
	return 1;
//	return notify_fail("你要回答什么？\n");
}
//

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		ccommand("say 这位" + RANK_D->query_respect(ob)+"，要来几碗面？牛肉面，还是猪脚面？");
    return;
}


void reset()
{
        set("vendor_goods", ([
                "obj/specials/food/noodle1"					 : 10,
                "obj/specials/food/spiced1"					 : 10,
        ]) );
}



// 凝輕·dancing_faery@hotmail.com

