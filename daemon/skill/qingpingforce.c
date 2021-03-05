// qingpingforce.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","清平内功");
	set("type","force");
	set("usage/force",1);
	set("skill_class","shenshui");
	set("effective_level",100);
	set("difficulty",150);
}


int valid_learn(object me)
{
	if(me->query_skill("nine-moon-spirit",1)< 90)
		return notify_fail("白三空捻著胡子看了看你，说道：姹女神功练高一些再来找我罢（需90级）\n");

	return 1;
}


void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("qingpingforce", 1);
		if (me->query("class") == "shenshui") {
/*	    	if (s == 100) {
	    		tell_object(me,WHT"你只觉武学之道，处处相通，这清平内功的『乾坤挪移』，也可用于九阴心法中。\n"
	    				"你学会了九阴心法的『乾坤挪移』。\n"NOR);
	    		me->set("pfm/9moon-qiankun",1); 
	    	} */
	    	if (s == 150) {
	    		tell_object(me,WHT"你只觉武学之道，处处相通，这清平内功的吐纳之术，也可用于九阴心法中。\n"
	    				"你九阴心法的『凝寒诀』的功效加强了。\n"NOR);
//	    		me->set("pfm/qingpingforce-9moon",1); 
	    	} 
    	}
    	return;
}


int help(object me)
{
	write(@HELP   
修习清平内功需要90级的姹女神功

L100 将『静心诀』融入九阴心法

L150 增强九阴心法的『凝寒诀』的功效

HELP
    );
    return 1;
}
