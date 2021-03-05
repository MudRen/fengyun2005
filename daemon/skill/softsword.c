// softword.c

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","清风细雨温柔剑");
	set("practice_limit",100);
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","swordsman");
	set("parry_msg", ({
        "$n左掌攻敌，右剑防身，一招「情海无涯」，手中的$v轻轻磕开了$N的$w。\n",
		"$n剑出连环，绕住$N的$w，一招「朝朝暮暮」竟使$N难以把持手中的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n使出一招「金风玉露」，亦守亦攻，竟使$N不知是攻是守。\n",
		"$n一抖手中的$v，使出一招「两情相悦」，手中的$v配合左掌，将全身团团罩住。\n",
	}) );
	
	action = ({
		([	"name":			"春风乍起",
			"action":		
			"$N使一招「春风乍起」，手中$w如和煦春风洒向$n的$l，没有人知道风从哪里来，也就无法抵挡",
			"dodge":		200,
			"parry" :		200,
			"damage":		70,
			"force" : 		200,
			"damage_type":	"刺伤"
		]),
		([	"name":			"细雨绵绵",
			"action":		
			"$N手中的$w一招「细雨绵绵」如绵绵细雨，无孔不入的刺向$n的$l",
	                "dodge":                200,
	                "parry" :               200,
	                "damage":               50,
	                "force" :               100,
			"damage_type":	"刺伤"
		]),
		([	"name":			"飞星传恨",
			"action":		
			"$N舞动$w，一招「飞星传恨」，剑如飞星人如闪电，人剑合一，扑向$n的$l",
	                "dodge":                200,
	                "parry" :               300,
	                "damage":               150,
	                "force" :               250,
			"damage_type":	"刺伤"
		]),
		([	"name":			"柔情似水",
			"action":		
			"$N一抖手中$w，使出「柔情似水」，不由得暗自情伤，以情驭剑，向$n的$l刺出一剑",
	                "dodge":                100,
	                "parry" :               100,
	                "damage":               50,
	                "force" :               150,
			"damage_type":	"刺伤"
		]),
		([	"name":			"织云弄巧",
			"action":		
			"$N手中$w剑光四散，一招「织云弄巧」，剑光如云，笼罩了$n的$l，令人不知剑来自何方",
	                "dodge":                250,
	                "parry" :               250,
	                "damage":               90,
	                "force" :               220,
			"damage_type":	"刺伤"
		]),
		([	"name":			"佳期如梦",
			"action":		
			"$N想起年少玩伴尢在倚门相望，手中$w直指$n$l，一招「佳期如梦」，刺出了惊天动地的一剑",
			"dodge":		200,
			"damage":		150,
			"damage_type":	"刺伤"
		]),
	});
}


int practice_skill(object me)
{
	return notify_fail("清风细雨温柔剑法只能学的。\n");
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    
    if(me->query_temp("cut_mana"))
    {
    	victim->set("mana",0);
    	victim->set("force",0);
    	return HIB"等到剑光消失时，$n觉得整个人似乎都失去重心，彷佛将腾云驾雾般飞起。 \n"NOR;
    }

    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "doomsword")
    if(me->query_skill("sword") > victim->query_skill("sword")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n因剑法相克，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("sword")) * 2;
    }
    return 0;
}

