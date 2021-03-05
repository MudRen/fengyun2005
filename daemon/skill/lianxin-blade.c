//TIE@FY3
//lianxin-blade.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","莲心影现刀法");
	set("skill_class","shaolin");
	set("type","blade");
	set("effective_level",150);
	set("usage/blade",1);
	set("usage/parry",1);
	
	set("practice_limit",100);
	set("damage_level",200);
	set("difficulty",200);
		
	set("parry_msg", ({
        	"$n使出一招「舍身不难难舍念」，手中的$v快似闪电般格开了$N的$w。\n",
		"$n手中$v泛出道道弧光，冷气森森，一招「炯炯孤光冷逾冰」，从侧面划向$N之必救。\n",
		"$n身形转动，手中的$v光华闪闪，一招「素心依旧伴青灯」，反削$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n使出一招「泥牛入海随波散」，手中的$v浑然波出，$N的攻势随波而散。\n",
		"$n站定身形，手中$v刀光暴长，一招「在冶良金色愈光」，封住$N的招式。\n",
		"$n手中的$v拆招化式，游刃有余。\n",
	}) );
	
	action = ({
		([	"action":		
		"$N使一招「拖泥带水伤人易」，手中$w连连向下斜劈，飞沙走石，迷住$n的二目，趁势一刀削向$n的$l！",
			"dodge":		180,
			"parry":		170,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N身形急转，刀随人动，$w随著一招「玉洁金坚律己难」，刀风滚滚向$n的$l砍去！",
	                "dodge":                160,
	                "parry":                260,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N身行跃起，抡动手中$w，一招「曾经人海竟飞腾」，凌空劈向$n的$l",
	                "dodge":                170,
	                "parry":                250,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N手中$w舞动，刀光缭绕，一招「笔绕春虹梦有形」，从四面八方齐向往$n杀去！",
	                "dodge":                170,
	                "parry":                240,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N手中$w化作片片刀光，一招「心地长飘六月雪」，飘飘荡荡向$n落去",
	                "dodge":                170,
	                "parry":                220,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N单掌拍出，掌风烈烈，热浪袭人，手中$w泛出五彩光华，一招「火内方开五色莲」直劈$n$l",
	                "dodge":                170,
	                "parry":                210,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N使一招「疑能生苦苦生疑」，手中$w盘转而进，刀光霍霍斩向$n的$l",
	                "dodge":                270,
			"damage_type":	"割伤"
		]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 250 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "axe")
    	if(victim->query_skill_mapped("axe") == "xuanyuan-axe"  )
    	if(me->query_skill("lianxin-blade",1)+50 > victim->query_skill("xuanyuan-axe",1)) {
    	switch(random(3)) {
            	case 0:
                    message_vision(HIR "\n$N料敌机先，渐渐占了上风！" NOR,me,victim);
                    break;
            	case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            	case 2:
                    message_vision(HIR "\n$N刀走偏锋，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    		return random(me->query_skill("blade")) * 2;
    	}
    	return 0;
}

int help(object me)
{
	write(@HELP  
『一片莲心』（yipianlianxin）和队伍中的同伴一起攻击对手
使用方法：perform yipianlianxin 敌人名 with 同伴名
一共5招。攻击、伤害随lianxin-blade加成
HELP
    );
    return 1;
}