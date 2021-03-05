// dormancy.c

#include <ansi.h>

inherit SKILL;

void setup() {
	set("name","息若纳气");
	set("skill_class","legend");
	set("type","knowledge");
	set("effective_level",150);
	set("difficulty",120);
}


int valid_learn(object me)
{
	if (me->query("class")!= "legend")
		return notify_fail("唯有铁雪弟子方能掌握息若纳气之法。\n");
	return ::valid_learn(me);
}

/*
void skill_improved(object me)
{
	int s;
	s = me->query_skill("dormancy", 1);
          
        if (s > 100 && s < 301 && !(s%10)) {
		if ( (s-100)*5 < me->query("marks/dormancy")) {
			tell_object(me, HIW "由於你勤修息若纳气，你的气血提高了。\n" NOR);
			me ->set("Add_kee/dormancy", (s-100)*5);
			me ->add("max_kee",50);
			me ->add("marks/dormancy",50);
		}
		if (s == 300)
			tell_object(me,HIR"你的气血已经不能通过息若纳气来提高了。\n"NOR);
		
	}
        
}*/

int help(object me)
{
	write(@HELP   
息若纳气是铁雪多项武功的基础，决定了铁雪舞叶身法中增加气血的数量。
HELP
    );
    return 1;
}
