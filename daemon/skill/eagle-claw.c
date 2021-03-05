// eagle-claw.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","鹰爪功");
	set("type","unarmed");
	set("effective_level",210);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("damage_level",250);
	set("difficulty",300);
	set("skill_class","fugui");
	set("parry_msg", ({
	        "$n一招「金雕擒兔」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
	        "$n右拳虚晃，左拳一招「迎风振翅」，逼得$N后退三步。\n",
	        "$n以攻为守，一招「拔翅横飞」，猛击$N握$w的手腕。\n",
	        "$n一招「雄鹰现爪」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n一招「金雕擒兔」，逼得$N中途撤招。\n",
	        "$n脚走阴阳，一招「拔翅横飞」，攻$N之必救。\n",
	        "$n左拳击下，右拳自保，一招「迎风振翅」，将$N封于尺外。\n",
	        "$n双拳齐出，使出一招「雄鹰现爪」，$N的攻势如泥牛入海，消失得无影无踪。\n",

	}) );
	action = ({
		([  "action" : "$N拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l",
		    "force" : 100,
		    "dodge" : 250,
		    "parry" : 250,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪拢向$n的$l",
		    "force" : 120,
		    "dodge" : 200,
		    "parry" : 400,
		    "damage": 5,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N一式「拔翅横飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
		    "force" : 150,
		    "dodge" : 200,
		    "parry" : 400,
		    "damage": 10,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门",
		    "force" : 190,
		    "dodge" : 150,
		    "parry" : 450,
		    "damage": 10,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口",
		    "force" : 150,
		    "dodge" : 500,
		    "parry" : 400,
		    "damage": 15,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N伏地滑行，一式「拨云瞻日」，上手袭向膻中大穴，下手反抓$n的裆部",
		    "force" : 110,
		    "dodge" : 265,
		    "parry" : 365,
		    "damage": 20,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n",
		    "force" : 180,
		    "dodge" : 375,
		    "parry" : 575,
		    "damage": 25,
		    "damage_type" : "抓伤"
		]),
		([  "action" : "$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
		    "force" : 170,
	 	    "dodge" : 800,
	 	    "parry" : 400,
		    "damage": 20,
		    "damage_type" : "抓伤"
		])
	});
}
/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
	mapping buff;
	int mod;
	
	if (me->query_skill("eagle-claw",1) < 100 || me->query("class")!="fugui")	
		return;
	
	if (victim->query("race")!="人类")	return;
		
	mod = COMBAT_D->can_busy(me, victim, "eagle-claw");	
	if (!mod) mod = 1000;
	
	if (!ANNIE_D->check_buff(victim,"lockup"))
	if (COMBAT_D->do_busy_attack(me, victim, "eagle-claw/suomai","unarmed", 200,mod))
	{
		msg = BLU"\n$N忽然出手，轻飘飘的点下去，从$n左手无名指的第二个骨节一路跳跃过去，
跳过左肘，肩井，脊椎。。。。\n"NOR;
		message_vision(msg + "\n", me, victim);
		tell_object(victim, WHT"（你中了鹰爪功的锁脉式!）\n"NOR);
		buff =
		([
			"caster":me,
			"who":	 victim,
			"type": "lockup",
			"att":  "curse",
			"name": "鹰爪功·锁脉",
			"time":  20 + random(10),
			"buff1": "till_death/lockup",
			"buff1_c": 1,
			"buff_msg": "",
			"warn_msg":"",
			"disa_msg": WHT"$N身形晃动，终于从指风中脱离出来。\n"NOR,
			"disa_type": 1, 
		]);
		ANNIE_D->buffup(buff);
		
	} 
}

void skill_improved(object me)
{
        int s;
        s = me->query_skill("eagle-claw", 1);
 	if (s == 100)
 		tell_object(me, WHT"由於你勤练鹰爪功，你悟出了『锁脉』，将自动在战斗中应用。\n" NOR);
}
*/


int help(object me)
{
	write(@HELP   	
L50『擒龙』（qinlong）
在三回合内降低敌手的招架闪躲攻击能力，自我忙乱1轮。
此式无论成败连续使用成功率都会下降。

L120『见龙卸甲』（xiejia）
成功后可降低对方硬气功和护甲等级七成，
（对BOSS类敌人无效）
成功每3分钟可再使用，效用维持60秒。
失败每1分钟可再使用。
成败与否自我忙乱1轮。

L150『寸进』（cunjin）
若得手后可禁止敌手在15回合内使用特技，
（对BOSS类敌人持续时间为5回合）
每10分钟使用一次，自我忙乱1轮。

HELP
    );
    return 1;
}
