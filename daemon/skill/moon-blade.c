// spring-blade.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","圆月魔刀");
	set("type","blade");
	set("difficulty",1000);
	set("usage/blade",1);
	set("usage/parry",1);
	set("usage/dodge",1);
	set("effective_level",400);
	set("skill_class","npc");
	
	set("dodge_msg", ({
    		"$n哼了一声，向后退了一步，顿时就将$N的攻势消弭于无形！\n",
		"$N只觉眼前一花，$n。。。竟消失了，$N再定睛一看，$n竟已绕到了$P背后！\n",
		"$n不退反进，$N的出招完全扑了一个空。\n",
		"$n身形似乎根本就没有动，但$N却连$n的衣角都没有沾到！\n",
	}) );

	set("parry_msg", ({
	        "$n微微冷笑，$N只觉凉风袭体，只得生生撤回手中的$w。\n",
	        "只听「啪」的一声，$N手中的$w已被弹开，但$P却连$n使出了什么招式都没有看到！\n",
	        "$n竟不退不让，$N手中忽然一麻，$w竟刺在了$n手中$v的刀鞘上！\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n微微冷笑，$N只觉凉风袭体，只得生生将自己的出招收回。\n",
	        "只听「啪」的一声，两人对了一招，$N脸色惨白，连退几步。\n",
	        "$n竟不退不让，$N手中忽然一麻，这一招竟击在了$n手中$v的刀鞘上！\n",
	}) );
	action = ({
        ([      "action":               "$N手中$w一闪，$n根本没有看清出$N的出刀！",
                "damage":               100,
                "dodge":                400,
		"parry":		400,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N人未动，刀已出，$n只觉阴风拂面。。。。。。",
		"dodge":		300,
		"parry":		500,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身形一折，$w刀光不定，$n全身上下顿时被笼罩其中！",
                "damage":               20,
		"dodge":		600,
		"parry":		40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w竟如圆月一般弯转，无论速度还是角度都令$n难以闪躲。",
		"dodge":		1400,
		"parry":		1200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$n眼前一花，$N的$w竟已到了$n的面前！",
                "damage":               40,
		"dodge":		10,
		"parry":		400,
                "damage_type":  "割伤"
        ]),

	});
}

int practice_skill(object me)
{
       return notify_fail("「圆月魔刀」精妙无比，你无论如何练习也无法体会其精义所在！\n");
}

