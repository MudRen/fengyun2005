// Simon - tiger
// tiger.c ; last modified at 06.25.2003 by annie
// MT,hv berserk ability

#include <ansi.h>

inherit NPC;

void berserk();

void create()
{

	set_name("白虎", ({ "tiger" }) );
	set("race", "野兽");
	set("attitude", "friendly");
	set("title",WHT"四灵之"NOR);
	set("nickname",YEL"黄泉"NOR);
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
               (: berserk() :),
        }) );

	set_temp("apply/attack",500);
	set_temp("apply/dodge",1);
	set_temp("apply/parry",1);
	set_temp("apply/armor",1);

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	// powerup when hit. ; annie 6.25.03
	if (query("berserk"))
		return;
	add_temp("apply/haste",30);
	add("str",3);
	return HIR"$n鲜血的气味激发了$N体内的狂性，$N眼中的精光越来越盛。\n"NOR;
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

void berserk()
{
	object me = this_object();
	object target = select_opponent();
	int i;

	if ((target->query("kee") < target->query("max_kee") / 2 || query("kee") < query("max_kee") / 2 || query("gin") < query("max_gin") / 2 || query("sen") < query("max_sen") / 2) && !query("berserk"))
	{
		// cast 吼破雲關 ; annie 6.25.03
		set("berserk",1);
		message_vision(YEL"\n$N猛然仰天大吼，其声震聋发聩，其势上冲霄汉！\n$N的双眼变成一片腥红，周身带上了无边的杀气！\n\n"NOR,me);
		set("str",query("str") * 2);
		target->start_busy(2);
		call_out("do_calmdown",12,me);	// CT 12 sec. ; up to 12 from 9,annie 6.26.03
	}
	return;
}

void do_calmdown(object me)
{
	// delete("berserk");	// rem by annie,6.25.03. 
	set("str",40);
	set_temp("apply/haste",0);
	set_temp("apply/slow",50);
	message_vision(CYN"$N眼中的血红渐渐褪去，显出一缕疲累之色。\n"NOR,me);
	return;
}