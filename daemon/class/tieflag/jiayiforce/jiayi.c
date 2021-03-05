// jiayi.c
//written by kouga

#include <ansi.h>

int exert(object me, object target, int amount)
{       
	int skill,force;  
	skill = me->query_skill("jiayiforce",1);  
	if(skill < 140) return notify_fail("你的嫁衣神功太差了，不能为人作嫁！\n"); 
	if( !target || target == me)  return notify_fail("你要对谁使用嫁衣神功？\n" );
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法使用嫁衣神功！\n");
	if((int)me->query("max_force") < 400)
                return notify_fail("你的内力不够强。\n");
	if((int)me->query("max_force") <= (int)target->query("max_force"))	
		return notify_fail("你的内力还没有"+target->name()+"的强，不能为其作嫁！\n"); 
        message_vision(
                HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
                "过了不久，$n浑身泛起红光，$N却昏倒在地。\n" NOR,
                me, target );
	me->set_skill("jiayiforce",1);
	me->add("max_force",-400);
	me->set("force",0);
	target->add("max_force",200);
	me->unconcious();
        return 1;
}
