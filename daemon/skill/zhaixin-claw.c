//	摘心手的特效
//  华山派武功的伤害率提高１０％，每１０级提高０。５％
// 	华山派武功: qingfeng-sword, tanzhishentong, zhaixin-claw


#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","摘心手");
	set("usage/unarmed",1);
	set("effective_level",190);
	set("damage_level",200);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","huashan");
	set("unarmed_parry_msg", ({
       	"$n指尖发出丝丝寒气抓向$N手腕，$N急忙沉腕避开。\n",
		"$n左手一沉，右手旁引，$N只觉手中一空，招式击偏。 \n",
	}) );
	action = ({
        ([      "action":               
"$N左手直抓，右手斜挥，一招“摘星揽月”抓向$n$l",
                "dodge":                100,
                "parry":                140,
                "force":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N一招“北岭折梅”，左手横胸，右手成爪，直击$n$l",
                "dodge":                150,
                "parry":                100,
                "force":                170,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出“长空紫气”，身形闪动间，爪影森森攻向$n$l",
                "dodge":                50,
                "parry":                120,
                "force":                140,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N回步斜身，右手成爪反挥一个圆弧，一式“鹞子翻身”击向$n$l",
                "dodge":                310,
                "parry":                200,
                "force":                290,
                "damage_type":  "抓伤"
        ]),
	});
}


int accuracy_level(object me){
	if (me && me->query_skill("qingfeng-sword",1)>=100) 
		return (me->query_skill("qingfeng-sword",1)-100);
	return 0;
}

int damage_level(object me){
	if (me && me->query_skill("zhaixin-claw",1)>=100)
		return (100+ me->query_skill("zhaixin-claw",1));
	return 200;
}

int help(object me)
{
	write(@HELP   
摘心手100级以上，每10级提高华山武功（摘心手、清风剑、弹指神通）
伤害等级+10。

L100	『摘心』（zhaixin）
对敌人的心神造成极大伤害，每30分钟使用一次。
伤害力=500 + 经验等级 * 摘心手等级/5
HELP
    );
    return 1;
}