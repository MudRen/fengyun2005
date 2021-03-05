// jin-gang.c
inherit SKILL;
void setup() {
	set("name","金刚不坏功");
	set("type","iron-cloth");
	set("usage/iron-cloth",1);
	set("effective_level",150);
	set("ic_effect",100);
	set("bounce_ratio",10);
	set("difficulty",250);
	set("skill_class","lama");
	set("absorb_msg", ({
	        "$n双臂一震，金刚不坏功力决堤似的澎湃而出。\n",
	        "$n施展出金刚不坏功中的「弹」字诀，一股弹力传入$N的体内。\n",
	        "$n使出一招「苦海无涯」，凝虚为实，浑身硬如金刚。\n",
	        "$n施展出金刚不坏功，对抗$N的一击之力。\n",
	}) );
}


int valid_learn(object me)
{
	if( (int)me->query_skill("lamaism",1) <= (int)me->query_skill("jin-gang",1)) {
		return notify_fail("你的密宗佛法修为不够，无法领悟更高深的金刚不坏功。\n");
	}
	return 1;
}

int effective_level(object me)
{
	if (me)
	if (userp(me) && me->query("class") != "lama")
		return 75;
		
	return 150;
}


int help(object me)
{
	write(@HELP   
L150『刀枪不入』（daoqiangburu）
消去敌人对自身气血伤害的并将部分反击对手

HELP
    );
    return 1;
}
