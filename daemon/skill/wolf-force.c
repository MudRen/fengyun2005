#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","天狼心法");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","wolfmount");
}

/*		in combat_d
mixed hit_ob(object me,object victim,int damage_bonus)
{
	int extra, dream;
	object weapon;
	string skill;
	
	if (damage_bonus < 1)	return 0;
	if (!extra = me->query_temp("rabie"))	return 0;
	
	if (ANNIE_D->check_buff(me,"bloodthirsty"))
		damage_bonus = damage_bonus * 2;
	
	damage_bonus = damage_bonus * (20 + F_ABILITY->check_ability(me,"shigu_add")*2)/100; 
	
	damage_bonus = COMBAT_D->magic_modifier(me, me, "kee", damage_bonus);
		
	me->receive_fulling("kee",damage_bonus,me);
	return;
}*/

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int /*num,*/ hit_damage, amount;
	
	if (damage <=0)	return 0;	
	if( me->query_temp("pfm/wm_preservation")<=0)
		return 0;
	
	me->add_temp("pfm/wm_preservation",-1);
	
	data["msg"] = WHT"$n的身子往下一伏，似乎短小了数分。\n"NOR;
	
	hit_damage = 100 + me->query_skill("hammer")*3;	
	if (ob->query_hate(me)>0)
		ob->add_hate(me,-hit_damage);
	if ((amount = ob->query_hate(me))<0)
		ob->add_hate(me, -amount);	// 0
				
	if (me->query_temp("pfm/wm_preservation") < 1) {
			ANNIE_D->debuff(me, "wm-detaunt");
	}	
	return data;	
}



int help(object me)
{
	write(@HELP 
『潜狼』（preservation）
使用此心诀后每被敌人击中一次，敌人会降低对使用者的憎恨。
每次减少数量为有效锤法的三倍左右。每90秒使用一次。
每次延续30秒或被敌人击中3次后失效。
	  
『战狼』（bloodthirsty）
需要160级天狼心法，持续90秒，每10分钟可使用一次。
特技期间嗜骨返回的气血值加倍。
	
『舞狼』（fancyfeet）
需要170级天狼心法，200级唤狼术，每90秒钟可使用一次
让唤出的狼无条件闪躲3次非魔法攻击，10秒后失效。

『天狼』（paragon）
需要170级天狼心法和250级唤狼术，每20分钟使用一次，每次耗费
200点内力。特技使用后每三轮恢复一次气血，持续10轮，每轮恢
复气血值为天狼心法等级的三倍。

『神狼』（assassinate）
需要170级天狼心法和270级唤狼术，每20分钟使用一次，每次耗费
100点内力，持续16秒钟，在此期间搏浪七杀的特技绝无失手，同
时每次击中伤害为最大可能值。

HELP
    );
    return 1;
}