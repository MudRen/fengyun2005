// heart-listening.c
// annie 07.2003
// 用以增加sen，附带一个小小用处cast telepathy

inherit SKILL;
void setup(){
	set("name","幻念聆音");
	set("difficulty",200);
	set("usage/spells",1);
	set("type","spells");
	set("effective_level",200);
	set("skill_class","moon");
}

int practice_skill(object me)
{	
	return notify_fail("幻念聆音无法练习。\n");
}

int help(object me)
{
	write(@HELP   
L40 『他心移物』（telepathy）
夫妻之间相互传递物件

L80 『遗心忘恨』（yixinwanghen）
将敌人的憎恨全部清零，注意这并不会停止战斗，
而只是令敌人开始随机选择目标
每2分钟使用一次。

L120『无方变幻』（wufangbianhuan）
在９０秒内真气流转以减少对手造成的忙乱，
每５分钟使用一次。

L200『朝雨晚晴』（zhaoyuwanqing）
需阅读有关卷轴后才能使用。每30分钟一次
另需150级天岚凝舞。救命特技，最多持续60秒。
第一册：闪避6次攻击
第二册：闪避9次攻击
第三册：闪避12次攻击
HELP
    );
    return 1;
}
