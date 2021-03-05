// modified by mimicat@fy4
// qidaoforce.c

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","棋道");
	set("type","force");
	set("usage/force",1);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","legend");
	set("effective_level",150);
	set("damage_level",200);
	set("no_refund",({"diesword","shortsong-blade"}));
	set("difficulty",400);
	set("parry_msg",  ({
		"$n右臂回转，内力排山倒海地将$N的招式震开。\n",
		"$n一声大喝，周身真气震荡，挡住了$N的攻势。\n",
		"$n脚步不丁不八，右手高左手低，$N的攻势如泥牛入江消失无踪。\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n右臂回转，内力排山倒海地将$N的招式震开。\n",
		"$n一声大喝，周身真气震荡，挡住了$N的攻势。\n",
		"$n脚步不丁不八，右手高左手低，$N的攻势如泥牛入江消失无踪。\n",
	}) );
	action = ({
        ([      "action":"$N使出一招「镇神头」，左手聚出一团真气，从上而下，击向$n的$l",
                "parry":		400,
                "dodge":		500,
                "damage":		200,
                "damage_type":  "内伤"
        ]),
        ([      "action":"$N使出一招「大斜」，右手聚出一团真气，斜斜击向$n的$l",
                "parry":		100,
                "dodge":		600,
                "damage":		250,
                "damage_type":  "内伤"
        ]),
	([ 	"action":"$N使出一招「双飞燕」，双手聚出一团真气，左右同时击向$n的$l",
                "parry":		200,
                "dodge":		300,
                "damage":		300,
                "damage_type":  "内伤"
        ]),
	([	"action":"$N使出一招「倒垂莲」，全身腾空而起，运起全身的真气击向$n的$l",
                "parry":		400,
                "dodge":		400,
                "damage":		400,
                "damage_type":  "内伤"
        ]),
	});
}

int valid_enable(string usage) 
{ 
	return usage=="unarmed"||usage=="force"|| usage=="parry"; 
}

mixed hit_ob(object me,object victim)
{
	int extra/*, dream*/;
	string skill/*,message=""*/;
	object weapon;
		
	extra = me->query_temp("pfm/qidaoforce_juqi");
	if ( extra <= 0 ) 	return;
	
	if (me->query_temp("pfm/legend_berserk"))	extra = extra*2;
			
	skill = objectp(weapon = me->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
    if (skill == "unarmed")	extra = extra/2;
    
    skill = me->query_skill_mapped(skill);
    if (!skill || SKILL_D(skill)->skill_class()!="legend") {
		return;
    }
	
//	extra = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	victim->receive_damage("kee",extra,me);
	
	if (me->query("family/master_id")=="master xuerui")
			message_vision(WHT"\n$N身侧的玉色光芒忽如蝶翼般片片飞向$n，$n"+WHT"只觉经脉中一阵灼痛。\n"NOR,me, victim);
		else 
			message_vision(HIC"\n$N将内力凝为一线，攻入$n"+HIC"的体内。\n"NOR, me, victim);
	return;
}

int help(object me)
{
	write(@HELP
『聚血』(juxue)
此招不需使用exert juxue，而是用juxue命令直接使用，不受自身
忙乱的限制，可瞬间恢复自身或他人的气血值。每６０分钟一次。
聚血Ｉ：需６０级棋道心法，回复2000点气血
聚血ＩＩ：卷轴，250级息若纳气，150棋道，恢复6000点气血
聚血ＩＩＩ：卷轴，290级息若纳气，150棋道，恢复12000点气血

『聚气』『蝶梦』(juqi)
男弟子为聚气、女弟子为蝶梦，描述不同，功效相同。
在铁雪武功上增加额外伤害，该伤害不受对方护甲、铁布衫的阻挡。
『聚气I』需100级棋道心法，＋６０
『聚气II』需150级棋道心法和200级息若纳气，＋７０
『聚气III』另需250级息若纳气，＋８０

『聚寒』(juhan)
为铁雪的疗伤心法，在水源处运内力聚成寒冰，而后以此治疗外伤，
每15分钟聚寒一次，得到的寒冰可使用两次。『聚寒I』需150级棋道，
每次治疗1000点，『聚寒II』需150棋道、220级息若纳气，治疗2000
点；『聚寒III』另需270级息若纳气，治疗3000点，可使用三次。

『聚心』(juxin)
需150棋道、150级息若纳气，每3分钟使用一次，
铁雪战斗中的自疗，恢复25%的气血和50%的内力，恢复气血最大值
L200级息若纳气，每2分30秒钟使用一次

『聚神』(jushen)
需150棋道、150级六灵暗识，每5分钟使用一次，每次持续60秒，
攻击力提高150。学习ABILILTY可缩短再次使用时间。
L250级六灵暗识，攻击力提高200

『聚威』(juwei)
需150棋道、230级六灵暗识
攻击所有敌人，被击中者五回合内无法使用普通攻击。
此招产生额外仇恨。自我忙乱１回合，每3分钟使用一次。
此招无法招架或闪避。
L270级六灵暗识，每2分30秒使用一次
L300级六灵暗识，每2分钟使用一次

『聚力』(juli)
需150棋道、300级息若纳气，每5分钟使用一次，每次持续60秒，
期间武功每招伤害力都为最大值，学习ABILILTY可缩短再次使用
时间
HELP
    );
    return 1;
}