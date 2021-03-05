// feixian-steps.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","飞仙步法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","baiyun");
	set("dodge_msg", ({
		"$n一招「天玑离枢」轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「天璇乱步」早已避在七尺之外。\n",
		"$n使出「倒转天权」，轻轻松松地闪过。\n",
		"$n左足一点，一招「逐影天枢」腾空而起，避了开去。\n",
		"可是$n使一招「风动玉衡」，身子轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「开阳薄雾」轻轻闪过。\n",
		"但是$n一招「瑶光音迟」使出，早已绕到$N身後！\n"
	}) );

}


mixed dodge_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	if (me->query("class")!="baiyun")	return 0;
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chessism",1);
//	random(150) + 50 > 100	
	if (me->query_busy()>1)
	if (random(skill) + skill/3 > 100 && me->is_busy()) {
		message_vision(HIY"$N大局在握，步走斜飞，弈道『成算篇』历历在目，身形骤然轻巧起来。\n"NOR, me);	
		if (me->query_busy()==1) me->stop_busy();
			else me->start_busy(me->query_busy()-1);
	}
	return 0;
}	
