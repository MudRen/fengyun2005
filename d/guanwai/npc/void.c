// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	set_name("无名", ({ "void" }) );
	set("class","bat");
	set("gender", "男性" );
	set("age", 24);
	set("per", 50);
	set("int", 40);
	set("str", 4);
    create_family("潇遥派", 1, "另一个祖师");
	set("score",-10000);
	set("title",HIY"天下无敌"NOR);
	set("combat_exp",0);
	set("eff_kee",1);
	set("kee",1);
	set("attitude", "friendly");
	set("long","他看似文弱书生，却在这苦寒之地不着寸缕。\n");
	set("void",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"无名叹道：如今又是七夕，朝辰已逝，佳人何方？\n",
	}) );
	set("no_arrest",1);
	set("no_heal",1);
	set("NO_KILL","你突然打了一个寒颤，不由收住了手。\n");
	setup();
	set_temp("apply/attack",-999);
	set_temp("apply/dodge",-999);
	set_temp("apply/parry",-999);
}

void init()
{	
	object ob;
	::init();
	add_action("do_accept", "answer");
	add_action("do_listskill","skills");
	add_action("do_say","say");
	if( interactive(ob = this_player()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void do_say(string arg)
{
	object me = this_player();
	if (arg != "青梅已不可能回头了，我们缘分已尽")
		return;
	if ( REWARD_D->riddle_check( me, "七夕别离")!=2)
	{
		message_vision("无名厉声说道：不、不可能的，你一定是在骗我！\n", me);
		return;
	}
//	if (me->query("annie/void") != 2)
//		return 0;
	if (query("ggyying"))
	{
		tell_object( me, "无名正在出神，没听到你在说什么。\n");
		return;
	}
	set("ggyying",1);
	me->start_busy(12);
	call_out("do_ggyy",1,this_object(),me,0);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( REWARD_D->riddle_check(ob,"七夕别离"))
		if (!query("ggyying"))
			message_vision(CYN"无名一见$N就迎了上去：这位"+ RANK_D->query_respect(ob)
				+ "，你已经见到她了么？\n"NOR,ob);
}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	write("无名目前共学过十一种技能：\n\n  基本刀法 (blade)                         - "HIW"深不可测"NOR" 400/    0\n  纵跃闪躲之术 (dodge)                     - "HIW"深不可测"NOR" 400/    0\n  内功心法 (force)                         - "HIW"深不可测"NOR" 400/    0\n＊御驾天舞 (god-dance)                     - "HIW"深不可测"NOR" 400/    0\n＊冥风急斩 (hellblade)                     - "HIW"深不可测"NOR" 400/    0\n  铁布衫 (iron-cloth)                      - "HIW"深不可测"NOR" 400/    0\n  基本轻功 (move)                          - "HIW"深不可测"NOR" 400/    0\n＊有无相生 (nullforce)                     - "HIW"深不可测"NOR" 400/    0\n  扑击格斗之技 (unarmed)                   - "HIW"深不可测"NOR" 400/    0\n＊寒虚气罩 (void-shield)                   - "HIW"深不可测"NOR" 400/    0\n＊息纳乾坤 (worldstrike)                   - "HIW"深不可测"NOR" 400/    0\n\n");
	return 1;
}

void attempt_apprentice(object me)
{
	
	if ( me->query("annie/void") + 86400 < time())		// 已经不是原来的七夕了，还没完成任务，再做一次 
	if ( REWARD_D->riddle_check(me,"七夕别离") == 1) {
		me->delete("riddle/七夕别离");
	}
	
	if (!REWARD_D->riddle_check(me, "七夕别离") 
		&& !REWARD_D->check_m_success(me,"七夕别离")
		&& !query("ggyying"))
//	if (!me->query("annie/void") && !query("ggyying"))
	{
		message_vision(CYN"\n$n看了$N一眼，目中突然流露出沉思之色。\n"NOR,me,this_object());
		message_vision(CYN"$n对$N说道：这位"+RANK_D->query_respect(me)+"可愿帮我一个忙？\n"NOR,me,this_object());
		message_vision(HIW"("HIY"answer yes"HIW"/"HIY"no"HIW")\n"NOR,me,this_object());
		me->set_temp("annie/void",1);
	} else
		message_vision(CYN"无名似乎有重重心事，对你不闻不问。\n"NOR, me);
	
}

int do_accept(string arg)
{
	object me = this_player();
	object ob;
	
	if (arg == "青梅已不可能回头了，我们缘分已尽")		{
		do_say(arg);
		return 1;
	}
	
	if (me->query_temp("annie/void")  && !query("ggyying"))
	{
		if (arg == "yes")
		{
			me->delete_temp("annie/void");
			message_vision(CYN"$n的目光变得飘移而朦胧，虚无飘渺的声音在空中回响：那是很多很多年前了．．．\n"NOR,me,this_object());
			message_vision(CYN"$n摇了摇头，回神叹道：红尘中事如同指间砂，明明盈盈握在手里的，不知觉间就已漏尽了去。\n"NOR,me,this_object());
			message_vision(CYN"$n微微笑道：若是有缘，请将这只小船送给它原本的主人．．如果没有这个缘分，我也不敢强求了。\n"NOR,me,this_object()); // lazy annie
			message_vision(CYN"\n$n交给$N一只纸折小船。\n\n"NOR,me,this_object());
			message_vision(CYN"$n忽又一叹，低声道：天下无敌．．为了这四个字，我付出了太高的代价，何苦来，何苦来？\n"NOR,me,this_object());
			me->set("annie/void", time());
			ob = new(__DIR__"obj/paperboat");
			if (ob->move(me))
				REWARD_D->riddle_set(me,"七夕别离",1);			
//				me->set("annie/void",1);
			else
				destruct(ob);
			return 1;
		}
		else if (arg == "no")
		{
			me->delete_temp("annie/void");
			ccommand("sigh");
			ccommand("flook");
			return 1;
		}
	}

	return 0;
}


void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item;
	string msg;
	string *event_msg = ({
"\n无名一怔，脸色渐渐转为一片苍白，向后连连退了几步。",
"无名跌坐在山崖边上，喃喃道：缘分．．缘分已尽．．",
"无名合了合眼，惨笑道：没有你，纵是得了天下又如何？",
"无名吐出一口鲜血，长身而起，从怀中掏出一本小册子，扬手向$n抛去。$n慌忙\n接住小册，再抬眼处，只见山风习习吹过，却哪里还有无名的影子？",
});
	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,me,target);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1+count+random(count),me,target,count+1);
	else
	{
		set("ggyying",0);
		target->add("annie/void",1);
		i = random(100);
		// L120 unarmed/parry/dodge/move/literate/force
		// L120 chanting/foreknowledge/perception/iron-cloth	
		if (i<99)		
			j=1+random(10);
		else							// L170 zensword
			j=12;
		if (!target->query("class"))	// L50 demosword
			j=13;
//		item = new("/obj/specials/moon/book" + j);
		item = new("/obj/book/moon/book" + j);
		item->move(target);
		target->set("annie/7cbook","book"+j);
		CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)在七夕秘密中得到了一本%s。\n",
	                target->query("name"),target->query("id"),item->query("name")));

		log_file("riddle/annie_log", sprintf("[%s] %s(%s)在七夕秘密中得到了一本%s。\n",
			ctime(time()), target->query("name"),target->query("id"),item->query("name")));

		REWARD_D->riddle_done(target,"七夕别离",20,1);


		destruct(this_object());
		return;
	}
	return;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

