//燕南天之南天剑法

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","南天剑法");
	set("type","sword");
	set("difficulty",300);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",300);
	set("skill_class","npc");
	set("parry_msg", ({
        	"$n挺剑一招「浮云终日行」,身形矫若游龙，$N的攻势陡然失去了方向。\n",
		"$n镇定自若，随手一剑「游子终不至」悄然化解了$N漫天的攻势。\n",
		"$n长叹一声，手中$v挥洒如风，$N疾风般的攻势已被一招「江湖多风波」化解得无影无踪。\n",
		"$n疾风骤雨般使出一式「舟楫恐失坠」，须臾间已从$N中抢回主动。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n挺剑一招「浮云终日行」,身形矫若游龙，$N的攻势陡然失去了方向。\n",
		"$n镇定自若，随手一剑「游子终不至」悄然化解了$N漫天的攻势。\n",
		"$n长叹一声，手中$v挥洒如风，$N疾风般的攻势已被一招「江湖多风波」化解得无影无踪。\n",
		"$n疾风骤雨般使出一式「舟楫恐失坠」，须臾间已从$N中抢回主动。\n",
	}) );

	action = ({
		([	"name":			"冠盖满京华",
			"action":		
			"$N似鬼魅地倏退忽进，一招「冠盖满京华」剑势有若长江大河，无孔不入地攻向$n",
			"dodge":		200,
			"parry" :		400,
			"damage":		170,
			"force" : 		200,
			"damage_type":	"刺伤"
		]),
		([	"name":			"斯人独憔悴",
			"action":		
			"$N心神归一，反手一式「斯人独憔悴」,$w化作长虹，分中猛劈$n",
	                "dodge":                220,
	                "parry" :               200,
	                "damage":               300,
	                "force" :               100,
			"damage_type":	"刺伤"
		]),
		([	"name":			"千秋万岁名",
			"action":		
			"$N双目低垂，$w触地，有若老僧入定，忽又箭步抢前对着$n的胸口就是一招「千秋万岁名」！",
	                "dodge":                220,
	                "parry" :               340,
	                "damage":               140,
	                "force" :               250,
			"damage_type":	"刺伤"
		]),
		([	"name":			"寂寞身后事",
			"action":		
			"$N不退反进，身如疾风，凝神使出一式「寂寞身后事」，风卷雷奔般一剑侧劈$n的$l！",
	                "dodge":                170,
	                "parry" :               240,
	                "damage":               250,
	                "force" :               150,
			"damage_type":	"刺伤"
		]),
	});
}


