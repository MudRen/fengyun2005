// taiji.c by Silencer@fy4 workgroup

#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","太极拳");
	set("type","unarmed");
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",200);
	set("damage_level",200);
	set("difficulty",200);
	
	set("skill_class","wudang");
	set("parry_msg", ({
	    "$n一招『提手上势』，圆弧形击$N的面门，逼得$N中途撤回手中的$w。\n",
	    "$n脚走太极，一招『搂膝勾步』，逼得$N后退三步。\n",
	    "$n以守为攻，一招『进步搬拦锤』，猛击$N握$w的手腕。\n",
	    "$n一招『如封似闭』，双掌不断圆转，引得$N不由自主地转了一圈。\n",
	}) );

	set("unarmed_parry_msg", ({
	    "$n一招『十字手』，逼得$N中途撤招。\n",
	    "$n脚走阴阳、以静制动，一招『抱虎归山』，把$N带出好远。\n",
	    "$n左掌阴、右掌阳，使出太极拳的『起手式』，轻而易举地将$N封于尺外。\n",
	    "$n双掌齐出，使出太极拳最后一式『单鞭和太极』，$N的攻势如泥牛入海，消失得无影无踪。\n",
	}) );	
	action = ({
	    ([ "action":
	    		"$N双手圆转，使出一招『揽凤尾』，对准$n的$l击出",
	     	"dodge":30,
	     	"parry":150,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([ "action":
	    		"$N左掌虚晃，右掌画了一个圆弧，一招『单鞭』便往$n的$l招呼过去",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([	"action":	
	    		"$N一招『白鹤亮翅』，双掌成圆弧形提起，圆转着向$n的$l击出",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([ 	"action":
	    		"$N左掌阳、右掌阴，使出一招『手挥琵琶』，双掌慢慢向$n的$l合拢",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([  "action":
	    		"$N左手由胸向下，右臂微曲，一招『抱虎归山』，向$n的$l推去",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([ 	"action":
	    		"$N双手经下腹划弧交于胸前，成十字状，一式『十字手』向$n的$l打去",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([ 	"action":
	    		"$N左脚踏一个虚步，双手交叉成十字拳，一招『进步七星』，向$n的$l锤去",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([ 	"action":
	    		"$N身体向后腾出，使一招『倒撵猴』，向$n的$l和面门打去",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	    ([ 	"action":
	    		"$N双手握拳，右手缓缓收至耳际，左手缓缓向前推出，一招『弯弓射虎』直奔$n心窝而去",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"瘀伤"
		]),
	});
}


int valid_learn(object me)
{
    	object ob;
    	if( (int)me->query_skill("changelaw",1) < (int)(me->query_skill("taiji",1))){
        	return notify_fail("学习太极拳需要相同等级的易经作基础。\n");
		}
	return ::valid_learn(me);
}


//	四两拨千斤

mapping ob_hit(object ob, object me, int damage) {
	
	string msg;
	int myexp, yourexp, skill, bonus;
	object weapon;
	mapping data = ([]);
	
	skill = me->query_skill("taiji",1);
	bonus = (me->query_skill("incarnation",1) -300)/10;
	if (bonus > 5 ) bonus = 5;
	else if (bonus <0 ) bonus =0;
	
	if (userp(me)) {	// For Players
		if (!me->query_temp("pfm/taiji_siliang") && 
				(skill < 180	
				||	me->query("class")!="wudang"
				|| me->query_skill_mapped("iron-cloth")!= "incarnation"
				|| me->query_skill("incarnation",1) <= 250
				|| random(20)< 15 - bonus ))
			return 0;
	} else {			// For NPCs
		if (!me->query_temp("pfm/taiji_siliang") && 
				(skill < 100	
				|| me->query("class")!="wudang"
				|| me->query_skill_mapped("iron-cloth")!= "incarnation"
				|| me->query_skill("incarnation",1) <= 250
				|| random(20)< 15 - bonus ))
			return 0;
	}

	switch (random(6))	{			
		case 0:		msg = HIY"$n双手摆一招『野马分鬃』，左圈右围，将$N的劲力悉数卸去！\n"NOR,
				damage = - damage;
				break;
		case 1:
		case 2:		msg = CYN"$n左掌阳、右掌阴，双掌慢慢合拢，将$N的劲道消去了一大半。\n"NOR;
				damage = - damage*3/4;
				break;
		default:		if (weapon = ob->query_temp("weapon"))
					msg = YEL"$n左划右转，一招『转身摆莲』拍在"+ weapon->name()+YEL"上，将$N的力道卸掉一半!\n"NOR;
				else
					msg = YEL"$n左划右转，一招『转身摆莲』，将$N的力道卸掉一半!\n"NOR;
				damage = - damage/2;
	}
	if (msg && stringp(msg)) {
		data["damage"] = damage;
		data["msg"] = msg;
		return data;	
	} else
		return 0;
}
