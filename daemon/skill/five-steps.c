// five-steps.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","五行身法");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","wudang");
	set("dodge_msg", ({
	        "但是$n身形有如流水，一式『水字诀』中抽刀断水，举重若轻的避开这一击。\n",
	        "$n身随意转，脚踩五行，一式『木字诀』，倏地从木门挪开了三尺，避过了这一招。\n",
	        "可是$n侧身一让，使出五行身法中的『金字诀』，$N这一招扑了个空。\n",
	        "却见$n足不点地，幻出五个身影，从火门往旁窜开数尺，躲了开去。\n",
	        "$n身形微晃，使出五行『土字诀』，土遁到了$N的身后。\n",
	}) );
}

int valid_learn(object me)
{
	if((int)me->query_skill("changelaw", 1) < (int)(me->query_skill("five-steps", 1)/2)) {
		return notify_fail("你对易经的了解还不够高深，无法学习五行身法。\n");
	}
	return 1;
}


int practice_skill(object me)
{
	string msg;
		
	msg = MAG"你身形展开，试图将"HIY" 金 "HIG"木 "HIC" 水 "HIR" 火 "NOR YEL" 土 "MAG"五行步法变幻融入古阵法『八阵图』中。\n" NOR;
	tell_object(me,msg);
	return :: practice_skill(me);	
}


//	沾衣十八跌

mapping ob_hit(object ob, object me, int damage) {
	mapping data;
	int skill;
		
	skill = me->query_skill("five-steps",1);
		
	if (me->query_temp("pfm/five-steps_zhanyi")|| 
		(	skill >= 200 
			&& me->query("class")=="wudang"
			&& me->query_skill_mapped("iron-cloth")== "incarnation")
			&& me->query_skill("incarnation",1)>= 300
			&& !random(10)) {
		ob->perform_busy(1);
		data = ([
			"msg":	WHT"$N刚一触及$n，身躯竟平平的横飞出去，蓬的一声，重重实实的摔在两丈之外。\n"NOR,
			"damage": -damage,
		]);
		return data;
	}
	return 0;
}


