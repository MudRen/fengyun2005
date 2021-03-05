#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","媚术");
	set("type","knowledge");
	set("effective_level",150);
	set("skill_class","shenshui");
	set("difficulty",150);
}


void skill_improved(object me) {
	string att = "per";
	string c_att = "魅力";
	int s = me->query_skill("charm", 1);
	
	if (s > 50 && s < 201 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "由於你勤练媚术，你越来越漂亮了。\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 200)
			tell_object(me,HIR"你的"+c_att+"已经不能再通过"+ name()+ "提高了。\n"NOR);
		
	}
}
