inherit SKILL;

void setup() {
	set("name","流云刺");
	set("type","dagger");
	set("difficulty",200);
	set("usage/dagger",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","npc");
	set("unarmed_parry_msg",			({
		"$N盘身驻地，一招「川流不息」，挥出一片流光般的光影，反向$n的全身涌去。\n",
		"$N使出一招「佛光普度」，左臂回收，右掌引内力直刺$n的$l,避得$n连连后退。\n",		
			})
	);

	action = ({
		([	"action":	"$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
			"damage":		70,
			"dodge":		70,
			"damage_type":	"割伤"
		]),
		([	"action":	"$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
			"damage":		40,
			"damage_type":	"割伤"
		]),
		([	"action":	"$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
			"damage":		20,
			"damage_type":	"割伤"
		]),
		([	"action":	"$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
			"damage_type":	"割伤"
		]),
		([	"action":	"$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
			"damage":		70,
			"damage_type":	"割伤"
		]),
		([	"action":	 "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
			"damage":		30,
			"damage_type":	"割伤"
		]),
		([	"action":	"$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
			"damage":		50,
			"damage_type":	"割伤"
		]),
	});
}


