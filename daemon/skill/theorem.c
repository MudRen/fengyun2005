
inherit SKILL;

void setup(){
	set("name","无有之术");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("no_refund","attr");
}


int help(object me)
{
	write(@HELP   
以无厚入有间，则可以刃解千牛而不损其锋。
无有之术是武功中最上等的学问，可以用在各项特殊功能上，
而学习这些功能，都需要一定的无有之术为基础。

（1）天路引归（pathfinding）
需20级无有之术，学成后可在各类迷阵中迅即脱身，在岐路人处学得

（2）猴爪（monkey-claw）
需至少/2等级的无有之术，学成后可降低战斗中变换武器所引起的防
守力下降，在司空摘星处学得。

（3）千金方（prescription）
需至少/2等级的无有之术，学成后可提高各类药物和各门派基本自疗
心法（兴国、华山等除外）的治疗效率，在万春流处学得。

HELP
);
    return 1;
}
