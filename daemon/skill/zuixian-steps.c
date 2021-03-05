// zuixian-steps.c
inherit SKILL;

void setup() {
	set("name","醉仙望月步");
	set("practice_limit",100);
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("difficulty",200);
	set("skill_class","yinshi");
	set("dodge_msg",			({
			"但是$n身形飘忽，轻轻一纵，一招「醉仙望月」，轻而易举的避开这一击。\n",
			"$n身随意转，一式「仙人敬酒」，往旁窜开数尺，躲了开去。\n",
			"$n身形往上拔起，一招「把酒飞仙」，一个转折落在数尺之外。\n"
			})
	);
}


int help(object me)
{
	write(@HELP   
L100	『八仙醉酒』〔dodge.baxianzuijiu〕提高闪躲能力
HELP
    );
    return 1;
}
