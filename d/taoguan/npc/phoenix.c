// Simon - phoenix
// phoenix.c ; last modified at 06.25.2003 by annie
// cast thousand-feather,busy target

#include <ansi.h>

inherit NPC;

void busy_attack();

void create()
{

	set_name("朱雀", ({ "phoenix" }) );
	set("race", "野兽");
	set("attitude", "friendly");
	set("title",WHT"四灵之"NOR);
	set("nickname",RED"红尘"NOR);
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
               (: busy_attack() :),
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

void busy_attack()
{
	object me = this_object();
	object * enemy;
	object target;
	int i,j,k=0,l=0;
	enemy = query_enemy();
	// cast 炽翼千羽 ; annie 6.25.03
	message_vision(RED"\n朱雀发出一声清啸长啼，振翅而起。\n朱雀在空中转折身形，双翼拍动，无数火羽漫天洒落下来。\n\n",me);
	for(i=0; i<sizeof(enemy); i++)
	{
		target = enemy[i];
		for (j=0;j<10;j++)
		{
			if (random(target->query("combat_exp") * 3 / 2) < random(me->query("combat_exp")) )
				l++;
			else if (random(target->query("combat_exp")) < random(me->query("combat_exp")))
				k += 1+random(200);
			// else... miss.
		}
		message_vision(RED"结果$N",target);
		if (l)
		{
			message_vision("穷于闪躲漫天而下的火羽，",target);
			if (target->query_busy() <= l)
				target->start_busy(l);
			if (wizardp(target))
				tell_object(target,"BUSY:"+l);
		}
		if (k)
		{
			message_vision("被"+chinese_number(k)+"根火羽烧到，",target);
			target->receive_damage("kee",k*(5+random(5)),me);
			if (wizardp(target))
				tell_object(target,"DAMAGE:"+k);
		}

		if (l || k)
			message_vision("闹得手忙脚乱！\n\n"NOR,target);
		else
			message_vision("轻轻松松的避开了所有的火羽。\n\n"NOR,target);
	}
	start_busy(3);
	return;
	// tough? weak? silencer...pls balance this perform,thanks :) ; annie
}
