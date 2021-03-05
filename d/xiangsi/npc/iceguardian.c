// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
void smart_fight();

void create()
{
	set_name("冰魂", ({ "ice guardian", "ice soul", "guardian", "soul" ,"ghost"}) );
	set("class","moon");
	set("race", "野兽");

	set("attitude", "friendly");
	set("long","一缕似有还无的飘渺魂魄．．．\n");

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("no_arrest",1);

	set("combat_exp", 3000000);

	set_skill("mapo", 160);
	set_skill("spells", 200);

	set("NO_CORPSE","冰魂的灵气既失，形体也慢慢消散在寒风之中．．．\n\n");

	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		   (: smart_fight() :),
	}) );

	map_skill("spells", "mapo");
	setup();

}

int is_ghost() {return 1;}

int kill_ob(object who)
{
	::kill_ob(who);
	if (!is_busy())
		smart_fight();
	return 1;
}

void smart_fight()
{
	object me,target;
	mapping buff;
	me = this_object();
	target = select_opponent();
	if (target->query_temp("is_unconcious"))
		return;
	ccommand("name");
	SKILL_D("mapo")->cast_spell(me,"freeze",target);
	
	if (target->query_temp("is_unconcious"))
		ccommand("flatter");
	else
		ccommand("escape");
}

void die()
{	
	object me,target;
	mapping buff;
	me = this_object();
	target = query_temp("last_damage_from");
	if (!target)
	{
		::die();
		return;
	}
	if( ANNIE_D->check_buff(target,"freeze")) 
		return;

	message_vision(WHT"\n冰魂的形体中忽然射出一道白光，没入$N身中。\n",target);

		buff =
		([
			"caster":me,
			"who":target,
			"type":"freeze",
			"att":"curse",
			"name":"不老寒泉·千冰冻魄",
			"buff1":"disable_inputs",
			"buff1_c":1,
			"buff2":"is_unconcious",
			"buff2_c":1,
			"disable_type":HIW " <冻僵中>"NOR,
			"time":10+random(20),
			"buff_msg":HIW"奇冷的寒气包围了$N的全身，将$N冻成了一块冰雕！\n"NOR,
			"disa_msg":HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n"NOR,
			"disa_type":1,
		]);
	ANNIE_D->buffup(buff);
	::die();
}

void killed_enemy(object who)
{
	remove_killer(who);
	who->remove_killer(this_object());
    command("die3 "+who->get_id());
}
