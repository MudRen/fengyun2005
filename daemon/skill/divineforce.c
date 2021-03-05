// annie 6.27

inherit SKILL;

void setup(){
	set("name","破邪心经");
	set("type","force");
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","demon");
	set("effective_level",150);
}

int help(object me)
{
	write(@HELP   
此系列特技使用perform force.xxxx 形式	
为NPC专用，没有经过完整测试
	
『抱残守缺』（baocanshouque）
令对手的护体硬功在60秒内失去效用

『无独妙谛』（wudumiaodi）
令敌手所学技能混淆，造成心神伤害，
心神伤害的数量=敌手技能种类*敌手技能种类*2
其效果将在120秒后消失

『溃散溢体』（deathgrip）
令敌手在60秒内对气血伤害抵抗下降100%

『万痛聚身』（lessdeathgrip）
令敌手在60秒内对气血伤害抵抗下降50%

『乾坤大挪移』（disorder）
令所有的对手相互攻击一轮

『鬼神破灭』（guishenpomie）
驱逐在场所有敌人的召唤兽

『鬼神破灭』（check_gspm）
一个检查在场召唤兽的函数

『魂神飞离』(lobotomy)
麻婆寒练术

『万象破灭』(manaburst)
将对手的灵法内力转为精气神伤害

『有无相生』(manaflare)
将对手内力转为气血伤害

『千结缠缚』(mystbusy)
状态，每次发作时当前忙乱+1

『灵华仙迹』（replenish）
补充身上的暗器数目

『妖魔现形』（terror）
试图吓走在场所有敌人

『妖魔现形』（terror2）
试图吓走在场N-1个敌人

『空魂异血』（curseflesh）
30秒内所有恢复转化为伤害

buffup 和 resurrect 系列不再使用

HELP
    );
    return 1;
}
