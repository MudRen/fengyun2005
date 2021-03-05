// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name("杀人草", ({ "hunting weed", "weed" }) );
	set("race", "野兽");
	set("gender", "无性");
	set("age", 3);
	set("long", "它看起来就是一团杂草。\n");
	
	set("no_arrest",1);
	
	set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 360000);
	
	set_temp("apply/attack", 160);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 100);

	set_skill("force",200);
	set_skill("divineforce",200);
	map_skill("force","divineforce");
	set("class","demon");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

    set("NO_CORPSE",CYN"杀人草一声尖叫，化成一道青烟，钻进了山壁上的藤蔓中。\n"NOR);

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

void smart_fight()
{
	object me,target;
	me = this_object();
	
	target = select_opponent();
	
	if (target)
	if (target->query("combat_exp")< this_object()->query("combat_exp")*3/2)
	if (SKILL_D("divineforce")->perform_action(me,"check_gspm"))
	{
		message_vision(CYN"\n$N打量了一下情况，从草丛里蹦了出来，竟是个一尺高下的小人。"NOR,me);
		SKILL_D("divineforce")->perform_action(me,"guishenpomie");
		stop_busy();
		message_vision(CYN"$N咯吱细笑，直抖得草叶乱颤，又哧溜一声钻回草丛里。\n"NOR,me);
		return;
	}

	switch (random(3))
	{
	case 1:
		message_vision(CYN"\n$N身边木叶盘旋飞舞，让人难以迫近。\n\n"NOR,me);
		me->receive_heal("kee",300);
		break;
	case 2:
		message_vision(CYN"\n$N啾啾乱叫了几声。\n\n"NOR,me);
		break;
	case 0:
		add_temp("apply/attack",100);
		COMBAT_D->do_attack(me,target,TYPE_PERFORM,
					HIG"\n$N身边骤然鼓起一道狂风，夹着飞沙走石卷向$n，飞乱的砂石雨迷得$n耳眼迷茫！"NOR,
					"刺伤");
		add_temp("apply/attack",-100);
		if (target->query_temp("damaged_during_attack"))
		{
			ccommand("ya");
			target->perform_busy(1);
		}
	}
}

