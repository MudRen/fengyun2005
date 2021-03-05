#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)

{
	object wolf;
	int summonwolf, exp;
	int guard;
        
        if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
        if ((string)me->query("class") != "wolfmount")
		return notify_fail("只有狼山弟子才可以驱狼助阵。\n");
        if( !me->is_fighting() )
        	return notify_fail("好象没有人要杀你！\n");
	
	guard= 2;

	if( me->query_temp("max_guard") > guard )
    	return notify_fail("好象附近已经没有狼了。\n");

	summonwolf = (int)me->query_skill("summonwolf",1);
	seteuid(getuid());
	wolf= new("/obj/npc/wolf");
	wolf->move(environment(me));
        wolf->invocation(me, (summonwolf));
        wolf->set("possessed", me);

	if (summonwolf<50)
		wolf->set_name("杂毛恶狼",({ "wolf" }));
	else if (summonwolf<75)
		wolf->set_name(WHT"灰毛恶狼"NOR,({ "wolf" }));
	else if (summonwolf<100)
    		wolf->set_name(YEL"黄毛恶狼"NOR,({ "wolf" }));
	else if (summonwolf<125)
        	wolf->set_name(RED"红毛恶狼"NOR,({ "wolf" }));
	else if (summonwolf<150)
		wolf->set_name(HIW"白毛恶狼"NOR,({ "wolf" }));
        else if (summonwolf<175)
     		wolf->set_name(HIR"赤毛恶狼"NOR,({ "wolf" }));
	else 
		wolf->set_name(HIY"金毛狼王"NOR,({ "wolf" }));

    me->add_temp("max_guard",1);

	message_vision(HIB "\n$N仰天狼嚎“呜～嗷～～，呜～嗷”，顿时漫山遍野群狼齐哮。\n" NOR, me);	
    message_vision( "\n\n$N恶狠狠地扑了上来。\n" , wolf);
	return 1;
}

