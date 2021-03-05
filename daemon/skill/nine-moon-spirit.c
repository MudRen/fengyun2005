// begging.c

inherit SKILL;

void setup() {
	set("name","姹女神功");
	set("effective_level",200);
	set("type","knowledge");
	set("skill_class","shenshui");
	set("no_refund", ({"nine-moon-sword","nine-moon-claw" }));
	set("difficulty",200);
	set("no_refund",({"qingpingforce","qingpingsword","chaos-steps"}));
}


int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	if((string)me->query("class") != "shenshui" ) 
		return notify_fail("姹女神功是神水宫弟子独有的武功。\n");
	return 1;
}


int help(object me)
{
	write(@HELP   
『迷魂术』（exert mihunshu）
此式需50级姹女神功方能使用，令敌人迷乱一轮并损伤其气血心神，
伤害力与姹女神功等级相关，成功率极高，无论成败都没有自我忙乱，
每14秒使用一次，每次耗费100点内力。
HELP
    );
    return 1;
}
