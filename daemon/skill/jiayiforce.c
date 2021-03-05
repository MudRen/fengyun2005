// Silencer @ FY4 workgroup. Aug.2004
// + 300 force, 50 50 50 50 50 50. --> L150-200, 每加一次则reset到0

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","嫁衣神功");
	set("type","force");
	set("usage/force",1);
	set("skill_class","tieflag");
	set("effective_level",120);
	set("difficulty",200);
}


/*
void skill_improved(object me)
{
    	int s;

    	s = me->query_skill("jiayiforce", 1);
    	if(!(s%50) && (me->query_skill("force",1)/6 < me->query_skill("jiayiforce",1))){
        tell_object(me,HIR "\n你体内真气振荡，一股气流走入叉道，啊！！....\n\n" NOR); 
        me->set_skill("jiayiforce",s/2);
        me->unconcious();		
    }

}*/
