#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name("九动雷机", ({ "launch mechanism","mechanism" }) );
	set("race","元素");
	set("long","\n唐门中人历来于机括硝器之学上独有所长。十五年前名匠唐宗为朝廷画\n出天罡破阵之图，北域官兵依此在燕门之劫中击退胡人二十万兵马，从\n此天罡破阵弩声名大振，朝廷亦将其布置在每一处要道关隘。此弩虽是\n威力无穷，无奈连发机构极端庞大而不便运输，现在在你面前的便是瞭\n望台上大弩的牵射机括。\n"CYN"你可以用摆放在一边的木条铁兖尝试修理它(repair)\n"NOR);
	set("combat_exp",100000);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("no_heal",1);

	setup();
}

// ajouter une fonction de "réparation"


void init()
{
	add_action("do_start","repair");
}

int do_start()
{
	object me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙……\n");
	if (query("repairing"))
		return notify_fail("有人正在修理九动雷机。\n");
	if (query("max_kee") == query("kee"))
		return notify_fail("九动雷机并没有受到任何损害。\n");
	set("repairing",1);
	me->perform_busy(10);	// 20 sec: kee + 5%
	message_vision(HIY"\n$N趁乱避到一边，蹲下身开始修理九动雷机．．．\n\n",me);
	call_out("r2",20,me);
	return 1;
}

void r2(object me)
{
	set("repairing",0);
	if (!me)
		return;
	if (environment(me) != environment())
		return;
	receive_fulling("kee",query("max_kee")/20);
	message_vision(HIY"\n$N修好了九动雷机，抹抹汗站起身子。\n\n"NOR,me);
		return;

}




// ajouter une fonction de "broken"->la mission a échoué
void die()
{
	object me = this_object();
	tell_room(environment(this_object()),HIR"\n漫天的血雨潇潇，一阵阵打在毁损的天罡破阵弩上．．．\n"HIW"\n由于明霞关隘的失守，两个月后倭人海贼长驱直入，大肆屠杀，中原大地一时间\n哭声遍野，愁肠欲绝，数十万百姓流离失所，被迫西迁．．．"HIY"\n\n很遗憾，任务失败了。\n\n"NOR);
	environment(this_object())->failed();
	// not real die..
//	::die();
}




/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
