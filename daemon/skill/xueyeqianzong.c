inherit SKILL;

void setup(){
	set("name","雪野潜踪");
	set("practice_limit",100);
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",190);
	set("difficulty",200);
	set("skill_class","wolfmount");
	set("dodge_msg", ({
		"$n脚下游移不定，轻飘飘，不费力地闪在一旁。 \n",
		"$n用一种近似漂浮的动作滑开数步，躲开了$N的攻击。 \n",
		"$n侧身斜纵，远远跳开，同时回头紧盯$N招式的破绽。 \n",
		"$n左右闪动，迷惑了$N的视线，令$N的招式落空。 \n"
	}) );
}

int help(object me)
{
	write(@HELP   
雪野潜踪的两个不同步法特技只能同时使用一个
持续时间10分钟

『狼突』（dodge.wolverine）
提高自身的攻击力，注意该增值不会影响博浪特技的杀伤力
Ｉ：需50级雪野潜踪，提高50点有效攻击力
ＩＩ：需120级雪野潜踪，提高80点有效攻击力
ＩＩＩ：需160级雪野潜踪，提高120点有效攻击力，需阅读有关卷轴

『虎踞』（dodge.feline）
增加自身的气血值，
Ｉ：需130级雪野潜踪，提高400点气血
ＩＩ：需160级雪野潜踪，提高800点气血，需阅读有关卷轴
ＩＩＩ：需160级雪野潜踪，提高1300点气血，需阅读有关卷轴

HELP
    );
    return 1;
}
