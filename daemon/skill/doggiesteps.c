// doggiesteps.c

inherit SKILL;

void setup()
{
	set("name","野狗步法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","beggar");
	set("dodge_msg", ({
		"但是$n身形飘忽，轻轻一纵，一招『野狗扑食』，举重若轻的避开这一击。\n",
		"$n身随意转，一式『野狗斜纵』，倏地往一旁挪开了三尺，避过了这一招。\n",
		"可是$n侧身一让，使出『野狗打滚』，$N这一招扑了个空。\n",
		"却见$n足不点地，一招『野狗上蹿』，往旁窜开数尺，躲了开去。\n",
		"$n身形微晃，使出『野狗下跳』，有惊无险地避开了$N这一招。\n",
		"$n身形往上一拔，一招『野狗左摇』，一个转折落在数尺之外。\n"
	}) );
}

int help(object me)
{
	write(@HELP   
『狗尾续貂』（dodge.gouweixudiao）
需100级野狗步法，80级乞讨之术，持续时间120秒，若战斗中使用自我
忙乱2轮。使用该特技后，打狗杖法的各个特技（如引字诀等）有20％
几率最后增加一个额外攻击。通过门派能力增强可以达到40％几率。

『狗急跳牆』（dodge.goujitiaoqiang〕
需200野狗步法，L160乞讨之术，每15分钟使用一次，耗费内力150点。
绝地求生之技，连续三次试图逃跑，（不受逃跑的三轮限制），如果
失败则自我忙乱2轮。

HELP
    );
    return 1;
}
