// Silencer @ FY4 workgroup. Aug.2004
//	山河同寿，每一招都是反击，放弃dodge
// 意思说人死之后，精神不朽，当可万古长春，实是杀身成仁、舍生取义的悲壮招数。
//	Can't stop ppl unwield all .....
//	Can make it so he won't dodge, only parry counter... thinking.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        mapping buff;
        
	extra = me->query_skill("yue-strike", 1);
        if ( extra < 150) 
        	return notify_fail("『山河同寿』需要160级的小重山掌！\n");
        
        msg = HIY  "$N仰天长叹，使出了小重山掌的『山河同寿』，一股浩然正气直冲霄汉！\n" NOR;
        
        buff =
		([
			"caster": me,
			"who":   me,
			"type": "riposte",
			"att":	"bless",
			"name":	"小重山掌·山河同寿",
			"buff1":"pfm/yue-strike/shts",
			"buff1_c":1,
			"time":  60 ,
			"buff_msg": msg,
		]);          
        
        ANNIE_D->buffup(buff);
                
        return 1;
}
