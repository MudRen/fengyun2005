// thunderwhip.c

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","天雷破");
	set("practice_limit",100);
	set("type","whip");
	set("usage/whip",1);
	set("usage/parry",1);
	set("effective_level",160);
	set("difficulty",200);
	set("skill_class","yinshi");
	
	set("parry_msg", ({
        	"$n一鞭转空，身形籍式升空三尺，反手连戳三鞭『太古神龙三掉尾』，卷起一道鞭焰，护住全身。\n",
		"$n一招『横扣天机』，贯运真力，直截$N手中的$w\n",
		"$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
		"$n急踏步移形换位，让开这一招。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n一鞭转空，身形籍式升空三尺，反手连戳三鞭『太古神龙三掉尾』，卷起一道鞭焰，护住全身。\n",
	        "$n右臂向后一摆，手中的$v向前卷出，鞭影象雪花般罩住了$N。\n",
	        "$n急踏步移形换位，让开这一招。\n",
	}) );
	
	action = ({
		([
			"action":		
			"$N惊叱一声，双手并举，寒光陡飞，霎时人鞭合一，凌空直向$n飞去",
			"dodge":		100,
			"damage":		60,
			"damage_type":	"抽伤"
		]),
		([
			"action":		
			"$N手中鞭影乍迸，卷起万重电光，『太古开天』轰然横扫",
			"dodge":		500,
			"damage":		40,
			"damage_type":	"抽伤"
		]),
		([
			"action":		
			"$N鞭式一变，杀机四布，展开了天雷破有去无回的杀招『太古伏羲说八卦』",
			"dodge":		400,
			"damage":		150,
			"damage_type":	"抽伤"
		]),
		([
			"action":	        
			"$N跃起三丈，身在半空，招式陡变，『太古神龙』如惊涛骇浪，卷转电擎而落",
			"dodge":		400,
			"damage":		60,
			"damage_type":	"抽伤"
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
    	if(victim->query_skill_mapped("hammer") == "pangu-hammer"
     		||victim->query_skill_mapped("hammer") == "assassin-hammer"
     		||victim->query_skill_mapped("hammer") == "liuxing-hammer")
    
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

int damage_level(object me)
{
	int add, n;
	if (me) {
		//	thunder_add 1-10 -> 2%-20% add
		add = F_ABILITY->check_ability(me,"thunderwhip_add",2) *20;
		return add;
	}
	return 0;
}

int help(object me)
{
	write(@HELP   
当有效天雷破等级高于盘古九式、流星锤法、搏浪锤法等时有克制效应。

『天雷一击』(Tianleiyiji)
对敌手造成气血伤害，自我忙乱两轮
L50：单击
L200：两击
额外攻击力=天雷破等级
额外伤害力=天雷破等级

『云龙』（yunlongjiuxian）
需要110级的天雷鞭法，将通天降的威力汇入鞭法中攻击敌人的精力，
其命中率和杀伤力与有效降头术的等级相关
该特技属魔法攻击，分三个进界
『云龙三现』另需110级通天降，自我忙乱3轮
『云龙六现』另需160级通天降，自我忙乱4轮
『云龙九现』另需200级通天降和200级乾坤无形，自我忙乱4轮

HELP
    );
    return 1;
}
