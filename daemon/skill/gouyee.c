// gouyee.c

inherit SKILL;
void setup() {
	set("name","谷衣心法");
	set("effective_level",120);
	set("type","force");
	set("usage/force",1);
	set("skill_class","taoist");
	set("difficulty",200);
}

int valid_learn(object me)
{
    	if((int)me->query_skill("taoism",1) < (int)me->query_skill("gouyee",1)){
        		return notify_fail("你的天师正道不够，无法提升谷衣心法的造诣。\n");
		}
    	return 1;
}

int help(object me)
{
	write(@HELP   
灵神诀（concentrate）
需要50级的谷衣心法
将内力转化为法力，转化效率为谷衣心法等级/100。
该特技可指定数量：exert concentrate 200 就是转化200点内力

复苏灵息Ⅰ（heal）
需要50级的谷衣心法和70级的三清道术
耗费300点精力，恢复召唤兽900点气血。

复苏灵息Ⅱ（gheal）
需要100级的谷衣心法和120级的三清道术
耗费400点精力，恢复召唤兽1200点气血。（需卷轴）

复苏灵息Ⅲ（sheal）
需要150级的谷衣心法和180级的三清道术
耗费600点精力，恢复召唤兽1800点气血。（需卷轴）

倒转阴阳（manatwist）
需150级谷衣心法和220级天师正道
在30秒内加倍所有三清攻击性法术伤害，法力消耗x3
每30分钟使用一次

专注（absorbed）
需150级谷衣心法和220级天师正道
在120秒内有55%的概率在战斗中施展准备技不被打断
每3分钟使用一次，无法和倒转阴阳共存。
HELP
    );
    return 1;
}
