// qingpingsword.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","清平剑法");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","shenshui");
	set("effective_level",175);
	set("practice_limit",1);
	set("difficulty",150);

	set("parry_msg", ({
	        "$n使出一招「凤舞九天」，手中的$v化作一条长虹，磕开了$N的$w。\n",
	        "$n使出「封」字诀，将$N的$w封于丈外。\n",
	        "$n使出一招「朝朝瑞雪」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
	        "$n手中的$v一抖，一招「旱地春雷」，向$N拿$w的手腕削去。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
	        "$n反手一招「阳光普照」，整个人消失在一团剑光之中。\n",
	        "$n使出一招「龙舞九天」，$v直刺$N的双手。\n",
	        "$n将手中的$v化做七条剑气，迫得$N连连后退。\n",
	}) );
	action = ({
        ([      "action":               
"$N使一招「峰回路转」，手中$w如一条银蛇般刺向$n的$l",
                "dodge":                20,
                "damage":               80,
                "force":                200,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出清平剑法中的「空山鸟语」，剑光霍霍斩向$n的$l",
                "dodge":                20,
                "damage":               120,
                "force":                100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「御风而行」，身形陡然滑出数尺，手中$w斩向$n的$l",
                "dodge":                30,
                "damage":               80,
                "force":                100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「旭日东升」对准$n的$l刺出一剑",
                "dodge":                40,
                "damage":               70,
                "force":                60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「金光泻地」对准$n的$l斜斜刺出一剑",
                "dodge":                40,
                "damage":               100,
                "force":                60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「童子引路」刺向$n的$l",
                "dodge":                20,
                "damage":               150,
                "force":                120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「柳暗花明」反手对准$n$l一剑刺去",
                "dodge":                20,
                "damage":               110,
                "force":                180,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「空谷秋虹」画出一道光弧斩向$n的$l",
                "dodge":                30,
                "damage":               80,
                "force":                110,
                "damage_type":  "割伤"
        ]),
	});
}


int valid_learn(object me)
{
	if(me->query_skill("nine-moon-spirit",1)<115)
		return notify_fail("白三空捻著胡子看了看你，说道：姹女神功练高一些再来找我罢（需115级）\n");

	return ::valid_learn(me);
}

void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("qingpingsword", 1);
		if (me->query("class") == "shenshui") {
	    	if (s > 100  && s<= 200 && s%10 ==0 ) {
	    		tell_object(me,WHT"你信手舞去，刺、磕、削、劈。。。。只觉武学之道，一路通，百路通。\n"
	    				  "这清平剑法之飘逸，与九阴剑法之阴柔正是一路。\n"
	    				  "你的九阴剑法提高了一个级别。\n"NOR);
	    		if (s == 200)
	    			tell_object(me,WHT"你已经彻底将清平剑法与九阴剑法融会贯通了！\n"NOR);
	    		me->set("pfm/qingpingsword-9moon",(s-100)); 
	    	} 
	    	
/*	    	if (s == 100) {
	    		tell_object(me,WHT"你只觉武学之道，处处相通，这清平剑法的『封字诀』，亦可用于九阴剑法中。\n"
	    				"你学会了九阴剑法的『雁渡寒潭』。\n"NOR);
	    		me->set("pfm/9moon-yanduhantan",1); 
	    	}	    	if (s == 140) {
	    		tell_object(me,WHT"你忽觉灵窍突开，这清平剑法的『封字诀』，正可补入『霜冷残霞』的破绽之中。\n"
	    				"你学会了九阴剑法的『意染苍云』。\n"NOR);
	    		me->set("pfm/9moon-yirancangyun",1); 
	    	}*/
    	}
    	return;
}

int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill = me ->query_skill("qingpingsword",1);
		if (skill < 150)
			return 150;
		else
			return 200;
	}
	return 200;
}


int help(object me)
{
	write(@HELP   	
清平剑法可从白三空处学得，条件为115级姹女神功
L100-L150可逐步（每十级）将九阴剑法的系数从100提高到150
L155-L200可逐步（每十级）将九阴剑法的系数从150提高到175
（L150以上学习系数升高为200）
HELP
    );
    return 1;
}
