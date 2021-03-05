// nine-moon-claw.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","九阴白骨爪");
	set("practice_limit",100);
//	set("damage_level",200);
	set("usage/parry",1);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","shenshui");
	set("parry_msg", ({
		"$n伸出两指，一招「金石为开」，将$N的$w牢牢的夹在指中！\n",
		"$n后退一步，双手向下连抓，$N手中的$w似乎突然沉重起来，几乎连拿都拿不稳。\n",
		"$n向地上凌空一抓，一招「阴河倒卷」，整个人象一片枯叶一样在$N$w的气流中飘荡。\n",
		"$n双爪劲力一吐一吸，一招「阴毒敷骨」，竟将$N手中的$w吸于双爪之上！\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n双臂暴长，一招「阴爪搜魂」，将$N双臂所有大穴全然罩于爪下！\n",
		"$n左臂一转，从$N意想不到的角度猛然回击，一招「阴龙乍现」将$N逼退。\n",
		"$n中指微弹，一招「无孔不入」，一股阴森森的指风直刺$N的面门。\n",
		"$n双手交错，一招「天地皆阴」将$N圈于爪风之下。\n",	
	}) );
	action = ({
        ([      "action":               
"$N使出一招「穿心百抓」，右手抓向$n的$l",
                "dodge":                330,
                "parry":                290,
                "force":                400,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出一招「残天九连抓」，左手化指为爪，连续击向$n的$l",
                "dodge":                200,
                "parry":                320,
                "force":                370,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出九阴白骨爪的「爪底亡魂」，如鬼魅般欺至$n身前，一爪勾向$n的$l",
                "dodge":                200,
                "parry":                320,
                "force":                350,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N双臂一错，使出「戕帝狂爪」，对准$n的$l连续抓出",
                "dodge":                250,
                "parry":                300,
                "force":                390,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N左手指甲暴突，奋力推出，一招「九阴腐万象」，抓向$n$l",
                "dodge":                250,
                "parry":                350,
                "force":                470,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出「九阴穿两仪」，双手同时向$n的$l出爪攻击",
                "dodge":                280,
                "parry":                380,
                "force":                380,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「邪巫神天爪」双臂并力递出",
                "parry":                400,
                "dodge":                280,
                "force":                320,
                "damage_type":  "抓伤"
        ]),
	});
}

int valid_learn(object me)
{
    if( (string)me->query("gender") != "女性" ) {
        return notify_fail("九阴白骨爪是只有女子才能练的武功。\n");
	}
	if( me->query_skill("nine-moon-claw",1) < 180) {
		if( me->query_skill("nine-moon-claw",1) >= me->query_skill("nine-moon-force",1) ) {
			return notify_fail("你的九阴心经火候不够。\n");
		}
	}
    return ::valid_learn(me);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    
	int damage;

	if( damage_bonus < 110 ) {
		return 0;
	}
	if( random(damage_bonus)/4 > victim->query_str() ) {
		damage = (damage_bonus - 100) / 2;
		damage = COMBAT_D->magic_modifier(me, victim, "kee", damage);     
		victim->receive_wound("kee", damage, me);
		switch( random(3) ) {
			case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
			case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
			case 2: return "只听见$n的$l「喀」地一声 ...\n";
		}
	}
}

/* 
void skill_improved(object me)
{
    	if( (int)me->query_skill("nine-moon-claw", 1)  % 10 == 0 ) {
        	tell_object(me, RED "\n你突然觉得一股阴气冲上心头，只觉得想杀人....\n\n"NOR);
        	me->add("bellicosity", 500);
    	} else {
            	me->add("bellicosity", 100);
	}
}*/

mixed parry_ob(object victim,object me)
{
	int extra ;
	extra = me->query_temp("nine-moon-force_poison");
	extra = extra/2;
	if( extra )	{
		extra = COMBAT_D->magic_modifier(me, victim, "kee", extra);
		victim->receive_damage("kee", extra, me);
		victim->receive_wound("kee", extra, me);
		if( !victim->query_temp("weapon") ) {	
			return MAG"$N只觉触手处紫气一闪，缕缕阴寒锥心而至！\n"NOR;
		} else {
			return MAG"$N只觉一层淡淡的紫气从兵刃上蔓延而来，刺骨的寒气几乎令手腕转动不灵。\n"NOR;		
		}
	}
}

/*
int effective_level(object me)
{
	
	int skill,n;
	
	if (me) {
		skill = me->query("pfm/baiquan-9moon");
		if (skill )
			return 210;		
		else 
			return 200;
	}
	return 210;
}*/


int help(object me)
{
	write(@HELP   
女子专用，180级以下需有相同等级的九阴心经作基础。

『唯我独尊』〔weiwoduzun〕
需100级九阴白骨爪，对敌人有极大的杀伤力，自我忙乱2轮。
每30分钟使用一次。直接伤害气血＝3000
卷轴Ｉ：直接伤害气血4500
卷轴ＩＩ：直接伤害气血6000

『破颅』〔polu〕    
需要150级九阴白骨爪，150级九阴身法，九阴心经和姹女神功，
『破颅』有两击，第一击随时可以使出，第二击需要捕捉战机，
在敌手受九阴毒雾或霜冷残霞的毒雾影响时才能使出，威力取决于
九阴白骨抓、九阴心经、九阴身法、姹女神功和自己的经验等级，
第二击类似于法术攻击，不受对方护甲影响。自我忙乱2轮
HELP
    );
    return 1;
}
