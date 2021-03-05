// drift_sense.c

#include <ansi.h>

inherit SSERVER;
void move_team(object me,object target);

int conjure(object me, object target)
{
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才可以使用游识神通！\n");
	
	if((int) me->query_skill("essencemagic",1) < 170)
        return notify_fail("需要170级八识神通！\n");
	
	if (!me->query("scroll/essencemagic_team_drift"))
		return notify_fail("你需要寻找到专门的卷轴后才能悟出此特技。\n");
	
	if (environment(me)->query("no_fly"))
   		return notify_fail("此地无法使用游识神通。\n");
	
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用游识神通！\n");
    if( me->query("atman") < 300 )
        return notify_fail("至少需要300点的灵力！\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用游识神通！\n"); 	
	write("你要将队伍移动到哪一个人身边？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;
	object *team;
	int transported; 
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
// the following is the NEW FLY FLAG, all NPCs are non-driftable by default.	
		|| !ob->query("fly_target")
	) {
		write("你无法感受到这个人的灵力 ....\n");
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
	} else if( me->query("atman") < 300 ) {
		write("至少需要300点的灵力！\n");
		return;
	}

	me->add("atman", -300);
	
	message_vision( HIY "$N低头闭目，开始施展游识神通 ....\n" NOR, me);
	
	if(environment(ob)==environment(me)) {
		write("你已经在这里了！\n");
		return;
	}	
	message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
		+ "，几秒钟後，光芒和人一齐消失得无影无踪！\n\n" NOR, environment(me), ({ me }) );
	
	// -> team transport here
        transported = 1;
	if( pointerp(team = me->query_team()) ) {
		for (int i=0; i<sizeof(team); i++) {
			if (!team[i]) continue;
			if (team[i] == me) continue;
			if ( environment(team[i]) != environment(me)) continue;
			if ( !team[i] ||( !me->visible(team[i])) || team[i]->is_ghost()
			   || !team[i]->query("max_atman") || !team[i]->query("atman")
			   || environment(team[i])->query("no_fly")
			   || environment(team[i])->query("no_magic")
			   
			) {
				write("你无法感受到"+team[i]->name()+"的灵力 ....\n");
				continue;
			}
			if (team[i]->is_busy() ||team[i]->is_fighting()
				|| team[i]->query_temp("no_move")) {
				tell_object(team[i],"你受到"+me->name()+"的心灵感召，但是你现在正忙，无法回应。\n");
				tell_object(me, YEL"\n" + team[i]->name()+"似乎没有空闲来回应你的游识感应。\n"NOR);
				continue;
			}

			message_vision(HIY"忽然间一片耀眼光芒浮动在$N周围。。。\n\n"NOR,team[i]);	
		        //team[i]->move(environment(ob));
		        team[i]->start_busy(4);
			call_out("move_team",2, me,team[i]);	        
			transported++;
		}
	}
    TASK_D->flying_risk(me);
    me->move(environment(ob));
    me->start_busy(4);
	message( "vision", HIY "\n你的眼前耀眼的光芒浮动，光芒中现出"+ chinese_number(transported)+ "个人影！\n\n" NOR,
		environment(ob), ({ me }) );
}


void move_team(object me,object target){

	if (!me)	return;	// 没人施法了。	
	if (!target) return; 	// 怎么会呢，除非操作错误, busied 	
	message_vision(HIY"$N受到"+me->name()+"的心灵感召，顿时如虚空凌度，已到了另外一个地方。\n"NOR,target);	
	tell_object(me, target->name()+"已应你感召，游识而来。\n");    	
	TASK_D->flying_risk(target);
	target->move(environment(me));
}




