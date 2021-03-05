// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

#include <ansi.h>
inherit NPC;
inherit F_LEVEL;
object ob;
int  do_ji(string arg);
int give_me_it(object me);


void create()
{
	set_name("段公公", ({ "duan gonggong","duan","gonggong" }) );
	set("gender", "男性" );
	set("title", HIR "掌事公公"NOR);
	set("age", 52);
	set("long","段公公是当今皇上面前的一大红人，虽然只是个从三品儿的官衔，
却掌管着宫里铸造、雕刻金玉器物的活儿，借着皇上的名义，从
各地搜刮了许多"WHT"奇珍异宝"NOR"。\n");

	set("inquiry",([
		"奇珍异宝" : "恩，最近从西域来了一批精铁，是打造武器的上好材料。\n",
		"精铁"     : "西域精铁，乃是是打造武器的上好材料。\n",
		"打造武器" : "唯有宫里御聘的大法师红云上人才知如何锻造，寻常工匠是不行的，！\n",
		"红云上人" : "红云上人从不出宫，你若有意，我或可行个方便。\n",
		"行个方便" : "精铁数量有限，红云上人更不轻易出手，寻常人没这个机遇。\n",
		"方便"     : "精铁数量有限，红云上人更不轻易出手，寻常人没这个机遇。\n",
		"寻常人"   : "action段公公看了看你，嘴角撇了撇不说话。\n",
		"机遇"     : "说难也不难，精铁加上工场开销，总要那么千两黄金，再加上为皇上效力过（task）。",
		"task"     : "每打造一次，至少需完成两千个任务（task），到时候就可以来找我帮忙（temper）了。\n",	
		"temper"   : "就是打造武器了，这都不懂？看来你阴沟里蓄没学好。\n",
	]) );

	set("combat_exp", 50000);
	set("str",30);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{       
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
	add_action("do_ji","temper");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || random(10) ) {
		return;
	}
	message_vision(CYN"段公公慢条斯理地看了你一眼，满是不屑的神色。\n"NOR, this_object()); 
}

int do_ji(string arg)
{
	int ji2, n;
	int gold;
	int cost =1;
	int i, j, base, current;
	string id, name, broken;  

	object me = this_player();

	if( me->is_busy() ) {
		return notify_fail("你上一个动作还没有完成。\n");
	}
	if( !arg ) {
		return notify_fail("你要锻造什麽武器？\n");
	}
	if( !objectp(ob = present(arg, me)) ) {
		return notify_fail("你身上没有这样东西。\n"); 	
	}
	if( !ob->query("weapon_prop") ) {
			return notify_fail("你只能锻造可当作武器的东西。\n");
	}
	if( ob->query("equipped") ) {
			return notify_fail("你不可锻造装备著了的武器。\n");
	}
	if( !ob->query("owner") ) {
		return notify_fail("你只可锻造自己打造的武器。\n");
	}
	sscanf(ob->query("name"), "%s的", broken);
	if( broken == "断掉" ) {
		return notify_fail("你不可锻造损坏了的武器，请去张铁匠那里修好武器再来。\n");
	}
	base = (int)ob->query("base_damage");
	current = (int) ob->query("weapon_prop/damage");
	if( base != current ) {
		return notify_fail("你不可锻造损坏了的武器，请去张铁匠那里修好武器再来。\n"); 
	}
	if( me->query("deposit") < 10000000 ) {
		tell_object(me, CYN"段公公笑眯眯地说：这锻造兵器可是极费人工的活儿，至少要有千两存款。\n"NOR);
		return 1;
	}
	if( me->query("TASK") < 2000 ) {
		tell_object(me,CYN"段公公摇摇头说：你没为皇上做什么事儿，忠奸难辨啊。（至少需2000个使命）\n"NOR);
		return 1;
	}
			
	ji2 = me->query("ji2_times");
	if( ji2 >= 10 ) {
		tell_object(me,CYN"人力有穷尽，红云大师说，他已经没法再改进这件武器了。\n");
		return 1;
	}
				
	n = (ji2+1)*2000 - me->query("TASK");
	if( n > 0 ) {
		tell_object(me,CYN"这位大侠，你还要为皇上多效力才行。（至少还需再做"+n+ "个使命）\n"NOR);
		return 1;
	}
	tell_object(me, HIY"锻造武器一次将会使用一千两黄金，是否要继续？(continue yes/no)\n"NOR);
	add_action("do_continue", "continue");
	me->set_temp("process_ji2", ob);
	return 1;
}

int do_continue(string arg)
{
	int i, j, cost = 1;
	object me = this_player();
	object ji_person, obx;
	string broken;
	int gold, base, current;

	if( environment(me)!= environment(this_object()) || !me->query_temp("process_ji2") || !objectp(me->query_temp("process_ji2")) ) {
		return notify_fail("什么？\n");
	}
	if( arg != "yes" ) { 
		write ("段公公说：知难而退，你还是很有自知之明的。\n");
		me->delete_temp("process_ji2");
		remove_action("do_continue","continue");
		return 1; 
	}
	if( !objectp(ob = me->query_temp("process_ji2")) ) {
		return notify_fail("你身上没有这样东西。\n");
	}
	me->delete_temp("process_ji2");
	if( !ob->query("weapon_prop") ) {
		return notify_fail("你只能锻造可当作武器的东西。\n");
	}
	if( ob->query("equipped") ) {
		return notify_fail("你不可锻造装备著了的武器。\n");
	}
	if( !ob->query("owner") ) {
		return notify_fail("你只可锻造自己打造的武器。\n");
	}
	sscanf(ob->query("name"), "%s的", broken);
	if( broken =="断掉" ) {
		return notify_fail("你不可锻造损坏了的武器，请去张铁匠那里修好武器再来。\n");
	}
	base = (int)ob->query("base_damage");
	current = (int) ob->query("weapon_prop/damage");
	if( base != current ) {
		return notify_fail("你不可祭损坏了的武器，请去张铁匠那里修好武器再来祭。\n");
	}
	cost = 1000;
	gold = me->query("deposit")/10000;
	if( gold < cost) {
		tell_object(me,"你银行里存款不够" + sprintf("%d",cost)+ "两金子。\n");
		return 1;
	}
	me->perform_busy(1);        
	me->add("deposit", -10000000);

	// need to update 2 things: damage, base_damage is to keep track
	// damage on weapon so we can xiu weapon later on.
	seteuid(ROOT_UID);
	me->add("ji2_times",1);
	ob->unequip();
	ob->add("weapon_prop/damage", 10);
	ob->add("base_damage", 10);
	ob->add("ji2_times", 1);
	ob->save();
	ob->restore();
	me->save();
	seteuid(getuid());

	message_vision("\n$N从$n手中取过"+ob->name()+NOR"踱入宫中，没一会儿又走了出来。\n", this_object(), me); 
	message_vision("$N呵呵笑道：你小子好福气，红云上人正好在替皇上行事，顺便就把你的事儿也办了。\n\n", this_object());
	message_vision("$N把"+ob->name()+NOR"交还给$n道：好好替皇上办事儿，重重有赏！\n\n", this_object(), me);

	remove_action("do_continue", "continue");
	return 1;
}

int accept_object(object who, object ob)
{
	object me = who;

	if( (ob->query("name") == HIG"孝女花"NOR) && (REWARD_D->riddle_check(me,"孝感苍天") == 2) ) {
		if( ob->query("lore") ) {
			message_vision("段公公接过此等尤物仔细端详后对$N说："CYN"“此事哀家已知晓。”\n"NOR, me);
			REWARD_D->riddle_set(me,"孝感苍天",3);
			give_me_it(me);
			return 1;
		}
	} else if( ob->query("pfm_r1") == 1 ) {
		message_vision(WHT"$N的眼中忽然放出光来，笑呵呵地道：“好，好，虽然残缺了些，也是你对皇上的一片忠心。”\n"NOR, this_object());
		who->add("marks/book_task", 1);
		who->add("TASK", 1);
		tell_object(who,"（完成使命数 +1 ）。\n");
		return 1;
	}
	return 0;
}

int give_me_it(object me)
{
	object x;
	x = new(__DIR__"obj/su_paper");
	if( !x->move(me) ) {
		x->move(environment(me));
		message_vision("段公公从怀里摸出一卷东西丢出去，挥手道："CYN"“去吧，别让皇。。。公子久等了。”"NOR"\n");
	} else {
		message_vision("段公公从怀里摸出一卷东西塞给$N后，挥手道："CYN"“去吧，别让皇。。。公子久等了。”"NOR"\n",me);
	}
	return 1;
}