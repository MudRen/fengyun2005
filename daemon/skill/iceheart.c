// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","冰心诀");
	set("type","force");
	set("usage/force",1);
	set("effective_level",100);
	set("difficulty",400);
	set("skill_class","yinshi");
}


// 蛊降I II
mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage, rate;
	object weapon, *enemy;
	string msg;

	if( !(rate = me->query_temp("pfm/locustcurse")) ) {
		return;
	}
	// max 500*2
	extra = me->query_skill("cursism");
	extra = extra *2;
	extra = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	me->delete_temp("pfm/locustcurse");
	if( random(100) > rate ) {
		if( COMBAT_D->do_magic_attack(me, victim, "cursism", "kee", 400) ) {
			victim->receive_wound("kee", extra, me);
			msg= RED"$N手中的红虫忽然飞掠出来，悄没声息地落到$n身上。\n"NOR;
		} else {
			msg= YEL"$N手中的红虫忽然飞掠出来，$n早有所备，一掌将其拍散。\n"NOR;
		}
		return msg;
	} else {
		me->receive_wound("kee", extra, me);
		me->set_temp("last_damage_from","被蛊降尸虫反噬而死\n");
		msg= HIR"$N手中的红虫受惊飞掠而起直扑自身，$N大惊失色。\n"NOR;
		return msg;
	}
	return 0;
}


int help(object me)
{
	write(@HELP
『紫心诀』（Heal）疗伤心法

『素心诀』〔Depoison〕解毒
L0 		解最一般的伤风咳嗽等病状
L75 	解蝙蝠毒、蛇毒、碧血蛊、赤血蛊等
L150 	解瘴气、无名毒等
为他人（队友）至少需要100级冰心诀

『寒心诀』〔Buffup) 
提高自己的气血最大值，需花费400点内力，延续15分钟
Ｉ		：需50级冰心诀，+300气血
ＩＩ	：需110级冰心诀，阅读卷轴，+900气血
ＩＩＩ	：需150级冰心诀，阅读卷轴，+1500气血
ＩＶ	：另需200级通天降，阅读卷轴，+2500气血
寒心诀可以经由门派ability进一步提高；另外还可经由TASK ability3同时
提升精/气/神，但是增加的部分作用于队友时数量减半。
HELP
	);
	return 1;
}
