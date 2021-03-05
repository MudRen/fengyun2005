// cloud-dance.c
inherit SKILL;

void setup() {
	set("name","幻风飘云舞");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",175);
	set("difficulty",200);
	set("skill_class","huashan");
	set("dodge_msg", ({
		"$n悠悠飘开，如秋空中的一缕轻云。\n",
		"$n纤腰轻轻一折，如风舞流云避开了$N的攻势。\n",
		"$n似旋风中飘舞的羽毛，身影闪动姿态妙曼，悠闲地避开了$N的招式。\n",
		"如同冷冽的晨风中落下的梅花，$n款款向后飘开。\n",
	}) );
}

int help(object me)
{
	write(@HELP   
L100:『夜雪初积』（dodge.yexuechuji）
需100级的暗香浮影和幻风飘云舞，
与暗香浮影的特技类似，但成功率有显著提高（取决于两者等级之和）
令敌人忙乱三回合，如果失败则自身忙乱两回合

L120:『摘心式』  （dodge.zhaixin）
与摘心手的『摘心式』类似但成功率、杀伤力都有提高，
对敌人的心神造成极大伤害，每30分钟使用一次。
伤害力= 500+ 经验等级*（摘心手等级+幻风飘云舞/2）/5
	
L150:『离人夜归』（dodge.yegui）
在同伴尸体旁回复同伴的经验损失，每次耗费500点灵力，
需要150级的幻风飘云舞、150级的寒梅心法，耗费死者8点评价。
该特技需要卷轴方能领悟，三阶段的卷轴分别恢复60%、70%、90%损失。	

以下舞蹈类特技为华山独有
效果可与绝大部分其他门派的特技效果叠加，可极大程度提高队伍
的战斗能力。每3回合可使用一次舞技，效果延续时间5回合，
但使用后三回合内自身防守力会有一定下降。
舞蹈类特技均需要200级幻风飘云舞，并需达到一定经验等级
以下等级指使用者的经验等级而非技能等级

L70:『雪里春信』（dodge.chunxin）
恢复队伍的内力(至少间隔10秒)，需100点内力，自我忙乱1轮
恢复队伍内力=幻风飘云舞等级
恢复自身内力=幻风飘云舞等级-100

以下四个舞技各需50内力使用，无自我忙乱
L80:『蜃影千幻』（dodge.qianhuan）提高招架能力(+100)
L90:『梅心惊破』（dodge.jingpo） 对气血伤害的抵抗能力(+10%)
L100:『疏影横斜』（dodge.hengxie）提高闪躲能力(+100)
L110:『九遁绝杀』（dodge.juesha） 增加队伍武功的攻击力(+100)


HELP
    );
    return 1;
}