// dragonwhip.c
// ; annie 7.1

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","龙凤奇翔鞭法");
	set("type","whip");
	set("usage/whip",1);
	set("effective_level",210);
	set("practice_limit",100);
	set("practice_force",10);
	set("difficulty",200);
	set("skill_class","demon");
	action = ({
		([
			"action":		
			"$N用一招『烈焰凌云』，弓身围$n四周疾转。混乱中只见四面八方都是鞭影，似\n乎已将$n逼入死路",
			"dodge":		100,
			"damage":		60,
			"damage_type":	"刺伤"
		]),
		([
			"action":		
			"$N身形一转，一招『长日将尽』，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
			"dodge":		500,
			"damage":		40,
			"damage_type":	"瘀伤"
		]),
		([
			"action":		
			"$N运起轻功在$n周围疾转数圈，在$n眼花缭乱之际，一式『火舞神焰』落向$n",
			"dodge":		400,
			"damage":		150,
			"damage_type":	"刺伤"
		]),
		([
			"action":	        
			"$N使出『火龙吞野』，七道红芒一经泛出有若苍鹰猎兔以雷霆万钧之势，快愈飘风的刺向$n",
			"dodge":		400,
			"damage":		60,
			"damage_type":	"瘀伤"
		]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob,weapon;
    int cele;
    
    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "hammer")
    if(me->query_skill("whip")+100 > victim->query_skill("hammer")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n因鞭锤法相克，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("whip")) * 2;
    }
    return 0;
}

int help(object me)
{
	write(@HELP   
龙凤奇翔鞭法克制所有锤法

L50『炽翼千羽』（thousandfeather）
舞动长鞭化作千万条火羽灼烧所有对手，此招有一定几率使对手忙乱。
此招伤害力很不稳定，自我忙乱2-3轮。

		
L165『炎舞鞭烈』（firestorm）
以长鞭带动烈焰攻击四周对手，自我忙乱两轮
额外攻击力=龙凤奇翔鞭法等级
额外伤害力=龙凤奇翔鞭法*2
如果击中则产生十轮持续伤害，每两轮间隔2-3回合
伤害力约为random(龙凤奇翔鞭法等级*5)

HELP
    );
    return 1;
}
