#include <ansi.h>

inherit NPC;
int give_soup();

void create()
{
        set_name("孟婆", ({ "mengpo", "meng"}) );
        set("gender", "女性" );
        set("age", 220);
        set("long", "
据说，孟婆生于西汉时，自小爱读经书，长大后开始颂念佛经，她在世时，既
不回忆过去，也绝不想将来，只是一心一意地劝人不要杀生，要吃素，一直到
八十一岁，仍然是处女之身。她只知道自己姓孟，于是人称她为“孟婆”。后
来孟婆入山修行，因为当时世人有知前世因着，往往泄漏天机，上天特命孟婆
为幽冥之神，掌管"YEL"醧忘之汤(ask mengpo about soup)"NOR"。
\n");
        set("combat_exp", 5000);
        set("title", WHT"【不如归去】"NOR);
        set("attitude", "friendly");
		set("no_arrest", 1);
	
		set_temp("apply/astral_vision",1);
		set("chat_chance", 1);
        set("chat_msg", ({
                "孟婆对你说：＂在下面受了不少苦吧，来碗"YEL"汤"CYN"吧！＂\n",
                "孟婆说：＂孩子，上路前喝一碗吧！＂\n",
        }) );
        set("inquiry", ([
                "明烟草":   "那是极名贵的药材，可惜对你已经没用了。\n",
                "孟婆汤" : (: give_soup:),
                "汤" : (: give_soup:),
                 "醧忘之汤" : (: give_soup:),
                 "醧忘汤" : (: give_soup:),
                "soup" : (: give_soup:)
        ]));
	setup();
	carry_object("/obj/armor/ghost_cloth")->wear();
}


int give_soup()
{
	object obj,me;
	mapping buff;
	int num,death;
	
	me = this_player();
	
	if (!me->is_ghost()) {
		command("say 孩子你又不是鬼，到这里来瞎逛什么？\n");
		return 1;
	}
		
	if (ANNIE_D->check_buff(me,"mengpo-soup")>0 || me->query_temp("marks/ready_incar"))
	{
		command("say 孩子，你已经喝过了，快赶着上路吧。。\n");
		return 1;
	}
		
	message_vision("$N以熟练的手法舀起一碗汤递给$n。\n",this_object(),this_player());
	command("say 别厌弃，快点儿喝，喝完好上路！\n");
	message_vision("$N一仰脖子，咕嘟咕嘟地将醧忘汤一饮而尽。。。。。。\n",this_player());
	

    // 每个等级死两次。。。再多就多呆些吧	
	death = me->query("KILLED");
    num = 60 + 5* (death - 2*F_LEVEL->get_level(me->query("combat_exp")));

	if (num < 60) num = 60;
	if (num > 600) num = 600;
			
	buff =
			([
				"caster":me,
				"who": me,
				"type":"mengpo-soup",
				"att":"bless",
				"name":"地域幽魂",
				"buff1": "mengpo",
				"buff1_c":1,
				"time":  num,
				"buff_msg":""NOR,
			]);
	
	ANNIE_D->buffup(buff);
	me->set_temp("marks/ready_incar",1);
	me->remove_all_killer();	// well, fix that guard problem.
	me->start_busy(2);
	call_out("faint_him", 3, me);
	return 1;
}


void faint_him(object him)
{
	int death, num;
	if (!objectp(him) || !him->is_ghost())	return ;
	him->unconcious();
	him->move(AREA_DEATH"hospital");
	message("vision",
      		"一个鬼影摇摇晃晃地走了进来，一头栽倒在忘川台下。\n", environment(him), him);
	return ;
}	

