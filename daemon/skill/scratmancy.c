// scratmancy.c
inherit SKILL;

void setup() {
	set("name","三清符术");
	set("type","scratching");
	set("difficulty",250);
	set("effective_level",200);
	set("practice_limit",100);
	set("usage/scratching",1);
	set("skill_class","taoist");
}

int valid_learn(object me) {
	if((int)me->query_skill("taoism",1) < (int)me->query_skill("scratmancy",1)) {
		return notify_fail("你的天师正道修为不够，无法领悟更高深的三清符术。\n");
	}
	
	return 1;
}

int practice_skill(object me)
{	
	object bug;
	
	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"+ bug->name() + "吧！\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("你的法力不够。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("你闭目凝神，神游物外，开始修习三清符术中的法术....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else		bug = new("/obj/npc/mind_beast");

		write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->set("combat_exp", (int)me->query("combat_exp")+100);
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n");
	}	
	else return 1;
}


int help(object me)
{
	write(@HELP   
飞行和遥感类：
L20 往生符（earth-warp）地府往返
L35 天眼符（far-vision）遥感敌手
L50 九遁符（drift-warp）飞行到有鼎之处，参看门派帮助，
		符术等级越高，能感应到的鼎意越多

招鬼类（只能同时招出一个）,召唤兽的经验等级取决于你的有效符术，
技能取决于你的技能（雪影剑法、踏雪无痕等等）。
L30 召鬼符（zhaogui）
召唤鬼卒，鬼卒气血比主人略低，会使用白雪皑皑
L100 天師符（tianshi）
召唤天兵，天兵气血比主人高，会使用漫天飞雪和吸引敌人注意
L160 上君符（shangjun）
召唤真君，气血很低，但会使用法术攻击敌人
L195 祭死符（jisi） 
召唤无常，气血比主人略低，攻击可吸取敌人气血，可使用法术在一定
时间内禁忌敌人使用特技
*如果召唤兽在战斗中死去，他所引起的憎恨将转给主人
*召唤兽不在战斗中时主人可主动将其驱除（dismiss xxx）耗费300心神

恢复类：
L55 续气符/ L110 续血符/ L160 续命符（qi）
L60 续精符/ L120 续元符/ L170 续魄符（jing）
L65 续心符/ L130 续神符/ L180 续魂符（shen）
L70 续法符/ L140 续灵符/ L200 续道符（fa）
*使用恢复类符法有三个步骤，写符、燃符（战斗中），而后就生成一
张可以用来恢复相应精气神的符了。
HELP
    );
    return 1;
}
