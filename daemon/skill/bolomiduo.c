// bolomiduo.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","婆萝蜜多心经");
	set("type","force");
	set("effective_level",120);
	set("usage/force",1);
	set("difficulty",200);
	set("skill_class","lama");
}


//	明尊护体

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	
	if(!me->query_temp("pfm/dz_roar") || me->query("class")!= "lama"
		|| me->query_skill_mapped("iron-cloth")!= "jin-gang")
		return 0;
	
	data["msg"] = BRED + HIY"$n周身霞霓环绕，光华夺目，$N的攻势尽皆消逝！\n"NOR,
	data["damage"] = -damage;	// In Roar, we set resistance/kee = 100, so damage here is irrelevant.
	return data;	
}

int help(object me)
{
	write(@HELP   
L0 『婆罗蜜多』（bolo）疗伤心法

L100『舍身』（sheshen）
另需100级密宗佛法，将自身气血的15%转化为最大法力的80%。
每20秒可使用一次

L150『雷霆』〔leiting〕
另需150级金刚不坏，被敌人击中后自动反击伤害敌人的心神，
提高10%对心神伤害的抵抗能力（仅为自身），可用于同伴。

L160『霹雳』〔pili〕
另需180级金刚不坏，被敌人击中后自动反击伤害敌人的精力，
提高10%对精力伤害的抵抗能力（仅为自身），可用于同伴。

L160『活佛转世』〔huofo〕
另需170级密宗佛法，减半2word和3word的mana需求，
无法与『霹雳』和『雷霆』连用，仅用于自身。
效果持续10分钟。

HELP
    );
    return 1;
}
