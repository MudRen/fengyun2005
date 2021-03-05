// hawk-steps.c

inherit SKILL;
void setup() {
	set("name","鲲鹏步法");
	set("practice_limit",100);
	set("usage/dodge",1);
	set("usage/move",1);
	set("type","step");
	set("difficulty",200);
	set("effective_level",200);
	set("skill_class","fugui");
	set("dodge_msg", ({
		"$n轻张双臂，使出「苍茫古木连穷巷」，轻轻巧巧地避了开去。\n",
		"只见$n身影一晃，一式「寥落寒山对虚牖」早已避在七尺之外。\n",
		"$n藉著激起的劲风,瞬间移形换位，使出「誓令疏勒出飞泉」，轻轻松松地闪过。\n",
		"$n左足一点，漂浮不定的身法恰似「不似颍川空使酒」，腾空而起，避了开去。\n",
		"可是$n使一招「贺兰山下阵如云」，意境已达形泣风动般的诡异,轻轻飘了开去。\n",
		"$n身影微动，已经藉一招「羽檄交驰日夕闻」轻轻闪过。\n",
		"$n势如风行草偃，犹如诗意「试拂铁衣如雪色」，向后疾退而去。\n",
		"$n双脚真气一提，身形变换「聊持宝剑动星文」，顿时风起叶飞，雪花盖顶，人已无影无踪。\n",
	}) );
}


int help(object me)
{
	write(@HELP   
L100『鹰翔九天』（dodge.yingxiangjiutian）提高自身速度

L160『饥鹰搏兔』（dodge.jiyingbotu）
在10回合内反击对手所有招式，每三分钟使用一次

HELP
    );
    return 1;
}
