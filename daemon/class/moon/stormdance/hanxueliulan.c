// annie 07.2003
// dancing_faery@hotmail.com
// 寒雪流岚
// Backfire.... silencer既然把no_abs & no_shield这么rascal的pfm都提供给player了....hmm
// 关于此pfm，需要在enable中判断，禁止效果间更换dodge。

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	mapping buff;
	int extra, level, ratio;

	if( me->query("class") != "moon" ) {
		return notify_fail("只有皓月宫的弟子才能施展『寒雪流岚』。\n");
	}
	extra = me->query_skill("stormdance", 1);
	if( extra <150 ) {
		return notify_fail("『寒雪流岚』需要至少150级的天岚凝舞。\n");
	}
	if( ANNIE_D->check_buff(me, "damageshield") || me->query_temp("damage_shield") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
/*
	寒雪流岚?简介	stormdance_hanxueliulan_1	L100	1M
	寒雪流岚?简介	stormdance_hanxueliulan_2	L120	2.4M
	寒雪流岚?简介	stormdance_hanxueliulan_3	L140	4M
	寒雪流岚?简介	stormdance_hanxueliulan_4	L200	6.4M
*/
	level = me->query("annie/stormdance_hanxueliulan");
	if( me->query("class") != "moon" ) {
		level = 0;
	}
	if( !userp(me) ) {
		level = 5;
	}
	switch( level ) {
		case 0:
			ratio = 15;
			break;
		case 1:
			ratio = 25;
			break;
		case 2:
			ratio = 25;
			break;
		case 3:
			ratio = 35;
			break;
		case 4:
			ratio = 45;
			break;
		case 5:
			ratio = 55;
			break;
	}

	buff = ([
			"caster": me,
			"who": me,
			"type": "damageshield",
			"att": "bless",
			"name": "天岚凝舞·寒雪流岚",
			"buffup_name": "backfire",
			"buffup_type": level >= 2 ? "all" : "kee",
			"buffup_ratio": ratio,
			"buffup_msg": WHT"一阵锥心刺骨的寒冷沁进了$n"NOR+WHT"心中，$n"NOR+WHT"不由打了一个寒颤。\n"NOR,
			"time": extra/3,
			"buff_msg": WHT"$N"NOR+WHT"身法乍变，脸若冰霜，投足间阵阵冷风翻卷，刺骨凝寒。\n"NOR,
		]);

	ANNIE_D->buffup(buff);
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
