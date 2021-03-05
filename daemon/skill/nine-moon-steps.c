// nine-moon-steps.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","九阴身法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("skill_class","shenshui");
	set("effective_level",150);
	set("practice_limit",100);
	set("difficulty",200);
	set("dodge_msg", ({
		"$n一招「阴差阳错」轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「阴风拂面」早已避在七尺之外。\n",
		"$n使出「阴动阳随」，轻轻松松地闪过。\n",
		"$n左足一点，一招「阴气冲天」腾空而起，避了开去。\n",
		"可是$n使一招「阴阳交错」，身子轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「阴鬼叛阎」轻轻闪过。\n",
		"但是$n一招「阴气森森」使出，早已绕到$N身後！\n"
	}) );
}

int valid_learn(object me)
{
        if( (string)me->query("gender") != "女性" )
        	return notify_fail("九阴身法是只有女子才能练的武功。\n");
	if (me->query_skill("nine-moon-steps",1)>= me->query_skill("nine-moon-force",1)){
			return notify_fail("你的九阴心经火候不够。\n");
	}	
	return ::valid_learn(me);
}


//	Let chaos-steps add to nine-moon-steps.

int effective_level(object me)
{
	
	int skill,n;
	
	if (me) {
/*		skill = me->query("pfm/chaos-9moon");
		if (skill == 20 || skill == 10 || skill == 30)
			return 150 + skill;	
		else 
			return 150;*/
		skill = me->query_skill("chaos-steps",1);
		if (skill >= 150)	return 180;
		if (skill >= 100)	return 170;
		if (skill >= 50)	return 160;
		return 150;	
	}
	return 180;
}


int help(object me)
{
	write(@HELP   
『连环步』（dodge.lianhuabu）
需要30级九阴步法，令敌人忙乱两轮，120级以上有几率令敌人忙乱三轮，
虽然成功率不高，但即使失败自我忙乱也只有一轮。
水天姬的入门弟子（经验等级25以下）每次（上线）见过师傅后此特技的
成功率会有一定提高。

『飞燕式』（dodge.feiyanshi）
需要150级九阴步法、100级倒乱七星步，此式是从倒乱七星步的“抽身
式”化出，可在战斗中主动逃跑而不受通常每三轮一次的限制，每次耗
费150点内力，自我忙乱一轮。

『追命式』（dodge.zhuiming）
需要180级九阴步法、200级九阴白骨抓和200级姹女神功
出招之际，先以九阴身法困住对手，而后以白骨抓取其顶门要害。若对
手气血低于20%（以及<=5000）时有极大可能一击致命。
若对手不在忙乱状态则会试图令其忙乱一轮再攻击
第二击若出手则需等待五分钟方可再用，自我忙乱两轮。

从白三空处学习倒乱七星步可提高九阴步法等级，至少需要160级姹女神功
倒乱七星步L50  九阴步法有效系数提高至160
倒乱七星步L100 九阴步法有效系数提高至170
倒乱七星步L150 九阴步法有效系数提高至180

HELP
    );
    return 1;
}

