inherit SKILL;
void setup(){
	set("name","大摔碑手");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",180);
	set("type","unarmed");
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","npc");
	set("parry_msg", ({
      		"$n怪叫一声，以硬碰硬把$N震开五步。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n左手虚晃，右手早对$N的要害伏下数个后招。\n",
	}) );	
	action = ({
		([	"action":		"$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
			"force":		300,
			"parry":		100,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
			"force":		300,
			"parry":		200,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
			"force":		300,
			"parry":		200,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
			"force":		300,
			"parry":		500,
			"damage_type":	"瘀伤"
		]),
	});
}

