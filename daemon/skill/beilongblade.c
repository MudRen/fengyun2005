#include <ansi.h>
#include <weapon.h>

inherit SKILL;
void setup(){
	set("name","悲龙斩");
	set("type","unarmed");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
        "$n回身反破，金刃切风，逼得$N退向一旁。\n",
	}) );
	set("unarmed_parry_msg", ({
        "$n回身反破，金刃切风，逼得$N退向一旁。\n",
	}) );	
	action = ({
		([	"action":		"$N沉气提心，力贯双臂，一式「空山鬼雨」卷起狂岚袭向$n",
			"damage":		100,
	        "force":        100,
			"dodge":		-30,
			"parry":		-120,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N双手紧握$w，一声断喝中劈向$n，声势相助，气撼三天，好一招「人间末路」",
			"damage":		50,
	        "force":        35,
			"dodge":		25,
			"parry":		70,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N吼声里马步旋动，使一招「壮怀空许」横斩$n腰部",
			"damage":		220,
	        "force":        190,
			"dodge":		-175,
			"parry":		30,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N双手青筋浮现，左腿蹬起处飞劈$n，这招「浮欢若梦」显然已尽了全力",
			"damage":		450,
	        "force":        330,
			"dodge":		-130,
			"parry":		-255,
			"damage_type":	"割伤"
		]),
	});
}


int valid_learn(object me)
{
    return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object wep;
	int i=0,t;
	wep = me->query_temp("weapon");
	if (!(wep->query("flag")&TWO_HANDED))
		return -damage_bonus;
	// 只有双手长刀才能发挥出威力。
	return wep->query_weight()/400;
	// 40000 / 400 = 100.
}

int help(object me)
{
	write(@HELP   
北龙斩的两个特技有很大的随机性。
	
L150『分天斩』（fentianzhan）
单击，自我忙乱2轮
额外攻击力=random(random(悲龙斩等级*6))+1
额外伤害力=random(random(random(悲龙斩等级*12)))+1

L200『煮鹤焚琴』（fenqin）
单击，自我忙乱2轮
额外攻击力=random(random(random(random(悲龙斩等级*40))))+1
额外伤害力=random(random(random(random(random(悲龙斩等级*80)))))+1
HELP
    );
    return 1;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
