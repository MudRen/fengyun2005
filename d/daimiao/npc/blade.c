#include <ansi.h>
inherit SMART_NPC;

int smart_fight();

void create()
{
	object weapon;
	set_name("一刀万杀", ({ "wansha","wan sha" }) );
	set("title",HIB"灭境三途判"NOR);
	set("gender", "男性" );

	set("group","demon");

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
//		(: auto_smart_fight(100) :),
		(: smart_fight() :),
	}) );

	set("combat_exp", 10000000);

	setup();

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","spring-blade",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("麒麟甲", ({ "armor"}) );
	weapon->set("long","\n");
	weapon->set("value",0);
	weapon->wear();


	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(HIR"千兽魄"NOR, ({ "blade"}) );
	weapon->set("long","\n");
	weapon->set("value",0);
	weapon->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}

void unconcious()
{
	die();
}

pf2(object tm)
{
	object ob,me=this_object();
	object* inv,target,*pros;
	int i;
	if (!tm)
		return;
	if (!is_fighting() && !tm->is_fighting())
		return;
	if (environment() != environment(tm))
		return;
	
//	message_vision(WHT"\n$N与$n对视一眼，两人同时吐气开声，收去控住刀剑的真力。\n",me,tm);
	message_vision(WHT"\n墨蓝与淡红的流辉骤然暴涨，"HIR"化作两道辉煌灿烂的光弧，晕向四面八方！\n"NOR,me,tm);
	inv=all_inventory(environment());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (inv[i] == me)	continue;
		if (inv[i] == tm)	continue;
		if (!inv[i]->is_fighting(me) && !inv[i]->is_fighting(tm) )	continue;
		target = inv[i];

		target->receive_damage("kee",target->query("max_kee")/(5+random(2)),me);
		target->receive_damage("kee",target->query("max_kee")/(5+random(2)),tm);
		target->receive_wound("kee",target->query("max_kee")/(5+random(2)),me);
		target->receive_wound("kee",target->query("max_kee")/(5+random(2)),tm);
		

		COMBAT_D->report_status(target);
	}
	message_vision(WHT"\n",me,tm);
	return;
}

pf(object tm)
{
	object ob,me=this_object();
	object* inv;
	int i;
	if (!tm)
		return;
	if (!is_fighting() && !tm->is_fighting())
		return;
	if (environment() != environment(tm))
		return;
	
	message_vision(MAG"$N与$n微微发颤的手引着双色的流光画出一个又一个完整的圆弧，起伏之中隐含着奇特的韵律，\n",me,tm);
	message_vision("就像天地间万物相生轮转的道家至理一般，浑然天成、毫无破绽而又极其美丽。\n"NOR,me,tm);
	call_out("pf2",2,tm);
	return;
}

smart_fight()
{
	object ob,me=this_object(),tm;
	object* inv;
	int i;
	ob=select_opponent();
	if (present("wan sheng",environment()))
		tm=present("wan sheng",environment());
	if ((!SMART_D->check_health(me,30) || !SMART_D->check_health(ob,30)) && query("ac") + 60 < time())
		if (tm)
			if (tm->query_busy()<2 && tm->query("ac") + 60 < time())
			{
				set("ac",time());
				tm->set("ac",time());
				message_vision(HIB"\n墨青淡红的刀剑辉光忽而收敛，一上一下，一升一沉，以一种奇异的轨迹与节奏环绕着$N和$n缓\n",me,tm);
 				message_vision("缓旋转，刹那间竟使你有种错觉，似是刀剑正沿着自己的思想、自己的意识而动。\n\n"NOR,me,tm);
				inv=all_inventory(environment());
				for (i=0;i<sizeof(inv) ;i++ )
				{
//					if (inv[i] == me)	continue;
//					if (inv[i] == tm)	continue;
					if (!inv[i]->query("max_kee"))	continue;
					inv[i]->perform_busy(3);	// NO IMMUNE.
				}
				call_out("pf",2,tm);
				return;
//				message_vision(HIR"淡淡的红色",me);
			}
	ccommand("perform fengsiyunqi");
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
