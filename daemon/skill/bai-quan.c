// bai-quan.c
#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","白家拳法");
	
	set("type","unarmed");
	set("effective_level",150);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","shenshui");
	set("difficulty",150);
	set("practice_limit",1);
 	set("parry_msg", 		({
	        "$n一招「瞒天过海」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
	        "$n右拳虚幌，左拳一招「暗渡陈仓」，逼得$N后退三步。\n",
	        "$n以守为攻，一招「反客为主」，猛击$N握$w的手腕。\n",
	        "$n一招「金蝉脱壳」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
							})
	);
	set("unarmed_parry_msg",({
	        "$n一招「瞒天过海」，逼得$N中途撤招。\n",
	        "$n脚走阴阳，一招「釜底抽薪」，攻$N之必救。\n",
	        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
	        "$n双拳齐出，使出一招「一箭双雕」，$N的攻势入泥牛入海，消失得无影无踪。\n",
							})
	);
					   
 	action = ({
			([	"action":		"$N使一招「古松挂月」，对准$n的$l「呼」地一拳",
				"dodge":		40,
				"parry":		40,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N扬起拳头，一招「傲雪冬梅」便往$n的$l招呼过去",
				"dodge":		30,
				"parry":		30,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N左手虚晃，右拳「孤崖听涛」往$n的$l击出",
				"dodge":		30,
				"parry":		30,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N步履一沉，左拳拉开，右拳使出「荒山虎吟」击向$n$l",
				"dodge":		30,
				"parry":		30,
				"damage_type":	"瘀伤"
			]),
	});
}


int valid_learn(object me)
{
	return notify_fail("白三空说：这套拳法太过粗浅，你不学也罢。\n");
	
	if( me->query_skill("nine-moon-spirit",1)<70)
		return notify_fail("白三空捻著胡子看了看你，说道：姹女神功练高一些再来找我罢（需70级）。\n");

	if (me->query_skill("nine-moon-claw",1) < 200 && me->query_skill("bai-quan",1) >= 198 )
		return notify_fail("白三空捻著胡子看了看你，说道：你先把九阴神抓练好，我再传你白家拳绝招。\n");
	
	return ::valid_learn(me);
}


void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("bai-quan", 1);
		if (me->query("class") == "shenshui") {
	    	if (s == 100 ) {
	    		tell_object(me,WHT"你悟出了白家拳的静心诀（jingxin）。\n"NOR);
	    		me->set("pfm/baiquan-jingxin",1); 
	    	} 
	    	
	    	if (s == 200) {
	    		tell_object(me,WHT"你点、戳、击、打、举手投足，这平凡的拳法竟是意味无穷。\n"
	    				"你的九阴神抓的功力百尺竿头，更上一步。\n"NOR);
	    		me->set("pfm/baiquan-9moon",1); 
	    	}
    	}
    	return;
}


int help(object me)
{
	write(@HELP   
修习白家拳需要70级的姹女神功，L198级以上需要L200级九阴神抓。
200级提高九阴白骨抓的系数至210

『静心决』（jingxin）
需100级白家拳，耗费心神调理内伤，每次耗费300点心神
回复数目为白家拳与清平内功等级之和。
HELP
    );
    return 1;
}
