// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void setup() {
	set("name","寒星雨觞");
	set("type","throwing");
	set("usage/throwing",1);
	set("usage/parry",1);
	set("skill_class","moon");

	set("effective_level",150);
	set("eff_parry_level",210);

	set("difficulty",250);
	set("practice_limit",50);

	set("parry_msg", ({
        "$n抽身急退，双手轻扬，$N阻住脚步，却是一式虚招。\n",
		"$n长袖乍展，只银华飞泻，潇潇如雨，将自身护于其中。\n",
		"$n飞舞轻旋，进退如据，令$N隔寸束手，变式落空。\n", 
	}) );
	set("unarmed_parry_msg", ({
        "$n抽身急退，双手轻扬，$N阻住脚步，却是一式虚招。\n",
		"$n长袖乍展，只银华飞泻，潇潇如雨，将自身护于其中。\n",
		"$n飞舞轻旋，进退如据，令$N隔寸束手，变式落空。\n", 
	}) );	

	action = ({
        ([      "action":               
"$N一拂长袖，只见星星点点$w纷飞而出，直似萤虫飞舞，有如天穹倾覆",
                "parry":                1,
				"damage":				4,
				"post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N大袖翻转，霎时间绛雪纷纷，$w飘如柳絮，弱似梨花，密密舞向众人身边",
                "parry":                2,
				"damage":				3,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N旋舞时幻起花雨满天，袖落处化作断霞千缕，无数$w漫天而出，不离不散的欺向敌人",
                "parry":                3,
				"damage":				2,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"只听$N一声清啸，双袖虚拍，袖中$w洒若冰魂急雨，微光粼动，竟似抵死缠绵",
                "parry":                4,
				"damage":				1,
                "post_action":  "throw_weapon",
                "damage_type":  "刺伤"
        ]),
	});
}

int damage_level(object me)
{
	return me->query_skill("starrain",1)+50;
}

int accuracy_level(object me)
{
	return me->query_skill("starrain",1)+50;
}

int valid_learn(object me)
{
	if(!::valid_learn(me))
		return 0;
	if( me->query_skill("starrain",1)> 100 && me->query_skill("throwing", 1) < me->query_skill("starrain",1) ) {
		return notify_fail("你对基本的暗器收发之术尚未掌其精髓，怎能学这大巧大工的寒星雨觞？\n");
	}
	if( me->query("class") != "moon" && me->query_skill("starrain",1) >= 100 ) {
		return notify_fail("你已无法更深入的领悟寒星雨觞。\n");	// 必须RESEARCH。
	}
	return 1;
}

int valid_research(object me)
{
	if( me->query_skill("throwing", 1) < me->query_skill("starrain",1) ) {
		return notify_fail("你对基本的暗器收发之术尚未掌其精髓，怎能学这大巧大工的寒星雨觞？\n");
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob,*enemy;
	int i;
	if (me->query("class") != "moon" && userp(me))
		return 0;
	if (me->query_temp("annie/perform_starrain") && userp(me))
		return 0;
	if (me->query("annie/no-multi-target"))
		return 0;
	enemy = me->query_enemy();
	if (sizeof(enemy) < 2)
		return 0;
	me->set_temp("annie/multi-target",victim);

    return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("starrain", 1);
		if( skill < 200 ) {
			return 250;
		} else {
			return 400;
		}
	}
	return 250;
}

int help(object me)
{
	write(@HELP   
寒星雨觞普通攻击时可以攻击所有对手，
100级以上，暗器之术的等级必须高于寒星雨觞。
寒星雨觞级别200以上，学习系数增加到400。

『无空漩流』（wukongxuanliu）
需50级寒星雨觞，在对手忙乱<3时使用，若成功敌人的忙乱定为三轮，（敌
人若忙乱大于三轮则不受影响），如失败敌人的忙乱减少一轮，自己也会受
到些许气血伤害，每12秒使用一次。

『连天衰草』（liantianshuaicao）＊
需80级寒星雨觞，若成功降低对手10%抵抗心神伤害能力，持续10秒。
每20秒使用一次，无论成败无自我忙乱。

『七星伴月』（qixingbanyue） 
成功后10秒内所有击中该敌人者都会得到一定的气血恢复（魔法类攻击除外）。
Ｉ：需要100级的寒星雨觞（+50气血）
ＩＩ：需要160级的寒星雨觞，需卷轴上卷（+70气血）
ＩＩＩ：需要180级的寒星雨觞，需卷轴下卷（+90气血）
每20秒使用一次，无论成败无自我忙乱。

『红藕香残』（hongouxiangcan）
需130级寒星雨觞，若成功对手停止三回合普通攻击
每20秒使用一次，无论成败无自我忙乱。

＊以上三个特技公用同一个20秒时限。

『风漏飞烟』（fengloufeiyan）
需150级寒星雨觞，在一瞬之间掷出六柄飞刀，有虚有实，利用敌人的错误判
断而趁机击中对手，该特技在对方不处于忙乱状况时有更高的命中率，自我
忙乱2轮。每20秒钟使用一次。
若对方不在忙乱中，额外攻击力=有效暗器等级

『天河一线』（tianheyixian）
需要200级的寒星雨觞，将暗器聚成一线源源不断地掷出。
使用此招时每2回合击出一式，共4式，威力逐渐增大，
但是由于运用时自身也处于忙乱中，十分凶险。
自身精气神低于30%时将自动中断
每5分钟使用一次
额外攻击力=400/400/600/800
伤害力=400/600/800/1600
伤害取最大可能值，且随自身经验等级增长而逐渐增加
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
