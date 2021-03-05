// move.c

#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","基本轻功");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("eff_learn_level", 150);
	set("no_refund","attr");
}

void skill_improved(object me)
{
	string att = "agi";
	string c_att = "速度";
	int s = me->query_skill("move", 1);
	
	if (s > 50 && s < 221 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "由於你勤练轻功，你的敏捷度提高了。。\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 220)
			tell_object(me,HIR"你的"+c_att+"已经不能再通过"+ name()+ "提高了。\n"NOR);
		
	}
	
}
