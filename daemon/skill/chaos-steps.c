#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","倒乱七星步");
	set("effective_level",170);
	set("type","step");
	set("skill_class","shenshui");
	set("usage/dodge",1);
	set("usage/move",1);
	set("difficulty",150);
	
	set("practice_limit",1);
	set("dodge_msg", 			({
			"$n一招「天玑离枢」轻轻巧巧地避了开去。\n",
			"只见$n身影一晃，一式「天璇乱步」早已避在七尺之外。\n",
			"$n使出「倒转天权」，轻轻松松地闪过。\n",
			"$n左足一点，一招「逐影天枢」腾空而起，避了开去。\n",
			"可是$n使一招「风动玉衡」，身子轻轻飘了开去。\n",
			"$n身影微动，已经藉一招「开阳薄雾」轻轻闪过。\n",
			"但是$n一招「瑶光音迟」使出，早已绕到$N身後！\n"
			})
	);
}


int valid_learn(object me)
{
	if(me->query_skill("nine-moon-spirit",1)<160)
		return notify_fail("白三空捻著胡子看了看你，说道：姹女神功练高一些再来找我罢（需160级）\n");

	return ::valid_learn(me);
}

void skill_improved(object me)
{
		int s;
		s = me->query_skill("chaos-steps", 1);
		if (me->query("class") == "shenshui") {
	    	if (s == 50 && !me->query("pfm/chaos-9moon")) {
	    		tell_object(me,WHT"你只觉武学之道，处处相通，这倒乱七星步的窍门，似也可用于九阴步中。\n"
	    				"你的九阴身法提高了一个级别。\n"NOR);
//	    		me->set("pfm/chaos-9moon",10); 
	    	} else if (s == 100) {
	    		tell_object(me,WHT"你只觉武学之道，处处相通，这倒乱七星步的窍门，似也可用于九阴步中。\n"
	    				"你的九阴身法提高了一个级别。\n"NOR);
/*	    		tell_object(me,WHT"你只觉武学之道，处处相通，这倒乱七星步的『抽身』，似也可用于九阴步中。\n"
	    				"你学会了九阴身法的『飞雁式』。\n"NOR);
	    		me->set("pfm/9moon-feiyanshi",1);*/ 
//	    		me->set("pfm/chaos-9moon",20); 
	    	} 
/*	    	else if (s == 120) {
	    		tell_object(me,WHT"你忽觉灵窍突开，这倒乱七星步的『抽身』，正好配合九阴神抓的『破颅』。\n"
	    				"你学会了九阴身法的『追命式』。\n"NOR);
	    		me->set("pfm/9moon-zhuimingshi",1); 
	    	} */
	    	else if ( s == 150) {
	    		tell_object(me,WHT"你只觉武学之道，处处相通，倒乱七星步的身法，似也可用于九阴步中。\n"
	    				"如此这般，你的九阴身法与倒乱七星步已是融会贯通。\n"NOR);
//	    		me->set("pfm/chaos-9moon",30);
	    	}
		}
		return;
}


int help(object me)
{
	write(@HELP   
修习倒乱七星步至少需要160级的姹女神功

L50  九阴步法有效系数提高160
L100 九阴步法有效系数提高170
L150 九阴步法有效系数提高至180
HELP
);
    return 1;
}


