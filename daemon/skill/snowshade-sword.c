// modified by mimicat@fy4

#include <ansi.h>	

inherit SKILL;
void setup(){
	set("name","雪影剑法");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("difficulty",150);
	set("skill_class","taoist");
	set("parry_msg", ({
	        "$n剑尖向上，以『朝天一柱香』格开了$N的$w。\n",
	         "$n滑出一步，$v『横云断峰』斜扫敌腰。\n",
	        "$n不退反进，竟走险招，和身下扑，$v直刺，点向$N右脚。\n",
	        "$n右肩侧过，『彩虹经天』，$v上撩，化解了$N的攻势。\n",
	        "$n镇定自若，『流星堕地』，直立向下挡架。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n滑出一步，$v『横云断峰』斜扫敌腰。\n",
	        "$n不退反进，竟走险招，和身下扑，$v直刺，点向$N右脚。\n",
	        "$n右肩侧过，『彩虹经天』，$v上撩，化解了$N的攻势。\n",
	        "$n镇定自若，『流星堕地』，直立向下挡架。\n",
	}) );
	action = ({
		([	"action":		"$N使一招『回光幻电』，手中$w幻作一条疾光刺向$n的$l",
			"dodge":		20,
			"damage":		130,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N使出雪影剑法中的『风霜碎影』，$w连挥，剑光霍霍斩向$n的$l",
			"dodge":		20,
			"damage":		130,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N一招『残阳照雪』，纵身飘开数尺，手中$w斩向$n的$l",
			"dodge":		30,
			"damage":		120,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w中宫直进，一式『冰谷初虹』对准$n的$l刺出一剑",
			"dodge":		40,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N纵身一跃，手中$w一招『长空雷隐』对准$n的$l斜斜刺出一剑",
			"dodge":		40,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N的$w凭空一指，一招『断石狼烟』刺向$n的$l",
			"dodge":		20,
			"damage":		140,
			"damage_type":	"刺伤"
		]),
	});
}

mixed hit_ob(object me, object victim)
{
	object weapon;
	string result;
	int extra;
	
	weapon=me->query_temp("weapon");
	extra=weapon->query("exorcising");
	
	//	allow 丁乘风 to do some demo without troubles.
	if (!userp(me) && me->query("id")=="master ding") {
		extra = 1500;
	}
	
	if(!extra )	return ;
		
	result = HIR"符纸上的血色似乎又加深了一分。。。\n";
	if(victim->is_ghost() || victim->is_zombie())
		extra = extra *2;
	extra = COMBAT_D->magic_modifier(me, victim, "sen", extra);
		
	victim->receive_wound("sen",extra,me);
		
//	message_vision("damage is "+(extra+extra/2)+".\n",me);
	result+=HIY"$n浑身如遭雷磔，神为之夺。\n"NOR;
	return result;
}

int help(object me)
{
	write(@HELP   
『白雪皑皑』（baixueaiai）
剑法攻击，自我忙乱２回合
额外攻击力＝雪影剑法＋有效符术／４
额外伤害力＝雪影剑法＋有效符术＊３／８
HELP
    );
    return 1;
}


