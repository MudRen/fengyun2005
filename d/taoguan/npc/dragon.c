// Simon - dragon
// dragon.c ; last modified at 06.26.2003 by annie
// heal teammate

#include <ansi.h>

inherit NPC;

void heal();

void create()
{

	set_name("青龙", ({ "dragon" }) );
	set("race", "野兽");
	set("attitude", "friendly");
	set("title",WHT"四灵之"NOR);
	set("nickname",CYN"碧落"NOR);
	set("no_fly",1);
	set("no_arrest",1);
	set("combat_exp", 6000000);

	set("group","demon");

	set("max_kee",7000);
	set("max_gin",4000);
	set("max_sen",4000);

	set("limbs", ({ "头部", "身体", }) );
	set("verbs", ({ "bite", "claw" }) );

	set("str",60);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: heal() :),
        }) );

	set_temp("apply/attack",350);
	set_temp("apply/dodge",1);
	set_temp("apply/parry",1);
	set_temp("apply/armor",1);

	setup();
}

object select_opponent() 	
{
	object * enemy;
	int i;
	enemy = query_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	clean_up_enemy();
	if(!sizeof(enemy)) {
		return 0;
	}
	for(i=0; i<sizeof(enemy); i++)
		if (userp(enemy[i]))
			return enemy[i]; // focus user. ; annie 6.25.03
	return enemy[random(sizeof(enemy))];
}

void heal()
{
	object me = this_object();
	object * friends;
	object target,enemy;
	int i,j,k=999999,l=0;
	enemy = select_opponent();
	friends = enemy->query_enemy();

	// cast 返命之陣 ; annie 6.26.03
	if (!present("ward",environment()))
	{
		message_vision(HIG"\n青龙周身的灵氛越来越浓，渐渐凝作一道浅绿色的光芒在场中流动。\n"NOR,me);
		target = new(__DIR__"obj/ward");
		target->move(environment());
		target->heal_ob(enemy,8);
		start_busy(2);
		return;
	}

	for (i=0;i<sizeof(friends) ; i++)
	{
		target = friends[i];
		if (target->query("kee") < target->query("max_kee"))
			if (k>target->query("kee"))
			{
				k=target->query("kee");
				j=i;
			}
	}

	if (k == 999999)
		return;

	target = friends[j];

	if (k < target->query("max_kee") * 2 / 3 && query("timer/instant_cure") + 4 < time())	// KEE : 2/3-,cast 琉璃淨光 ,4s cooldown ; annie 6.26.03
	{
		message_vision(HIG"\n青龙施展四相转生术中的「琉璃净光」，聚出一道青华注进$N后心。\n"NOR,target);
		target->receive_curing("kee",800);
		target->receive_heal("kee",800);
		set("timer/instant_cure",time());
		start_busy(1);
		return;
	}
	else if (query("timer/regenerate_cure") + 2 < time() && !target->query_temp("annie/demon_dragon_regenerate"))	// cast 冰蓮活心 , 2s cooldown; annie 6.26.03
	{
		message_vision(WHT"\n青龙施展四相转生术中的「冰莲活心」，聚出一道白芒注入$N顶门。\n"NOR,target);
		target->receive_curing("kee",300);
		target->receive_heal("kee",300);
		set("timer/regenerate_cure",time());
		start_busy(1);
		target->set_temp("annie/demon_dragon_regenerate",1);
		call_out("do_reg",1,target,3);
		return;
	}
	else if (query("timer/instant_cure") + 4 < time())	// cast 琉璃淨光 ,4s cooldown ; annie 6.26.03
	{
		message_vision(HIG"\n青龙施展四相转生术中的「琉璃净光」，聚出一道青华注进$N后心。\n"NOR,target);
		target->receive_curing("kee",800);
		target->receive_heal("kee",800);
		set("timer/instant_cure",time());
		start_busy(1);
		return;
	}

	return;
}

void do_reg(object target,int count)
{
	if (!target)
		return ;
	if (target->query("kee") < target->query("max_kee"))
		message_vision("$N神情一凛，似乎又精神了几分。\n",target);
	target->receive_curing("kee",300);
	target->receive_heal("kee",300);
	count--;
	if (count < 0)
	{
		target->delete_temp("annie/demon_dragon_regenerate");
		return ;
	}
	call_out("do_reg",1,target,count);
		return;
}