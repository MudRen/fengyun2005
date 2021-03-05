// xiaodao.c edit by hippo 2009 sh site
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","孝道");
	set("skill_class","basic");
	set("difficulty",100);
	set("usage/literate",1);
	set("type","knowledge");
	set("effective_level",150);
}	

void skill_improved(object me) {
			int s;
			s = me->query_skill("xiaodao", 1);
		   	if (s == 50 || s == 100 || s == 150 || s == 200) 
	    		tell_object(me,WHT"由于勤学孝道，你的运气调息更顺畅了。\n"NOR);
			return;
}

int valid_learn(object me)
{

	if (me->query_skill("xiaodao",1) >= me->query_skill("theorem",1)*2)
		return notify_fail("你的无有之术火候不够。\n");

	return ::valid_learn(me);
}

int help(object me)
{
	write(@HELP   
需至少/2等级的无有之术，学成后可提高ｅｘｅｒｔ
ｊｉｎｇ　ｑｉ　ｓｈｅｎ的回复效率，在缇萦学得。
此技能为消极技能，无需Enable便能自动生效。
L0： 回复量为100%
L50：回复量为107%
L100：回复量为115%
L150：回复量为122%
L200：回复量为130%
注：另外还会提高某些特殊技能的杀伤威力。
HELP
);
    return 1;
}