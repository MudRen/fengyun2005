// drift_sense.c

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才可以使用游识神通！\n");
	
    if((int) me->query_skill("essencemagic",1) < 90)
                return notify_fail("游识神通需要90级八识神通！\n");
	
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用游识神通！\n");
    
   	if (environment(me)->query("no_fly"))
   		return notify_fail("此地无法使用游识神通。\n");
    
    if( me->query("atman") < 100 )
        return notify_fail("你的灵力不够！\n");

	if( me->is_ghost())
		return notify_fail("鬼魂无法使用游识神通！\n"); 	
	if( target )
		return notify_fail("游识神通只能对自己使用！\n");
	write("你要移动到哪一个人身边？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("中止施法。\n");
		return;
	}

	ob = find_real_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)
// the following check start/arrival room.	
		|| environment(ob)->query("no_death_penalty")
		|| environment(ob)->query("no_fly")
		|| environment(ob)->query("no_fly_in")
		|| environment(ob)->query("no_magic") 
		|| environment(me)->query("no_fly")
// all NPCs are non-driftable by default.	
		|| !ob->query("fly_target")
	) {
		write("你无法感受到这个人的灵力……\n");
		write("你要移动到哪一个人身边？");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	
	if (stringp(me->query_temp("no_move"))) {
       	tell_object(me, me->query_temp("no_move"));
       	return;
    }
        	
	if( me->is_fighting() ) {
		write("战斗中无法使用游识神通！\n");
		return;
	} else if( me->query("atman") < 100) {
		write("游识神通需要100点灵力！\n");
		return;
	}

	if(environment(ob)==environment(me)) {
		write("你已经在这里了！\n");
		return;
	}	
	me->add("atman", -100);
	message_vision( HIY "$N低头闭目，开始施展游识神通 ....\n" NOR, me);
	
	message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
		+ "，几秒钟後，光芒和人一齐消失得无影无踪！\n\n" NOR, environment(me), ({ me }) );
	TASK_D->flying_risk(me);
	me->move(environment(ob));
	message( "vision", HIY "\n你的眼前突然出现一团耀眼的光芒，光芒中浮现出一个人影！\n\n" NOR,
		environment(ob), ({ me }) );
	
	
	return;
}
