// Simon - turtle
// turtle.c ; last modified at 06.26.2003 by annie
// buffup

#include <ansi.h>

inherit NPC;

void buff_mate();

void create()
{
	set_name("玄武", ({ "turtle" }) );
	set("race", "野兽");
	set("attitude", "friendly");
	set("title",WHT"四灵之"NOR);
	set("nickname",MAG"紫陌"NOR);
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
               (: buff_mate() :),
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

void buff_mate()
{
	object me = this_object();
	object * friends;
	object target,enemy;
	int i,j,k=999999,l=0;
	enemy = select_opponent();
	friends = enemy->query_enemy();

	switch (query("annie/demon_turtle_buff"))
	{
	case 0:
		message_vision(MAG"\n玄武身边紫气袅绕，云雾升腾。\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add("eff_gin",target->query("max_gin") / 2);
			target->add("eff_kee",target->query("max_kee") / 2);
			target->add("eff_sen",target->query("max_sen") / 2);
			target->add("max_gin",target->query("max_gin") / 2);
			target->add("max_kee",target->query("max_kee") / 2);
			target->add("max_sen",target->query("max_sen") / 2);
			message_vision(MAG"「灵阙返生」的紫云漫过$N，$N的身形隐然变大几分。\n"NOR,target);
		}
		break;
	case 1:
		message_vision(MAG"\n玄武精气神归于一体，施出「辰朱神护」！\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add_temp("apply/dodge",350);
			target->add_temp("apply/parry",350);
			message_vision(MAG"淡紫色的烟气缭绕在$N周围，隐隐护住$N。\n"NOR,target);
		}
		break;
	case 2:
		message_vision(MAG"\n玄武施出「红莲劫焰」，一朵灿烂的火焰骤然炸开！\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add_temp("apply/armor",200);
			target->add_temp("apply/ironcloth",350);
			target->set_temp("damage_shield/type","kee");
			target->set_temp("damage_shield/amount",250+random(200));
			target->set_temp("damage_shield/msg",MAG"$n一招得手，却被$N身边火焰烧得焦头烂额！\n"NOR);
			message_vision(MAG"几簇紫色的火苗在$N身边跳动，看似万分诡异。\n"NOR,target);
		}
		break;
	case 3:
		message_vision(MAG"\n玄武运转「降灵血刃」法低低咆哮，声音虽然不大却撼人心魄。\n"NOR,me);
		for (i=0;i<sizeof(friends) ; i++)
		{
			target = friends[i];
			target->add_temp("apply/attack",160);
			target->add_temp("apply/damage",160);
			message_vision(MAG"$N目中杀机乍现，出手更为绝情。\n"NOR,target);
		}
		break;
	}
	add("annie/demon_turtle_buff",1);
	if (query("annie/demon_turtle_buff") < 4)
		start_busy(3);
	return;
}

// Kill Turtle in 12s to prevent buffup; (asap)
// Kill Dragon to prevent heal;
// Kill Phoenix to prevent busy;
// Kill Tiger to deal combat.
