// fengmo-staff.c by Silencer@fy4 workgroup

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","疯魔杖法");
	set("type","staff");
	set("effective_level",200);
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",250);
	set("damage_level",200);
	set("practice_limit",100);
	set("skill_class","lama");
	set("parry_msg",		({
			"$n一反手，已迎头一棍砸了下来！正是攻其所不备，转守为攻！\n",
			"$n左手斜击，拗杖横击，一招『虎尾鞭势』又快又沉，挡住$N的$w。\n",
			"$n将右臂一振，那流动的杖影倏然合而为一，化作『气龙归海』,挡住$N的$w。\n",
			"$n舞动开来，但见青光流动，杖影纵横，幻化出一片片光幕，阻住了$N的攻势。\n",
			"$n一长杖，杖头指天，杖尾点地，正是“疯魔杖法”中的『抵柱中流』,反打$N。\n",
			})
	);

	set("unarmed_parry_msg",	({
			"$n一反手，已迎头一棍砸了下来！正是攻其所不备，转守为攻！\n",
			"$n左手斜击，拗杖横击，一招『虎尾鞭势』又快又沉，挡住$N的掌力。\n",
			"$n将右臂一振，那流动的杖影倏然合而为一，化作『气龙归海』,切碎$N的内劲。\n",
			"$n舞动开来，但见青光流动，杖影纵横，幻化出一片片光幕，阻住了$n的攻势。\n",
			"$n一长杖，杖头指天，杖尾点地，正是“疯魔杖法”中的『抵柱中流』,反打$N。\n",
			})
	);
	
	action = ({
			([      "action":               
		"$N高呼酣斗，越斗越狠，像是发了狂的野兽一般，$w横扫猛击，乱劈乱戳",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N一抖$w，“呼呼呼”一连攻出四杖，杖影如山，盖向$n",
			        "damage":               40,
			        "dodge":                20,
			        "parry":                60,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":           
		"$N使出『翻身劈山』，狠极猛极，犹如发疯着魔，将$w狂舞乱打",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N双手抡杖，一招『回龙杖』向下猛击",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N一声大吼，施了一招拨风盘打之势，搂头盖顶的，直向着$n头顶上猛击了下来",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N手中的$w一招『秦王鞭石』，从背后以肩为支，扳击而下",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N忽地立打有击，使一招『如痴如颠』，手中$w连续攻出五杖之多",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			
			
	});
}

mapping query_action(object me, object weapon) {
	mapping act=([]);
	string msg;
	if(sizeof(action) > 0) {
		if (me->query_temp("pfm/fengmo_1")) {
			msg = HIB + action[random(sizeof(action))]["action"] + NOR;
			act["action"] = replace_string(msg,"$w","$w"+HIB);
			act["post_action"] = "bash_weapon";
			act["damage_type"] = "砸伤";
			return act; 
		}
		else if (me->query_temp("pfm/fengmo_2")) {
			msg = HIY + action[random(sizeof(action))]["action"] + NOR;
			act["action"] = replace_string(msg,"$w","$w"+HIY);
			act["post_action"] = "bash_weapon";
			act["damage_type"] = "砸伤";
			return act; 
		}else if (me->query_temp("pfm/fengmo_3")){
			msg = HIR + action[random(sizeof(action))]["action"] + NOR;
			act["action"] = replace_string(msg,"$w","$w"+HIR);
			act["post_action"] = "bash_weapon";
			act["damage_type"] = "砸伤";
			return act; 
		}
			
		return action[random(sizeof(action))];
	}
}

int accuracy_level(object me){
	if (me){
		if (me->query_temp("pfm/fengmo_1")) {
			return 200; 
		} else if (me->query_temp("pfm/fengmo_2")|| me->query_temp("pfm/fengmo_3")) {
			return 200; 
		}
	}
	return 0;	
}

int damage_level(object me){
	
	if (me){
		if (me->query_temp("pfm/fengmo_1")) {
			return 300; 
		} else if (me->query_temp("pfm/fengmo_2")|| me->query_temp("pfm/fengmo_3")) {
			return 400; 
		}
	}
	return 200;	
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    
    	int damage;
		
		if (!me->query_temp("pfm/fengmo_1") && !me->query_temp("pfm/fengmo_2")
			&& !me->query_temp("pfm/fengmo_3"))
			return 0;
			    	
    	if (!userp(victim))
    		victim->add_hate(me,me->query_skill("lamaism",1)*2);
    		
        return 0;
}

int help(object me)
{
	write(@HELP   
疯魔杖法与其他武功特技不同，使用期间仍然以普通招式攻击对手，
自身不产生忙乱，但杖法伤害和命中等级都大为提高。
疯魔杖法的三个特技期间命中时产生额外憎恨（密宗佛法＊２）

L40『伏虎』（fuhu）
每４分钟使用一次，命中率＋２０％，伤害率＋３０％，持续４０回合。

L120『降龙』（xianglong）
每８分钟使用一次，命中率＋２０％，伤害率＋４０％，持续２０回合，
每回合攻出两招。

L180『疯魔』（fengmo）
１２分钟使用一次，持续１５回合，每回合攻出三招。命中率＋２０％，
伤害率＋４０％，该特技只有有了相应的卷轴后才能使用。

以上特技可以通过相应的能力提高减少再次使用时间。

HELP
    );
    return 1;
}
