// devil-spells.c

inherit SKILL;
void setup(){
	set("name","青冥魔咒");
	set("usage/spells",1);
	set("type","spells");
	set("effective_level",150);
	set("difficulty",200);
	set("skill_class","demon");
	
		
}	


int help(object me)
{
	write(@HELP   
『魔火炼魂』（soul-flame）
燃烧周围所有敌人，持续造成4次精气神伤害，
此特技有两个特点：
1）每次伤害数量为上一次的2/3
2）烧中的第一个对手伤害最大，下一个对手为1/2，
再下一个为1/3。。。依次递减

四次伤害之和：
伤精= lvl/num*3/2 *65/27
伤气= (lvl/num*2 + 50)* 65/27
伤神= lvl/num*4/3 *65/27

Lvl = 有效咒术等级
num = 第几个被烧到的

HELP
    );
    return 1;
}
