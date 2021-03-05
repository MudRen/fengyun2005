// yiqiforce.c
#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","混元一气功");
	set("usage/parry",1);
	set("usage/force",1);
	set("usage/iron-cloth",1);
	set("usage/unarmed",1);
	set("ic_effect",100);
	set("type","force");
	set("difficulty",1000);
	set("bounce_ratio",40);
	set("effective_level",500);
	set("skill_class","npc");
	set("absorb_msg",			({
			"$n身体虚转，双手微划，无坚不摧的混元一气功澎湃而出。\n",
			"$n施展出混元一气功，浑身肌肤坚如寒铁。\n",
			"$n身型微展，混元一气充斥了丈许空间。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
			"$n长袖一甩，一股大力将$N送出丈外。\n",
			"$n施展出「混元无我」，轻描淡写的化解了$N的攻势。\n",
			})
	);

	action = ({
			([      "action":
			"$N使出一招「三重天地混元」，左手聚出一团混元一气击向$n的$l",
			        "force":                300,
			        "damage_type":  "瘀伤"
			]),
			([      "action":
			"$N使出一招「五重天地混元」，右手聚出一团混元一气击向$n的$l",
			        "force":                500,
			        "damage_type":  "瘀伤"
			]),
			([ 	"action":
			"$N使出一招「七重天地混元」，双手聚出一团混元一气击向$n的$l",
			        "force":                700,
			        "damage_type":  "瘀伤"
			]),
			([	"action":
			"$N使出一招「九重天地混元」，全身腾空而起，全身化作一团混元一气击向$n的$l",
			        "force":                900,
			        "damage_type":  "瘀伤"
			]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor) {
	mixed foo;
	int force;
	
	foo = ::hit_ob(me, victim, damage_bonus, factor);
	if(intp(foo) && (damage_bonus + foo > 0) 
&& random(3*(me->query_skill("yiqiforce", 1)/2)) > (damage_bonus + foo)) {
		victim->receive_wound("kee", (damage_bonus + foo));
		victim->receive_wound("gin", (damage_bonus + foo));
		victim->receive_wound("sen", (damage_bonus + foo));
		force = victim->query("force");
		victim->set("force", force-random(10)-1);
		victim->set("max_force", 0);
		return "$N的混元一气功摧毁了$n的真元！！！！\n";
	}
	return foo;
}

void skill_improved(object me) {
	if((int)me->query_skill("incarnation", 1)  < random(501) ) {
		tell_object(me, HIR "\n你突然全身发麻！走火入魔了！！....\n\n" NOR);
		me->skill_death_penalty(me->query("combat_exp"));
		me->delete_skill("yiqiforce");
		me->unconcious();
	} 
}

