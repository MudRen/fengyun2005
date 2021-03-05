#include <ansi.h>
#include <combat.h>
inherit WALL;
void summon_ghost();

void create()
{
	set_name(MAG"亘古魂幡"NOR, ({ "demonic standard","standard" }) );
	set("race","元素");
	set("long","一面深紫色的巨大旗幡插在一方祭坛中央，旗幡周围飞舞着无数魂灵。\n或许你可以试图摧毁(kill)亘古魂幡。\n");
	set("combat_exp",20000);
	set("no_fly",1);
	set("no_curse",1);
	set("busy_immune",4);
	set("no_arrest",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		   (: summon_ghost() :),
	}) );

	set("real_boss",1);
	set_skill("iron-cloth",200);
	set_skill("steelwall",200);
	map_skill("iron-cloth","steelwall");
	setup();
}

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

void summon_ghost()
{
	object ghost;
	string g;
	object *enemy;
	int i;

	g=__DIR__"ghost"+(random(4)+1);
	ghost = new(g);
	ghost->move(environment());

	message_vision(MAG"一阵阴风卷过，有个盘旋的魂灵自亘古魂幡边飞下，直冲向你！\n"NOR,ghost);

	enemy = query_enemy();

	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			ghost->kill_ob(enemy[i]);
			enemy[i]->kill_ob(ghost);
		}
	}
	ghost->set("possessed",this_object());

	call_out("dist",10,ghost);
	return;
}

void dist(object ghost)
{
	if (!ghost)
		return;
	message_vision(BLU"$N在空中打了个旋儿，形体渐渐消散无影．．．\n"NOR,ghost);
	destruct(ghost);
	return;
}

void die()
{
	object me = this_object();
	object who = query_temp("last_damage_from");
	object tis = new(__DIR__"obj/artifact");
	object *c,owner;
	int i;
	
	if (objectp(owner=who->query("possessed")))
		who = owner;
	
	c=all_inventory(environment());
	for (i=0;i<sizeof(c) ; i++)
	{
		if (c[i]->is_ghost() && !userp(c[i]))
		{
			message_vision(BLU"$N在空中打了个旋儿，形体渐渐消散无影．．．\n"NOR,c[i]);
			destruct(c[i]);
		}
	}
	message_vision(MAG"\n随着一声巨响，亘古魂幡轰然倒地，山谷中一阵淡淡的紫雾升起．．．\n\n"NOR,me);
	if (who)		// You can get it again and again.. need mark to proceed riddle
		{
			tis->move(who);
			who->set("annie/亘古魂幡",1);
		}
	::die();
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
