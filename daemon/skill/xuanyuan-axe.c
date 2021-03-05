inherit SKILL;
#include <ansi.h>
#include <combat.h>

void setup(){
	set("name","轩辕斧法");
	set("type","axe");
	set("usage/axe",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","knight");
	set("parry_msg", ({
			"结果$n一招「神行飘缈」，挥动手中$v格开了$N的$w。\n",
			"结果$n手中$v一分，一招「神转天盘」，斜劈$N的$w。\n",
			"结果$n手中$v抡动如飞，一招「二神垂眉」，荡开$N的$w。\n",
			"结果$n手中$v飞速旋转，一招「鬼斧神工」，反扫$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n手中的$v舞动如飞，一招「鬼决天河」，封住了$N的攻势。\n",
			"$n身影晃动，一招「鬼哭神嚎」，反砍$N的下盘。\n",
			"$n身形一矮，一招「万魔同体」，躲过$N的攻势。\n",
			"$n手中的$v自上而下，一招「幽冥幻影」，反劈$N的要害。\n",
	}) );
	action = ({
		(["action":
"$N手中$w舞动，脚步一沉，一招「阴阳三合」，手中$w如流星般直劈$n的$l",
				"damage":               210,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "割伤"
		]),
		(["action":
"$N一招「圜则九重」如惊鸿一撇般令$n毫无警讯，一瞬间$w已来至$n的面前",
				"damage":               210,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "割伤"
		]),
		(["action":
"$N手中$w如陀螺般旋转不停，一招「天何所沓」，直取$n的各处要害",
				"damage":               200,
				"dodge":                140,
				"parry":                100,
				"damage_type":  "割伤"
		]),
		(["action":
"$N纵身一跃，手中$w牵动著周遭的气流，一招「日月安属」，漩涡般向$n$l劈去",
				"damage":               150,
				"dodge":                100,
				"parry":                100,
				"damage_type":  "割伤"
		]),
		(["action":
"$N手中$w彷佛如地狱幽灵般，一招「地方九则」，突然劈至，一股寒气从$N的斧中透出",
				"damage":               250,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "割伤"
		]),
		(["action":
"突然间彷佛空间被掏空般，$N手中$w化作一溜烟尘，一式「雄虺九首」使$n毫无着力感",
				"damage":               210,
				"dodge":                210,
				"parry":                240,
				"damage_type":  "割伤"
		]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob, snake;
	object weapon;

	weapon = me->query_temp("weapon");

	if( ANNIE_D->check_buff(me,"poison_spirit") ) {
		if( me->query_temp("max_snake") < me->query_temp("poison_spirit") ) {
			message_vision( HIG "$N"HIG"手中"+ weapon->name()+ HIG "飞出一团绿雾。\n"NOR, me, victim);
			snake = new("/obj/npc/poison_spirit.c");
			snake->move(environment(me));
			me->add_temp("max_snake",1);
			snake->invocation(me);
		}
	}

	if( random(damage_bonus) < 350 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "spear" ) {
			if( victim->query_skill_mapped("spear") == "xuezhan-spear" || victim->query_skill_mapped("spear") == "yue-spear" || victim->query_skill_mapped("spear") == "duanhun-spear" ) {
				if( me->query_skill("axe") + 50 > victim->query_skill("spear") ) {
					switch( random(3) ) {
						case 0:
							message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR, me, victim);
							break;
						case 1:
							message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR, me, victim);
							break;
						case 2:
							message_vision(HIR "\n$N招式虎虎生风，$n逐渐施展不开了！" NOR, me, victim);
							break;
					}
					return random(me->query_skill("axe")) * 2;
				}
			}
		}
	}
	return 0;
}

int help(object me)
{
	write(@HELP
对使用血战枪法、中平枪法、断魂枪法招架的对手有额外伤害力

L40 『鬼斧神工』（guifushengong）攻击技能
两连击，自我忙乱2轮，
额外攻击力=轩辕斧法等级

L160『九气破霄』（jiuqipoxiao）
五连击，自我忙乱3轮，每30秒可使用一次。
额外攻击力=轩辕斧法等级
HELP
	);
	return 1;
}
