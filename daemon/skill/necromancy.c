// necromancy.c

inherit SKILL;
void setup(){
	set("name","三清道术");
	set("type","spells");
	set("usage/spells",1);
	set("skill_class","taoist");
	set("practice_limit",100);
	set("effective_level",220);
	set("difficulty",250);

}	

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < (int)me->query_skill("necromancy",1))
		return notify_fail("你的天师正道修为不够，无法领悟更高深的三清道术。\n");
	return 1;
}

int practice_skill(object me)
{	
	object bug;
			
	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"
			+ bug->name() + "吧！\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("你的法力不够。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("你闭目凝神，神游物外，开始修习三清道术中的法术....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

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
L10 阴阳眼（vision）：
给自己/队友看鬼的能力

L20 青冥之箭（netherbolt）
攻击敌人的气血，将其中的50%转给自身，是三清精气神三个箭法中较弱的一个

L40 紫幽之箭（drainerbolt）
攻击敌人的精力，将其中的50%转给自身

L60 苍灵之箭（feeblebolt）
攻击敌人的心神，将其中的50%转给自身

L80 白云之箭（healbolt）
将自身气血转移给每个队友，三清道术120级以下，自损气血三清道术*5，
120级以上，自损气血三清道术*10。耗费法力300点。                    
      
L100 天罡伏魔（thunderbolt）
攻击所有敌人的心神，对鬼神杀伤力加倍。

L135 燃殇绝焰（demonicbolt）
伤害的种类由上一个Bolt种类决定，杀伤力更大，但在使用前有3轮准备，在
此期间如果受到伤害则会打断作法。

L170 御雷苍华（thunderstorm）
攻击所有敌人的心神，对鬼神杀伤力加倍，与燃殇绝焰类似，在使用前有三轮
准备，如果受到伤害则会打断作法。

HELP
    );
    return 1;
}
