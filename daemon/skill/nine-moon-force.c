// nine-moon-force.c
inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","九阴心经");
	set("type","force");
	set("effective_level",100);
	set("usage/force",1);
	set("skill_class","shenshui");
	set("difficulty",200);
	set("no_refund",({"nine-moon-claw","nine-moon-steps"}));
}
 
mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage,ratio, rec;
	object weapon;
	string msg;
	
/*	if ((ratio=me->query_temp("pfm/9moon_huaxue"))) {		// 化血神功。
		rec = COMBAT_D->magic_modifier(me, victim, "kee", 
			damage_bonus *(ratio + F_ABILITY->check_ability(me,"huaxue_add")*5)/100);
		if (ratio==20) msg =RED"\n$N"NOR RED"但觉全身气血都晃了一晃。\n"NOR;
		else if (ratio=30)	msg = RED"\n$N"NOR RED"心头一颤，气血浮动不止。\n"NOR;
		else 		msg = RED"\n$N"NOR RED"但觉全身气血飞泻而出。\n"NOR;	
		me->receive_fulling("kee",rec, me);
		message_vision(msg, victim);
	}*/
		
	if(!extra=me->query_temp("nine-moon-force_poison")) return ;
	
	damage = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	if (weapon=me->query_temp("weapon")){
		if (weapon->query("skill_type")=="sword" && 
			me->query_skill_mapped("sword") == "nine-moon-sword")
		{	
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			return MAG"$n"NOR MAG"只觉丝丝寒意透骨，似乎有一缕紫云般的雾气从$N"NOR MAG"兵刃上传来。\n"NOR;
		}
		if ((weapon->query("skill_type")=="unarmed" && 
			me->query_skill_mapped("unarmed") == "nine-moon-claw"))
		{	
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			return MAG"一缕紫云般的雾气一闪，$n"NOR MAG"只觉冷厉的阴风如刺如锥般从$N"NOR MAG"指尖传来。\n"NOR;
		}	
			
	} else if (me->query_skill_mapped("unarmed") == "nine-moon-claw")
		{
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			msg=MAG"一缕紫云般的雾气一闪，$n"NOR MAG"只觉冷厉的阴风如刺如锥般从$N"NOR MAG"指尖传来。\n"NOR;
			return msg;
		}
	return 0;
}


int help(object me)
{
	write(@HELP   
『迷魂术』（mihunshu）
此式需50级姹女神功方能使用，令敌人忙乱一轮并损伤其气血心神，
成功率极高，无论成败都没有自我忙乱。
每14秒使用一次，每次耗费（姹女神功/2或至少50）点内力。
心神伤害＝气血伤害＝姹女神功等级＋random(姹女神功等级)
迷魂术不受忙乱法则中18秒成功率下降的限制

『寒阴术』〔powerup〕
需60级九阴心经，风云中唯一一个同时提高攻击和闪避力的特技，提高
数目为九阴心经等级的一半，耗费100点内力。
   
『內纳术』〔powerfade〕   
需80级九阴心经，降低自己的杀气。

『凝神术』〔refine〕   
需100级九阴心经和100级姹女神功，将法力转化为内力。
转换内力数量为：消耗法力＊（姹女神功等级）／３００
该特技可指定数量：exert refine 200 就是转化200点法力

『九阴凝寒』（chill）
需要150级九阴心经和135级姹女神功，每次耗费300点内力，延续５分
钟。该特技为神水和清平武功的精华，举手投足间，神水武功的每一攻
击、每一轮招架都能产生额外伤害，若钻研清平内功到150级，敌人攻击
每沾身一次，亦能有反击的伤害。
伤害数目＝自身经验等级／２
   
『化血神功』〔huaxue〕
需要160级九阴心经和160级姹女神功，将对敌人非魔法伤害的50%转化
为自己的气血。每10分钟使用一次，每次持续120秒。

『九阴毒雾』(chillbreath)
需要180级九阴心经和姹女神功，持续作用120秒，受毒雾影响，敌人每三
轮有一定几率身法顿挫，为九阴白骨抓破颅的第二击创造战机。
此几率随经验等级的提高而提高。

从白三空可学习清平内功，需90级姹女神功
L100 将疗伤之『静心诀』（jingxin）融入九阴心法
L150 『九阴凝寒』在被敌人击中时亦会生效

HELP
    );
    return 1;
}
