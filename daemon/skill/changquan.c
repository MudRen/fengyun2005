// changquan.c
inherit SKILL;

void setup() {
	set("name","少林长拳");
	set("type","unarmed");
	set("effective_level",100);
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("difficulty",100);
	set("skill_class","official");
	set("parry_msg",			({
			"$n以守为攻，一招「反客为主」，猛击$N握$w的手腕。\n",
			"$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
			})
	);
	set("unarmed_parry_msg", 	({
			"$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
			"$n以守为攻，一招「反客为主」，猛击$N的手腕。\n",
			})
	);
	action = ({
			([	"action":		"$N使一招「黑虎掏心」，对准$n的$l「呼」地一拳",
				"force":		80,
				"parry":		60,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N扬起拳头，一招「泰山压顶」便往$n的$l招呼过去",
				"force":		60,
				"parry":		30,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N左手虚晃，右拳「中宫直进」便往$n的$l击出",
				"force":		60,
				"parry":		30,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N步履一沉，左拳拉开，右拳使出「老汉推车」击向$n$l",
				"force":		60,
				"parry":		80,
				"damage_type":	"瘀伤"
			]),
	});
}


int help(object me)
{
	write(@HELP   
『玉环鸳鸯拳』（yuhuan）
220级有效拳脚，连出七拳，自我忙乱5回合，
250级少林长拳，连出七拳，自我忙乱4回合，
额外攻击力＝有效拳脚／１０
额外加力(enforce)＝有效拳脚／７
至少需要120点内力。
HELP
    );
    return 1;
}
