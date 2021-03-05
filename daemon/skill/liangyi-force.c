// taijiforce.c

inherit SKILL;

void setup(){
	set("name","两仪心法");
	set("type","force");
	set("difficulty",250);
	set("usage/force",1);
	set("effective_level",100);
	set("skill_class","task");
}

int help(object me)
{
	write(@HELP   
L100 『如封似闭』（rufengsibi）
试图令敌人忙乱，自身忙乱一轮，若成功敌人忙乱两轮
每次消耗内力= 250 - 两仪心法等级
此特技使用时无需enable，只需要使用命令
perform rufengsibi
HELP
    );
    return 1;
}
