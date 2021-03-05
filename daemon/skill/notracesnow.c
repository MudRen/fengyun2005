// notracesnow.c

inherit SKILL;
void setup(){
	set("name","踏雪无痕");
	set("practice_limit",100);
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",120);
	set("difficulty",200);
	set("skill_class","taoist");
	set("dodge_msg", ({
	        "$n一招「夕阳残雪」轻轻巧巧地避了开去。\n",
	        "只见$n身影一晃，一式「腾云驾雾」早已避在七尺之外。\n",
	        "$n使出「鱼翔蓝天」，轻轻松松地闪过。\n",
	        "$n左足一点，一招「步履云端」腾空而起，避了开去。\n",
	        "可是$n使一招「踏雪无痕」，身子轻轻飘了开去。\n",
	        "$n身影微动，已经藉一招「龙腾万里」轻轻闪过。\n"
	}) );
}

int help(object me)
{
	write(@HELP   
L30『漫天飞雪』（mantianfeixue）提高自身闪避能力
HELP
    );
    return 1;
}
