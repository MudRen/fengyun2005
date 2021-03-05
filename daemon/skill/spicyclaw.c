inherit SKILL;

#include <ansi.h>

void setup() {
	set("name","迦楼罗油流麻香式");
	set("type","unarmed");
	set("effective_level",200);
	set("difficulty",300);
	set("skill_class","demon");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("parry_msg",			({
		"$n急划$N的脉门，逼得$N中途撤回手中的$w。\n",
	})	);
	set("unarmed_parry_msg",		({
        "$n急划$N的脉门，逼得$N中途撤招。\n",
	})	);
	action = ({
	([	"action":		"$N左掌微分，右手一长使出一招「铁铲煎蛋」铲向$n的$l",
		"dodge":		30,
		"parry":		70,
		"damage":		160,
		"force":		160,
		"damage_type":	"烫伤"
	]),
	([	"action":		"$N倏地一个转身，双手一翻「撺热锅」直掼$n$l",
		"dodge":		10,
		"parry":		60,
		"force":		140,
		"damage":		140,
		"damage_type":	"烫伤"
	]),
	([	"action":		"$N身子微斜，随即跨出一步，左手忽掌忽爪使出「撮炉灰」，拍向$n的$l",
		"dodge":		30,
		"parry":		40,
		"force":		120,
		"damage":		120,
		"damage_type":	"烫伤"
	]),
	([	"action":		"$N使出「青蛇十段锦」，双手滑溜异常对准$n的$l抓去",
		"dodge":		10,
		"parry":		60,
		"force":		140,
		"damage":		140,
		"damage_type":	"烫伤"
	]),
	([	"action":		"$N左手虚晃，右掌飘飘，一招「梁上君子下油瓶」击向$n$l",
		"dodge":		20,
		"parry":		50,
		"force":		150,
		"damage":		150,
		"damage_type":	"烫伤"
	]),
	([	"action":		"$N右手在$n$l划过，随後一招「大碗盛饭」左爪又向同一方位抓到",
		"dodge":		90,
		"parry":		90,
		"force":		100,
		"damage":		100,
		"damage_type":	"烫伤"
	]),
	([	"action":		"$N使出「油流麻香」，凌空跃起，冷不防在落地前对准$n$l飞出一掌",
		"dodge":		500,
		"parry":		500,
		"force":		400,
		"damage":		400,
		"damage_type":	"烧伤"
	]),
});

}

int valid_learn(object me)
{	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
			return notify_fail("练迦楼罗油流麻香式必须空手。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("迦楼罗油流麻香式只能学的。\n");
}

mixed parry_ob(object victim,object me)
{
	object ob;
	if (!victim->query_temp("weapon"))
		return 0;
	ob=victim->query_temp("weapon");
	if (ob->query("skill_type") == "throwing" || ob->query("skill_type") == "unarmed" )
		return 0;
	
	ob->add("weapon_prop/damage",-1);
	if(ob->query("weapon_prop/damage") < 1 ) 
		ob->set("weapon_prop/damage",1);
	else
		victim->add_temp("apply/damage",-1);
	ob->set("item_damaged", 1);
	ob->save();
	return RED"$n"RED"掌缘炽烈如焚，"+ob->name()+RED"竟尔有些熔化．．．\n"NOR;;
}

mapping query_action(object me, object weapon) {
	mapping act=([]);
	int skill,i;
	string *color= ({
		HIM,HIW,HIB,HIY,HIC,
	});
	if(sizeof(action) > 0)
	{
		if (me->query_temp("annie/spicyclaw_perform"))
		{
			i=random(sizeof(action));
			act["action"] = color[me->query_temp("annie/spicyclaw_perform")-1] + action[i]["action"] + NOR;
			act["dodge"] = action[i]["dodge"];
			act["force"] = action[i]["force"];
			act["parry"] = action[i]["parry"];
			act["damage"] = action[i]["damage"];
			act["damage_type"] = "烫伤";
			return act;
		}
		return action[random(sizeof(action))];
	}
}

int help(object me)
{
	write(@HELP   
该技能在招架成功时会令对方武器的伤害力降低1
	
『油流麻香式』
（extrahit1）（extrahit2）（extrahit3）（extrahit4）（extrahit5）
连续普通攻击，没有伤害、攻击等加成，有固定色彩
每两个不同extrahit间需有1秒间隔，
相同extrahit间需有15秒间隔

HELP
    );
    return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
