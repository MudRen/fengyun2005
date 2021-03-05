// springrain-sword


#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","春雨刀法");
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","npc");
	set("parry_msg", ({
        	"$n身形轻舞，一式"HIG"「云破月来花弄影」"NOR"幻出满天刀光，仿佛浮云流水般
将$N所有招式消于无形。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n身形一变，幽然长叹一声"HIC"「此情可待成追忆」"NOR"，$N忆起不堪往事，不
由地痴了。\n",
	}) );	
	action = ({
		([	"action":		"$N随声漫吟"HIG"「迢迢不断－如－春－雨──」"NOR"，$w就像迢迢不断的春雨，挥出了一波绵绵细雨洒向$n。",
			"force":		70,
			"dodge":		30,
			"parry":		30,
		        "damage" : 		100,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N临风而立，挥洒之间"HIC"「昨夜西风－碉－碧－树」"NOR"，仿佛清风拂树，$w星星点点挥向$n的$l。",
			"force":		90,
			"dodge":		50,
	      		"parry":		40,
		        "damage" : 		150,
			"damage_type":	"刺伤"
		]),
		([	"action":		HIR"「满地落花－红－带－雨」"NOR"的低喝中，$N的$w挽起数十朵刀花带起了一片绚丽的血雨涌向$n。",
			"force":		90,
			"dodge":		50,
			"parry":		40,
		        "damage" : 		200,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N双眸凝望远方，一式"HIY"「似曾相识－燕－归－来」"NOR"中身形不可思议的曼妙一转，$w顺势划出了一道优美的月弧。",
			"force":		80,
			"dodge":		20,
			"parry":		30,
		        "damage" : 		300,
			"damage_type":	"刺伤"
		]),
	});
}


