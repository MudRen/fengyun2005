#include <ansi.h>
#include <combat.h>
inherit WALL;
void summon_ghost();

void create()
{
	set_name("石狮子", ({ "石狮子","石狮","shi shizi","shizi","shishizi","lion","stone lion" }) );
	set("race","元素");
	set("long","一座雕刻得栩栩如生的石狮雕像。\n看起来不破坏(kill)掉它你就无法前进……\n");
	set("combat_exp",7000000);
	set("no_fly",1);
	set("no_shown", 1);
	set("no_curse",1);
	set("busy_immune",4);
	set("no_arrest",1);

	set("max_kee",15000);
	set("max_gin",10000);
	set("max_sen",10000);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		   (: summon_ghost() :),
	}) );


	set_skill("iron-cloth",200);
	set_skill("steelwall",200);
	map_skill("iron-cloth","steelwall");
	setup();
}
/*
int kill_ob(object who)
{
	if (!is_fighting())
	{
		summon_ghost();
		summon_ghost();
//		summon_ghost();
	}
	::kill_ob(who);
	return 1;
}
*/


void summon_ghost()
{
	object ghost;
	string g;
	object *enemy;
	int i;
	if (query_temp("summoning"))	return;
		
	message_vision(MAG"一阵阵淡紫色的薄雾向石狮上凝集而去．．．\n"NOR,this_object());
	set_temp("summoning",1);
	call_out("roar_prep",6);
	return;
}

void roar_prep()
{
	message_vision(MAG"紫气越集越多，在石狮边上漾出奇诡的水纹．．．\n"NOR,this_object());
	call_out("roar",6);
	return;
}

void roar()
{
	object me = this_object();
	object *enemy;
	object target;
	int i;
	int mod;
	enemy = me->query_enemy();
	if (!enemy || sizeof(enemy)<0)	return;
		
	message_vision(HIY"\n骤然间紫雾云散，你但见眼前褚黄宝光一闪，耳边已响起振聋发聩的吼声，如山中鼓，如海长啸，如枕边雷！\n"NOR,this_object());

  for (i = 0 ; i< sizeof(enemy); i++)
	{
		target = enemy[i];
		mod = COMBAT_D->can_busy(me, target, "npcroar");	
		if (!mod) mod = 1000;
		if (!COMBAT_D->do_busy_attack(me, target, "npcroar", "rev-unarmed", 400, mod))
			continue;
		tell_object(target,HIW"\n霎时只如天崩地裂，两耳剧痛攻心，你眼前景物摇晃，气血阵阵翻涌不息。\n"NOR);	

		// dmg
		mod = 400+random(1200);
		target->receive_damage("kee",mod,me);
		target->receive_wound("kee",mod/2,me);
//		target->add("eff_kee",-mod);
		// silencer不给标准受伤函式就只能这样啦
        COMBAT_D->report_status(target);
	}
	delete_temp("summoning");
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
