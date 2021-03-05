inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","药道");
	set("type","knowledge");
	set("skill_class","basic");
	set("difficulty",200);
	set("effective_level",50);
	set("no_refund",({"dream-herb"}));
}


/*
void skill_improved(object me)
{
        int s;
        s = me->query_skill("herb", 1);
	if (s>100) 
        if( s%10==9 && (s-99)/10>me->query("marks/resistance")) {
                tell_object(me, WHT"由於你修炼药道有成，你对伤害的抵抗能力增强了。\n" NOR);
                me->add("resistance/kee", 1);
                me->add("resistance/sen", 1);
                me->add("resistance/gin", 1);
        	me->add("marks/resistance",1);
        }
        if (me->query("class")=="knight") {
	        if (s==289 && !me->query("marks/resist189")){
	                me->add("resistance/kee", 5);
	                me->add("resistance/sen", 5);
	                me->add("resistance/gin", 5);
	        	me->add("marks/resist189",1);
	        }
	        if (s==299 && !me->query("marks/resist199")){
	                me->add("resistance/kee", 5);
	                me->add("resistance/sen", 5);
	                me->add("resistance/gin", 5);
	        	me->add("marks/resist199",1);
	        }        
        }
}
*/