// dabie-fu.c
// 天地交征阴阳大悲赋 - 荧河灵界心法
// 取材于“天涯明月刀”
// - neon
//

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","天地交征阴阳大悲赋");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("usage/force",1);
	set("difficulty",200);
	set("effective_level",300);
	set("skill_class","npc");
		
	set("unarmed_parry_msg",	({
			"$n左手似乎轻轻拨动了一下，又好像根本没有动过。然而$N的招式却似被\n无形的丝网牵引，莫名其妙地击在空处。\n",
			"可是$n反掌一切，冷厉如刀的掌风迫得$N内息一窒。\n",
			"$n左手单指向天，右手反掌向下，霎时周围阴风四起，竟然$n凭空失去踪影。\n",
			})
	);

	action = ({
			([      "action":
			"$n只觉得眼前一花，人影闪动间，$N已经伸掌击向$n$l",
			        "parry":                80,
			        "damage":		230,
			        "dodge":		800,
			        "force":		200,
			        "damage_type":  "瘀伤"
			]),
			([      "action":
			"$n周围忽然卷起凛凛寒风，$N掌化飞雪，卷向$n",
			        "parry":                400,
			        "force":		240,
			        "damage_type":  "瘀伤"
			]),
			([ 	"action":
			"$N使出《天地交征阴阳大悲赋》的杀式，一掌飘然拍落，封死了$n的趋避退路",
			        "parry":                700,
			        "dodge":		800,
			        "force":		360,
			        "damage":		460,
			        "damage_type":  "瘀伤"
			]),
	});
}

int valid_learn(object me) {
	if((int)me->query("max_force") < 600) {
		return notify_fail("你的内力不够！\n");
	}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	mixed foo;
	
	foo = ::hit_ob(me, victim, damage_bonus);
	if( intp(foo) ) {

		victim->receive_wound("kee", (damage_bonus + foo));
		return HIW"$N冷厉的掌风透骨而至，$n只觉得如百万钢针刺入。\n"NOR;

	}
	return foo;
}
 
