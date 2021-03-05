// tanzhi-shentong.c

inherit SKILL;
#include <ansi.h>
mapping* throwing_action;
void setup(){

	set("name","弹指神通");
	set("type","throwing");
	set("difficulty",200);
	set("usage/throwing",1);
	set("usage/parry",1);
	set("effective_level",180);
	set("practice_limit",100);
	set("skill_class","huashan");
	
	set("parry_msg", ({
	        "$n无名指弹出，一缕指风点向$N曲池穴。$N急忙撤肘收招。\n",
		"$n右手轻弹，森森指风点向$N双目。$N几乎睁不开眼睛。\n",
		"$n浅笑声中，左手食指轻弹，一缕暗劲射向$N环跳穴。$N踉踉跄跄连连后退。\n", 
	}) );
	set("unarmed_parry_msg", ({
		"$n无名指弹出，一缕指风点向$N曲池穴。$N急忙撤肘收招。\n",
		"$n右手轻弹，森森指风点向$N双目。$N几乎睁不开眼睛。\n",
		"$n浅笑声中，左手食指轻弹，一缕暗劲射向$N环跳穴。$N踉踉跄跄连连后退。\n", 
	}) );	
	action = ({
                ([      "action":               
"$N食指微屈，轻轻弹出，$w如电光般射向$n的$l",
                "dodge":                30,
                "parry":                30,
                "force":                280,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N中指弹出，指风如刀，$w在劲风中飞向$n的$l",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N左手斜展，小指微翘将$w弹出斜刺$n的$l，仪态神妙不可方物",
                "dodge":                30,
                "parry":                30,
                "force":                340,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N无名指“嗤”地弹出，$w如冷箭般射向$n的$l",
                "dodge":                30,
                "parry":                30,
                "force":                290,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),
        ([      "action":               
"$N身形闪动，左手五指连弹，右手拇指凝力，将$w射向$n的$l ",
                "dodge":                100,
                "parry":                100,
                "force":                290,
                "damage_type":  "刺伤",
                "weapon":               "暗器",
        ]),	
	});
}

/*
int valid_enable(string usage) 
{ 
	object me;
		
	me = this_player();
	if(!me->query("marks/hs_tz_parry")){
		return usage=="throwing";	
	}
	else
		return usage=="throwing"||usage=="parry"; 
}*/

int accuracy_level(object me){
	if (me && me->query_skill("qingfeng-sword",1)>=100) 
		return (me->query_skill("qingfeng-sword",1)-100);
	return 0;
}

int damage_level(object me){
	if (me && me->query_skill("zhaixin-claw",1)>=100)
		return (me->query_skill("zhaixin-claw",1)-100);
	return 0;
}

int help(object me)
{
	write(@HELP   
L80	『弹指惊魂』（tanzhijinghun）
试图忙乱敌手三轮，若成功自我忙乱一轮，如失败自我忙乱两轮。
该特技成功率较高，但（9轮内）连续使用效能降低。

L80	『漫天花雨』（mantianhuayu）
掷出手中暗器连击对方，每40级增加一枚暗器，最多5枚。
未击中对方的暗器将飞转保护自身，受到敌人伤害时自动激发。
L120前自我忙乱2轮，L120后自我忙乱3轮。至少需要10枚暗器。

L160『心有千结』（xinyouqianjie）
另需200级幻风飘云舞，至少需要12枚暗器，自我忙乱2轮，
此招杀伤、命中率都较高，且不受对方铁布衫影响，
但每使一式，都会同时对自己造成一定的气血损伤。

HELP
    );
    return 1;
}
