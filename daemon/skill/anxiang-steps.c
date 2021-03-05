inherit SKILL;

void setup() {
	set("name","暗香浮影");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",175);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","huashan");
	set("dodge_msg", ({
		"$n身形纵起有如风中飘舞的梅花瓣，轻轻飘了开去。\n",
		"只见$n腰往后微折，一式「雪压梅枝」轻轻松松避了开去。\n",
		"$n右足一点，身形腾空而起，恰似林间落花，轻轻闪过。\n",
		"$n凌空一个翻身，人退后了八尺，身法干净、漂亮、利落。\n",
	}) );
}


int help(object me)
{
	write(@HELP   
L50	『夜雪初积』(dodge.yexuechuji)
令敌人忙乱三回合，如果失败则自身忙乱两回合
HELP
    );
    return 1;
}
