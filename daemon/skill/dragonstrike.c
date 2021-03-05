inherit SKILL;
#include <ansi.h>


void setup() {
	set("name","降龙十八掌");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",160);
	set("practice_limit",100);
	set("damage_level",250);
	set("difficulty",300);
	set("skill_class","beggar");

	set("parry_msg", ({
	        "$n双掌微分，使出一招「神龙摆尾」，「啪」的一声将$N的$w划开。\n",
	        "$n略一转身，一招「见龙在田」拍向$N拿着$w的手。\n",
	        "$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n步走阴阳，一招「震惊百里」虚空拍出三掌，逼得$N撤招自保。\n",
	        "$n施展出「神龙摆尾」，轻描淡写的化解了$N的攻势。\n",
	}) );	
	action = ({
([      "action": "$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l",
        "dodge": 30,
        "parry": 10,
        "damage": 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
        "dodge": 15,
        "parry": 20,
        "damage": 800,
        "damage_type": "瘀伤"
]),
([	"action": "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l",
	"dodge": 10,
	"parry": 10,
	"damage": 720,
	"damage_type": "瘀伤"
]),
([	"action": "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l",
        "dodge": 15,
	"parry": 10,
	"damage": 900,
	"damage_type": "瘀伤"
]),
([	"action": "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l",
	"dodge": 10,
	"parry": 10,
	"damage": 500,
	"damage_type": "瘀伤"
]),
([	"action": "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l",
	"dodge": 10,
	"parry": 20,
	"damage": 500,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出",
	"dodge": 0,
	"parry": 10,
	"damage": 500,
	"damage_type": "瘀伤"
]),
([	"action": "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n",
	"dodge": 25,
	"parry": 10,
	"damage": 700,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「或跃在渊」，向$n的$l连拍数掌",
	"dodge": 20,
	"parry": 20,
	"damage": 300,
	"damage_type": "瘀伤"
]),
([	"action": "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l",
	"dodge": 10,
	"parry": 20,
	"damage": 460,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",
	"dodge": 20,
	"parry": 30,
	"damage": 900,
	"damage_type": "瘀伤"
]),
([	"action": "$N双掌立起，使出「时乘六龙」向$n连砍六下",
	"dodge": 20,
	"parry": 20,
	"damage": 870,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",
	"dodge": 15,
	"parry": 20,
	"damage": 220,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l",
	"dodge": 25,
	"parry": 10,
	"damage": 350,
	"damage_type": "瘀伤"
]),
([	"action": "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
	"dodge": 20,
	"parry": 40,
	"damage": 630,
	"damage_type": "瘀伤"
]),
([	"action": "$N门户大开，一招「履霜冰至」向$n的$l劈去",
	"dodge": 25,
	"parry": 1,
	"damage": 420,
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l",
	"dodge": 15,
	"parry": 40,
	"damage": 600,
	"damage_type": "瘀伤"
]),
([	"action": "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",
	"dodge": 10,
	"parry": 40,
	"damage": 620,
	"damage_type": "瘀伤"
]),
});

}

int valid_learn(object me){
	
	if( me->query_skill("begging",1) <= (int)me->query_skill("dragonstrike",1)
		&& me->query_skill("begging",1) < 150) {
        	return notify_fail("叫花子看家的乞讨之术没学好，怎么就急着学降龙十八掌了呢。\n");
	}
	return ::valid_learn(me);
}


//	降龙十八掌专破内家硬气功。
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int badint=0;

    if( damage_bonus < 300 ) return 0; 
        badint = victim->query_skill("iron-cloth");
	if (stringp(victim->query_skill_mapped("iron-cloth"))) {
		if(badint) {
			badint = COMBAT_D->magic_modifier(me, victim, "kee", badint);
			victim->receive_wound("kee",badint,me);
			switch(random(3)) {
        			case 0: return CYN"$N隔山打牛，“喀啦”一声轻响，竟似是骨碎的声音！\n"NOR;
               			case 1: return CYN"$N劲力暗吐，$n的$l发出“喀”地一声爆响！\n"NOR;
               			case 2: return CYN"只听见$n的$l“喀”地一声 ．．．\n"NOR;
           			}
		}
	}
}

int damage_level(object me)
{
	int skill, n;
	if (me) {
		skill=me->query_skill("dragonstrike",1);
				
		if (skill<=140) return 0;
		if (skill>=190) return 250;
		n= (skill-140)*5;
		return n;
	}
	return 250;
}
		
int help(object me)
{
	write(@HELP   
降龙十八掌需要相同等级的乞讨之术为基础。１５０级以上则无此限制。降龙
十八掌１４０级以上，每提升一级伤害等级提高５，直至２５０（１９０级）。

L20『降龙无悔Ｉ』（xianglongwuhui）
L90『时乘六龙Ｉ』（shichengliulong）
L100『震惊百里Ｉ』（zhenjingbaili）	
	『震惊百里ＩＩ』	需卷轴	
	『震惊百里ＩＩＩ』	需卷轴
	『震惊百里ＩＶ』	需卷轴
L150『时乘六龙ＩＩ』
L160『降龙无悔ＩＩ』可攻出相同威力的第二招

『降龙无悔』每２０秒会出现令敌人忙乱的特殊效果，每３０－４０秒攻击力
和杀伤力达到一个最大值。降龙十八掌等级越高，聚力时间越短，１２０级以
上，每增加１０级，聚力时间减少一秒，直至２２０级。
如果连续使用时间间隔过短，则不会出现以上的特效。自我忙乱２回合
最大额外攻击力＝降龙十八掌等级＊２
最大额外伤害力＝降龙十八掌等级＊４

『时乘六龙』的作用为降低敌人的防御（身法迟钝）
如果降龙十八掌级别为１５０以上，在成功后的四个回合内，
敌人可能有六个不同的反应，如果你能抓住战机使用对应的特技，
则会出现以下的功效：
敌人俯身：（１）绊字诀成功率加倍，不计忙乱时限
敌人空门：（２）戳字诀攻击力和伤害力加倍
敌人反击：（３）引字诀攻击力加倍
敌人招架：（４）挑字诀成功率加倍，不计挑字诀时限，若敌人没有武器则转为狙击
敌人镇定：（５）无懈可击，没有效果
敌人近身：（６）震惊百里无需聚气，以迅疾的速度击出
『时乘六龙』成功无自我忙乱，失败自我忙乱１回合

『震惊百里』伤害力很大，但普通使用时需要聚气数招，如果受到敌人
攻击受伤则可能真气岔乱，无法使出。
额外攻击力＝降龙十八掌等级，对手无法闪避
额外伤害力＝＋５００／９００／１５００／１８００
此招伤害力永远取最大可能值
HELP
    );
    return 1;
}

