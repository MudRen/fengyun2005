inherit SKILL;

void setup(){
	set("name","碎玉神罡");
	set("type","force");
	set("usage/force",1);
	set("skill_class","berserker");
	set("effective_level",150);
	set("difficulty",200);
}

int help(object me)
{
	write(@HELP   
L0『碎玉撼天破诀』（damageup）
非魔法攻击的杀伤力总是取最大可能值

l0 『碎玉焚情灭诀』（powerup）
提高额外攻击力，提高额外伤害力
数值=碎玉神罡等级

L200 『碎玉断空烈诀』(forceup) 
加力（enforce）提高50%

HELP
    );
    return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
