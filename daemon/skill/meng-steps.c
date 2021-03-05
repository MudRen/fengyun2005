//meng-steps.c  幻梦步法

inherit SKILL;
void setup() {
	set("name","幻梦步法");
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",180);
	set("skill_class","bat");
	set("dodge_msg", ({
		"$n如一阵清风，舒缓地闪过了$N的凌厉攻势。\n",
		"$n双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
		"$n身形陡地变得飘忽不定，令$N无法看清。\n",
		"$n便如闲庭信步，在弹指间已然退出丈外。\n",
		"可是$n左一转，右一绕，身影已消失不见。\n",
	
	}) );
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 ){
		return notify_fail("你的内力不够，没有办法练幻梦步法。\n");
	}
	if (me->query_skill("wuzheng-force",1)<me->query_skill("meng-steps",1))
		return notify_fail("你的无争心法火候不够。\n");
	return 1;
}
