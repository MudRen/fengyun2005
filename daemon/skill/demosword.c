// Can't Parry.
// 普通百姓专用 *cat
// 吃pots
// coeff = 180，200级 360 enable 超过ittouryu 150*2=300 enable。
// book 九思剑谱，study 0 - 50, learn 100 - 150, research 150 - 200.
// perform 诛天剑阵 惟普通百姓可用，效果与xiaodao挂钩。
// 　　　　　　　　　破iron-cloth，不被PB/DB/OHB,1-4hit busy 2-3。

inherit SKILL;
void setup() {
	set("name","九邪剑法");
	set("effective_level",180);
	set("type","sword");
	set("difficulty",300);
	set("usage/sword",1);
	set("skill_class","npc");
	action = ({
        ([      "action":               
"$N手中$w斜斜一划，一式「一剑苍茫」带起一片光华刺向$n",
                "damage":               70,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N悄然低眉，手中$w一转，施出「双目无光」抖出两点剑花刺向$n",
                "dodge":                -140,
                "damage":               140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一振手中$w，三点飞华袭向$n，正是九邪剑中的「三生缘定」",
                "parry":                -210,
                "damage":               210,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一按，圈出一缕寒光铺天盖地而来，这一式乃是九邪剑着「四海为家」",
                "dodge":                280,
                "parry":                -280,
                "damage":               280,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一式「五谷不食」，反手一剑，顺手一剑，似已乱了分寸，却自有神奥其中",
                "dodge":                -350,
                "parry":                350,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N一卷$w，倒持剑刃，满面悲戚，一式「六年魂断」笔直撞向$n",
                "dodge":                -420,
                "parry":                -420,
                "damage":               420,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N长叹一声，使出杀着「七窍风霜」，手中$w一点，已经隐去了剑光，只见一把凡\n铁般黯淡无华的$w平平刺向$n",
                "dodge":                490,
                "parry":                490,
                "damage":               490,
                "damage_type":  "刺伤"
        ]),
});

}

int effective_level(object me)
{
	
	if (me && userp(me))
	{
		if (!me->query("class"))
			return 180;
	}
	return 80;
}

int skill_difficulty() {
	
	object me = this_player();
	if (me && userp(me)) {
	if (!me->query("class"))
		return 300;
	}
	return 700;	
}

/*
int valid_learn(object me)
{
	if( me->query("class") ){
		return notify_fail("你门户之见已深，无法学习九邪剑法。\n");
	}
 	return ::valid_learn(me);
}
*/

mapping query_action(object me, object weapon)
{
	int i,level;
	level   = me->query_skill("demosword",1);
	if(level < 29) level = 29;
	for(i = sizeof(action); i > 0; i--)
		if(level >= i * 29)
			return action[random(i)];	// to get the 7th'hit,research 200->203.
}

int help(object me)
{
	write(@HELP   
『诛天剑阵』（zhutianjianzhen）
需要170级九邪剑法，150级孝道，
即便那些仅存的故典如凤毛麟角一般稀有，要在其中寻出与此相关式的
记载依然若大海捞针般困难。曾有好事者将七零八落的碎乱残章拼凑而起，
指出在上古时代罗堠三凶师便是以这一式联手诛灭黄帝身边的大将风后，将
其打落六道轮回。然而这简简单单的一句话，便是后人对「诛天剑阵」所有
的认知，其他一切的一切，似是都将永远湮没在历史的迷雾之中。

1-4连击，自我忙乱2-3回合。
无视硬功，伤害力与孝道等级相关。

注：普通百姓系数为180 否则为80
普通百姓学习难度为300 否则为700
非普通百姓时使用，自我忙乱增加二回合。

HELP
    );
    return 1;
}


/*Edit By Hippo 2009.11*/
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

