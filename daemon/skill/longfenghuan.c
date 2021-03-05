// longfenghuan.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","龙凤双环");
	set("type","hammer");
	set("difficulty",200);
	set("usage/hammer",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("damage_level",200);
	set("skill_class","assassin");
	
	set("unarmed_parry_msg", ({
        	"$n晃动$v，口中大声酣呼，向$N迎头击下，$N不得不撤回攻势。\n",
        	"$n左臂微偏，一招 「龙潜于野」，将周身遮得风雨不透。\n",
        	"$n一招「群龙无首」，$v在身前随随便便画了个圆弧，竟是无懈可击。\n",	
	}) );
	
	action = ({
        ([      "action":               
"$N单脚金鸡独立，缓缓施展出龙凤双环的起手式「八面威风」",
                "force":                500,
                "dodge":                500,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w相碰，发出＂隆隆＂声，一招「先声夺人」攻向$n$l",
                "force":                600,
                "dodge":                600,
                "parry":                200,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w凌空一挥，使出龙凤双环中的「龙飞凤舞」击向$n$l",
                "force":                500,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「游龙在天」，$w夹杂着风声撞向$n$l",
                "force":                800,
                "dodge":                100,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "挫伤"
        ]),
	});
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	string type;
    	
    	if( random(damage_bonus) < 300 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	{
    		type = ob->query("skill_type");
    		if (type != "blade" && type != "dagger" && type!="sword")	return 0;
    		if (me->query_skill("hammer") >= victim->query_skill(type))
    		{
	    		switch(random(3)) {
		        	case 0:
		                	message_vision(HIR "\n$N力大招沉，占尽了上风！" NOR,me,victim);
		                	break;
		        	case 1:
		                	message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
		                	break;
		        	case 2:
		                	message_vision(HIR "\n因兵刃被克，$n逐渐施展不开了！" NOR,me,victim);
		                	break;
	                }
    			return (damage_bonus/2 + random(damage_bonus)/2);
    		}
    	}
    	return 0;

}

